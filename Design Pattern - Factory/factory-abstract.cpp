#include <iostream>
#include <cstring>
#include <vector>
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
    virtual HotDrink* make() const = 0;
};

struct TeaFactory: HotDrinkFactory {
    HotDrink* make() const override {
        return new Tea();
    }
};

struct CoffeeFactory: HotDrinkFactory {
    HotDrink* make() const override {
        return new Coffee();
    }
};

struct StructFactories {
    public:
        string drink_type;
        HotDrinkFactory* drink_factory;
        StructFactories(string d, HotDrinkFactory* h): drink_type(d), drink_factory(h) {};
};

class DrinkFactory {
    vector<StructFactories> factories;
    public:
        DrinkFactory() {
            factories.push_back(StructFactories("coffee", new CoffeeFactory()));
            factories.push_back(StructFactories("tea", new TeaFactory()));
        }
        HotDrink* make_drink(const string& name) {
            for (auto factory: factories) {
                if (factory.drink_type == name) {
                    HotDrink* rv = factory.drink_factory->make();
                    rv->Prepare(200);
                    return rv;
                }
            }
            return nullptr;
        }
};

int main() {

    DrinkFactory df;
    auto d = df.make_drink("tea");
    return 0;
}