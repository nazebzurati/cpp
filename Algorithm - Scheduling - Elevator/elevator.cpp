#include <iostream>     // cout, endl
#include <vector>       // vector
#include <algorithm>    // sort
#include <iomanip>      // setfill, setw

// constant
const int number_of_request = 5;
const int floor_min = 1;
const int floor_max = 5;

// passenger information
class Passenger {

    public:
        std::string name;
        int floor_current = floor_min;
        int floor_destination = floor_max;

    public:
        Passenger(std::string name, int floor_current, int floor_destination): 
            name(name), floor_current(floor_current), floor_destination(floor_destination) {};

};

// sort passenger based on elevator direction and passenger destination
bool sort_ascending(Passenger a, Passenger b) {
    return a.floor_destination < b.floor_destination;
}
bool sort_descending(Passenger a, Passenger b) {
    return a.floor_destination > b.floor_destination;
}

// elevator operation
class Elevator {

    private:
        bool move_upward = true;
        int floor_current = floor_min;
        std::vector<Passenger> passenger_waiting, passenger_in_elevator;

    private:
        // display the elevator status
        void status(std::string message) {
            std::cout << "Elevator [Current floor: " << std::setw(3) << std::setfill('0') << floor_current << ", Passenger count: " << std::setw(3) << std::setfill('0') << passenger_in_elevator.size() << "]";
            if (!message.empty()) {
                std::cout << " : " << message;
            }
            std::cout << std::endl;
        }
        // move the elevator
        void move(int floor_destination) {
            // keep moving until it arrive at its destination floor
            while (floor_current != floor_destination) {
                // go to next floor
                if (floor_destination < floor_current) {
                    status("Moving downward");
                    --floor_current;
                }
                else {
                    status("Moving upward");
                    ++floor_current;
                }
            }
        }
        // pick passenger
        void pick_passenger() {

            // check for nearest passenger
            int floor_destination = floor_min;
            int shortest_distance = abs(floor_max - floor_min) + 1;
            for (Passenger passenger: passenger_waiting) {
                int distance = abs(floor_current - passenger.floor_current);
                if (distance < shortest_distance) {
                    shortest_distance = distance;
                    floor_destination = passenger.floor_current;
                }
            }
            move(floor_destination);

            // pick passenger
            std::vector<int> passenger_waiting_to_be_deleted_index;
            for (size_t i = 0; i < passenger_waiting.size(); i++) {

                // pick all passenger in same floor
                if (floor_current == passenger_waiting.at(i).floor_current) {

                    // first passenger sets the direction
                    if (passenger_in_elevator.size() == 0) {
                        if (passenger_waiting.at(i).floor_destination < floor_current) {
                            move_upward = false;
                        }
                        else {
                            move_upward = true;
                        }
                    }

                    // add next passenger
                    if ((move_upward && passenger_waiting.at(i).floor_destination > floor_current) || (!move_upward && passenger_waiting.at(i).floor_destination < floor_current)) {
                        status(passenger_waiting.at(i).name + " picked, going to " + std::to_string(passenger_waiting.at(i).floor_destination));
                        passenger_in_elevator.push_back(passenger_waiting.at(i));
                        passenger_waiting_to_be_deleted_index.push_back(i);
                    }
                }
            }

            // delete passenger that already in elevator from passenger waiting list
            for (int index: passenger_waiting_to_be_deleted_index) {
                passenger_waiting.erase(passenger_waiting.begin() + index);
            }

            // sort passenger based on elevator moving direction and passenger destination
            if (move_upward) {
                std::sort(passenger_in_elevator.begin(), passenger_in_elevator.end(), sort_ascending);
            }
            else {
                std::sort(passenger_in_elevator.begin(), passenger_in_elevator.end(), sort_descending);
            }
        }
        // drop passenger
        void drop_passenger() {

            // go through the passenger in elevator list as it is sorted based on destination
            for (size_t i = 0; i < passenger_in_elevator.size(); i++) {
                move(passenger_in_elevator.at(i).floor_destination);
                status(passenger_in_elevator.at(i).name + " dropped");
            }
            // clear the passenger in elevator list
            passenger_in_elevator.clear();
        }

    public:
        // elevator constructor
        Elevator(std::vector<Passenger> passenger_list): passenger_waiting(passenger_list) {
            // init
        }; 
        // start elevator
        void start() {
            // loop until all passenger already sent to their respective floor
            while (passenger_waiting.size() != 0 || passenger_in_elevator.size() != 0) {
                pick_passenger();
                drop_passenger();
            }
        }

};

int main() {

    // random seed
    srand (time(NULL));
    
    // generate list of user
    std::vector<Passenger> passenger_list;
    for (int i = 1; i <= number_of_request; i++) {
        // prevent same current and destination floor
        int user_at = 0;
        int user_go = 0;
        while (user_at == user_go) {
            user_at = rand() % floor_max + floor_min;
            user_go = rand() % floor_max + floor_min;
        }
        // add into a list
        Passenger user("User" + std::to_string(i), user_at, user_go);
        std::cout << "User: name = " << user.name << ", at = " << user.floor_current << ", to = " << user.floor_destination << std::endl;
        passenger_list.push_back(user);
    }

    // elevator start
    Elevator elevator(passenger_list);
    elevator.start();

    return 0;
}