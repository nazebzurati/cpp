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