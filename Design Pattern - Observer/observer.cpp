#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <mutex>
using namespace std;

template <typename T>
class Observer {
    public:
        virtual void changes (T& source, const string& field_name) = 0;
};

template <typename T>
class Observable {
    vector<Observer<T>*> observers;
    public:
        void notify(T& source, const string& field_name) {
            for (auto observer: observers) {
                observer->changes(source, field_name);
            }
        }
        void subscribe(Observer<T>& observer) {
            observers.push_back(&observer);
        }
        void unsubscribe(Observer<T>& observer) {
            observers.erase(remove(observers.begin(), observers.end(), &observer), observers.end());
        }
};

class Person: public Observable<Person> {
    private:
        string name;
        int age = 0;

    public:
        Person(string name): name(name) {};
        int getAge() {
            return age;
        }
        void setAge(int age) {
            if (this->age == age) return;
            bool oldVotable = checkVotable();
            this->age = age;
            notify(*this, "age");
            if (!oldVotable && checkVotable())
                notify(*this, "vote");
        }
        bool checkVotable() {
            return this->age >= 18;
        }
        string getName() {
            return this->name;
        }
};

class ConsoleObserver: public Observer<Person> {
    public:
        void changes(Person& person, const string& field_name) override {
            if (field_name == "age")
                cout << person.getName() << "'s age changed to " << person.getAge() << endl;
            else if (field_name == "vote")
                cout << person.getName() << " can now vote." << endl;
        }
};

class UniversityAdmin: public Observer<Person> {
    // national service only take civilian that age 17 and above
    public:
        void changes(Person& person, const string& field_name) override {
            if (field_name == "age") {
                if (person.getAge() >= 18) {
                    cout << person.getName() << "'s is applicable for university admission." << endl;
                }
                else {
                    cout << "Nope, unless you're a genius" << endl;
                    person.unsubscribe(*this);
                }
            }
        }
};

int main() {

    Person personA("Nazeb");
    Person personB("Syamsul");
    Person personC("Azeem");

    ConsoleObserver co;
    UniversityAdmin ua;

    personA.subscribe(co);
    personB.subscribe(co);
    personA.subscribe(ua);
    personB.subscribe(ua);
    personC.subscribe(ua);

    personA.setAge(15);
    personB.setAge(16);
    personC.setAge(20);

    personB.unsubscribe(co);

    personA.setAge(25);
    personB.setAge(25);

    return 0;
}