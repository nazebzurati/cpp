#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
using namespace std;

enum class Relation {
    parent,
    child
};

struct Person {
    string name;
    Person(const string name): name(name) {};
};

struct InterfaceFind { // dependency injector or mediator
    virtual vector<Person> findChildren(const string& parentName) = 0;
};

struct Relationship: InterfaceFind { // low-level module
    vector<tuple<Person, Person, Relation>> relations;
    void addParentChild(Person& parent, Person& child) {
        Relationship::relations.push_back(make_tuple(parent, child, Relation::parent));
        Relationship::relations.push_back(make_tuple(child, parent, Relation::child));
    }
    vector<Person> findChildren(const string& parentName) override {
        vector<Person> result;
        for (auto relation : relations) {
            if (get<0>(relation).name == parentName && get<2>(relation) == Relation::parent) { // tuple implementation here quite messy. In c++17, the usage is more neat by using auto datatype and square bracket
                result.push_back(get<1>(relation));
            }
        }
        return result;
    }
};

struct ResearchAbuChild { // high-level module
    ResearchAbuChild(Relationship& relationship) {
        for (auto child: relationship.findChildren("Abu")) {
            cout << "Abu has child named " << child.name << endl;
        }
    };
};

int main() {

    Person father("Abu");
    Person sister("Aminah");
    Person brother("Bakar");

    Relationship relationship;
    relationship.addParentChild(father, sister);
    relationship.addParentChild(father, brother);

    ResearchAbuChild researchAbuChild(relationship);

    return 0;
}