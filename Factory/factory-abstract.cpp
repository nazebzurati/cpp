#include <iostream>
#include <cstring>
#include <memory>
#include <map>
using namespace std;

struct HotDrink {
    virtual ~HotDrink() = default;
    virtual void Prepare(int volume) = 0;
};

struct Tea: HotDrink {
    void Prepare(int volume) override {
        cout << volume << "ml is required to make a tea." << endl;
    }
};

struct Coffee: HotDrink {
    void Prepare(int volume) override {
        cout << volume << "ml is required to make a coffee." << endl;
    }
};

struct HotDrinkFactory {
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory: HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory: HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};

// implementation without factory
unique_ptr<HotDrink> make_drink(string type) {
    unique_ptr<HotDrink> drink;
    if (type == "tea") {
        drink = make_unique<Tea>();
        drink->Prepare(10);
    } else {
        drink = make_unique<Coffee>();
        drink->Prepare(100);
    }
    return drink;
}

class DrinkFactory {
    map<string, unique_ptr<HotDrinkFactory>> factories;
    public:
        DrinkFactory() {
            factories["coffee"] = make_unique<CoffeeFactory>();
            factories["tea"] = make_unique<TeaFactory>();
        }
        unique_ptr<HotDrink> make_drink(const string& name) {
            auto drink = factories[name]->make();
            drink->Prepare(200);
            return drink;
        }
};

int main() {

    DrinkFactory df;
    auto d = df.make_drink("tea");
    return 0;
}

// Factory is a method to deal with the problem of creating objects without having to specify the exact
// class of the object that will be created.
// --------------------------------------------------------------------------------------------------------
// For an example in this tutorial, Point class could not have two constructor that have the same 
// argument: Point(float x, float y) for cartesian and Point(float rho, float theta). However, we can use
// one constructor and define it based on its type (in this example, enum class were used). It's just a
// simple if else or switch case would be sufficient to know which operation to be executed.
// --------------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++14 -g Factory/factory-abstract.cpp -o exec.out