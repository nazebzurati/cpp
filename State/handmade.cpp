#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

enum class State {
    Idle,
    Running,
    Tidy,
    Exit
};

inline ostream& operator<<(ostream& os, const State& s) {
    switch (s) {
        case State::Idle:
            os << "Idle state";
            break;
        case State::Running:
            os << "Running state";
            break;
        case State::Tidy:
            os << "Tidying state";
            break;
        case State::Exit:
            os << "Exit";
            break;
    }
    return os;
}

enum class Trigger {
    run,
    finish,
    cancel
};

inline ostream& operator<<(ostream& os, const Trigger& t) {
    switch (t) {
        case Trigger::run:
            os << "run ..";
            break;
        case Trigger::finish:
            os << "finish ..";
            break;
        case Trigger::cancel:
            os << "cancel ..";
            break;
    }
    return os;
}

int main() {

    // create a map of rules
    map<State, vector<pair<Trigger, State>>> rules;
    rules[State::Idle] = {
        { Trigger::run, State::Running }
    };
    rules[State::Running] = {
        { Trigger::cancel, State::Idle },
        { Trigger::finish, State::Tidy }
    };
    rules[State::Tidy] = {
        { Trigger::finish, State::Exit }
    };

    // set state
    State currentState { State::Idle };
    State exitState { State::Exit };

    // main
    int optionTrigger;
    while (1) {
        system("clear");
        cout << "You current state: " << currentState << endl;

        int count = 0;
        for (auto item: rules[currentState]) {
            cout << count++ << ". " << item.first << endl;
        }

        cout << "Select your trigger: ";
        cin >> optionTrigger;
        if (optionTrigger < 0 || optionTrigger >= rules[currentState].size()) {
            continue;
        }
        else {
            currentState = rules[currentState][optionTrigger].second;
            if (currentState == exitState) break;
        }
    }
    cout << "State machine exit." << endl;

    return 0;
}

// compile: g++ -std=c++11 -g State/handmade.cpp -o exec.out