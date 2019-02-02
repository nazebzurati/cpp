#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include <map>
#include <functional>
using namespace std;

struct HotDrink {
    ~HotDrink();
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

struct StructFactories {
    public:
        string drink_type;
        HotDrink* drink_factory;
        StructFactories(string d, HotDrink* h): drink_type(d), drink_factory(h) {};
};

class DrinkWithVolumeFactory {
    vector<StructFactories> factories;
    public:
        DrinkWithVolumeFactory() {
            factories.push_back(StructFactories("tea", new Tea()));
            factories.push_back(StructFactories("coffee", new Coffee()));
        }
        HotDrink* make_drink(const string& name) {
            for (auto factory: factories) {
                if (factory.drink_type == name) {
                    HotDrink *rv = factory.drink_factory;
                    rv->Prepare(200);
                    return rv;
                }
            }
            return nullptr;
        }
};

int main() {

    DrinkWithVolumeFactory dfv;
    auto d = dfv.make_drink("tea");
    return 0;
}

// Factory is a method to deal with the problem of creating objects without having to specify the exact
// class of the object that will be created.
// --------------------------------------------------------------------------------------------------------
// It quite similar to Abstract Factory but Functional Factory does not require interface.
// --------------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g Factory/factory-functional.cpp -o exec.out