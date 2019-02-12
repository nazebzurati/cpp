#include <iostream>
#include <cstring>
using namespace std;

class Bird {
    protected:
        string name;
        bool beAbleToFlight;
    public:
        Bird(const string name, const bool beAbleToFlight): name(name), beAbleToFlight(beAbleToFlight) {};
        bool isAbleToFlight() { return beAbleToFlight; };
        string getName() { return name; };
        virtual ~Bird() {}; // this is require in order to use dynamic cast. Virtual destructor made the the class polymorphic
};

class Penguin: public Bird {
    public:
        Penguin(string name): Bird(name, false) {};
};

class Parrot: public Bird {
    public:
        Parrot(string name): Bird(name, true) {};
};

void checkOne(Bird* bird) {
    Penguin* peng = dynamic_cast<Penguin*>(bird); // this line is to get check whether bird is castable into penguin class. Dynamic class is a way where it safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy. 
    if (peng) {
        cout << bird->getName() << " can't fly" << endl;
    }
    else {
        cout << bird->getName() << " can fly" << endl;
    }
}

void checkTwo(Bird* bird) {
    if (!bird->isAbleToFlight()) {
        cout << bird->getName() << " can't fly" << endl;
    }
    else {
        cout << bird->getName() << " can fly" << endl;
    }
}

int main() {
    
    Penguin penguin("PengPeng");
    Parrot parrot("Coacatoa");

    //Solution 1: The wrong way to do it according to liskov
    checkOne(&penguin);
    checkOne(&parrot);

    //Solution 2: An OK way to do it according to liskov
    checkTwo(&penguin);
    checkTwo(&parrot);

    return 0;
}