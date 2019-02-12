#include <iostream>
#include <cstring>

class Singleton {
    private:
        Singleton() {
            // nop
        };
    public:
        // requirement for a singleton to be a singleton
        Singleton(Singleton const&) = delete; // prevent the singleton be created
        void operator = (Singleton const&) = delete; // prevent the singleton be copied by reference
    public:
        static Singleton& get() {
            static Singleton single;
            return single;
        }
        std::string get_time() {
            return "example";
        }
};

int main() {

    std::cout << Singleton::get().get_time() << std::endl;

    return 0;
}

// g++ -std=c++11 -g singleton.cpp -o exec.out