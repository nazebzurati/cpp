#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
    private:
        vector<int> combination;
        unsigned int count = 0;
    public:
        string status;
        CombinationLock(const vector<int> &combination) : combination(combination) { 
            status = "LOCKED";
        };
        void enter_digit(int digit)
        {
            if (count == 0) 
            { 
                status = "";
            }
            status += to_string(digit);
            string a = to_string(combination.at(count));
            if (count == combination.size() - 1) {
                if (status[count++] == a[0]) {
                    status = "OPEN";
                }
                else {
                    status = "ERROR";
                    count = 0;
                }
            }
            else {
                if (status[count++] != a[0]) {
                    status = "ERROR";
                    count = 0;
                }
            }
        }
};

int main() {
    CombinationLock c({1, 2, 3});
    cout << c.status << endl;
    c.enter_digit(1);
    cout << c.status << endl;
    c.enter_digit(2);
    cout << c.status << endl;
    c.enter_digit(5);
    cout << c.status << endl;
    c.enter_digit(3);
    cout << c.status << endl;
    c.enter_digit(1);
    cout << c.status << endl;
    c.enter_digit(2);
    cout << c.status << endl;
    c.enter_digit(3);
    cout << c.status << endl;
}