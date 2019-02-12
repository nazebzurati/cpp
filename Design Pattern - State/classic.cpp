#include <iostream>
using namespace std;

class Machine;

struct State {
    public:
        virtual void runTransition(Machine *machine) { cout << "Machine already running." << endl; };
        virtual void finishTransition(Machine *machine) { cout << "Machine already finished." << endl; };
};

struct StateIdle: State {
    public:
        StateIdle() { cout << "Machine is in idle state." << endl; };
        void runTransition(Machine* machine) override;
};

struct StateRunning: State {
    public:
        StateRunning() { cout << "Machine is in running state." << endl; };
        void finishTransition(Machine* machine) override;
};

class Machine {
    private:
        State *state;
    public:
        Machine(): state(new StateIdle()) { };
        void transitionTo(State* state) {
            this->state = state;
        }
        void run() {
            state->runTransition(this);
        }
        void finish()
        {
            state->finishTransition(this);
        }
};

// this function need to be declare after machine has been declared
void StateIdle::runTransition(Machine* machine) {
    cout << "idle -> running" << endl;
    machine->transitionTo(new StateRunning());
    delete this; // delete current state to indicate current state already finish
};

// this function need to be declare after machine has been declared
void StateRunning::finishTransition(Machine* machine) {
    cout << "running -> idle" << endl;
    machine->transitionTo(new StateRunning());
    delete this; // delete current state to indicate current state already finish
};

int main() {

    Machine stateMachine;

    stateMachine.run();
    stateMachine.run();
    
    stateMachine.finish();
    stateMachine.finish();

    return 0;
}