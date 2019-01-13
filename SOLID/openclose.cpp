#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

enum class Color { red, green, blue, yellow };
enum class Size { small, medium, large };

struct Product {
    string name;
    Color color;
    Size size;
};

template <typename T>
struct Specification {
    virtual bool isSatisfied(T* item) const = 0;
};

template <typename T>
struct vFilter { // v is for virtual Filter. the reason why Specification doesn't have v because Specification will only apply specifically (specificationByColor etc) while Filter is not
    virtual vector<T*> filter(vector<Product*> items, Specification<T>& spec) = 0;
};

template <typename T>
struct TwoSpecification: Specification<T> {
    const Specification<T>& first;
    const Specification<T>& second;
    TwoSpecification(const Specification<T>& first, const Specification<T>& second): first(first), second(second) {};
    bool isSatisfied (T* item) const override {
        return first.isSatisfied(item) && second.isSatisfied(item);
    }
};

// this is an operator overriding. It is not declared inside Specification virtual class as it will break Open Close Principle (OCP)
template <typename T> 
TwoSpecification<T> operator&& (const Specification<T>& first, const Specification<T>& second) {
    return { first, second };
}

struct Filter: vFilter<Product> {
    vector <Product*> filter (vector<Product*> items, Specification<Product> &spec) override {
        vector <Product*> result;
        for (auto& item: items) {
            if (spec.isSatisfied(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct SpecificationColor: Specification <Product> {
    Color color;
    explicit SpecificationColor(const Color color): color(color) {};
    bool isSatisfied(Product* item) const override {
        return item->color == color;
    }
};

struct SpecificationSize: Specification <Product> {
    Size size;
    explicit SpecificationSize(const Size size): size(size) {}; // why use explicit? It seems that it uses explicit for const object
    bool isSatisfied(Product* item) const override {
        return item->size == size;
    }
};

int main() {
    // creating products
    Product apple { "Apple", Color::red, Size::small };
    Product shirt { "Shirt", Color::blue, Size::medium };
    Product clock { "Clock", Color::yellow, Size::small };
    vector<Product*> items { &apple, &shirt, &clock };

    // Filter
    Filter f;
    SpecificationSize specBySize(Size::small);
    for (auto& item: f.filter(items, specBySize)) {
        cout << item->name << " is small" << endl;
    }

    // 
    SpecificationColor specByColor(Color::red);
    TwoSpecification<Product> ts(specBySize, specByColor);
    for (auto& item: f.filter(items, ts)) {
        cout << item->name << " is yellow and small" << endl;
    }

    // with operator overriding
    auto autoSpec = specByColor && specBySize;
    for (auto& item: f.filter(items, autoSpec)) {
        cout << item->name << " is yellow and small" << endl;
    }

    // return 
    return 0;
}

// Open Close Principle is a principle where it open for extension while its close for modifiction
// ------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g SOLID/openclose.cpp -o exec.out