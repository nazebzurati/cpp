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

// Liskov Principle is a principle where subtype should to be immediately subtitutable for their base type.
// --------------------------------------------------------------------------------------------------------
// In the other hand, Liskov says that the code should work without knowing the actual class. The tutorial 
// actually use rectangle-square problem (circle-eclipse problem) and it's hard to be understand as it only
// show the problem and not the solution. This approach is to reduce the posibilites that you need to refactor
// everthing in order to make up a slight changes in code or creating new element (in current case other bird
// type and you have to add the if statement for each available derived-bird class)
// --------------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g SOLID/liskov.cpp -o exec.out