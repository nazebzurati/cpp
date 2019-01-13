#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

struct Journal {
    string title;
    vector<string> entry;
    Journal(const string &title) : title(title) {};
    void EntryAdd(const string &newEntry) {
        cout << "New entry: " << newEntry << endl;
        entry.push_back(newEntry);
    }
};

struct PersistenceManager {
    static void Save(const Journal& j, const string& filename) {
        ofstream f(filename);
        f << j.title << endl;
        for (auto& i: j.entry) {
            f << i << endl;
        }
        cout << "Journal saved" << endl;
    }
};

int main () {
    // create a journal
    Journal j("Diary!");
    j.EntryAdd("Today I cried.");

    // persistence manager
    PersistenceManager pm;
    pm.Save(j, "jounal.txt");

    return 0;
}

// Single responsibility is a class should have single responsibilty.
// ----------------------------------------------------------------------------------
// In this use case, we are not recommended to have save the journal functionality
// inside the journal because journal class only have the resposibility to save and
// keep the journal added into it. Because of it, you might have the complication
// if there is changes in the class. The save and load function would not be relevent
// and you required to update all the class that have this same save and load function
// in it. 'Seperation of concern' is used to seperate this common operation from the
// class and maintain its persistence. Persistence is the continueance of an subject
// after a class not remain relevent.
// ----------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g SOLID/single_responsibility.cpp -o exec.out