#include <iostream>
#include <cstring>

class Monostate {
    public:
        int& get() {
            static int value = 0;
            return value;
        }
};

class Normal {
    private:
        int value = 0;
    public:
        int& get() {
            // value cannot be local as it will have segmentation fault error (because it is trying to access a non-exist object from outside the scope)
            return value;
        }
};

int main() {

    Monostate m1;
    Monostate m2;

    if (&m1.get() == &m2.get()) {
        std::cout << "it's the same: " << &m1.get() << "==" << &m2.get() << std::endl;
    }

    Normal n1;
    Normal n2;

    if (&n1.get() != &n2.get()) {
        std::cout << "it's not the same: " << &n1.get() << "==" << &n2.get() << std::endl;
    }
    
    return 0;
}