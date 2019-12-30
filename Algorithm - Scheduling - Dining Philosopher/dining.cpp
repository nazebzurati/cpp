#include <iostream>
#include <vector>

#include "philosopher.h"
#include "chopstick.h"

inline int indexPicker(int index, int size)
{
    return (index >= (size - 1)) ? 0 : index;
}

int main()
{
    std::vector<Philosopher> phis;
    std::vector<std::shared_ptr<Chopstick>> chops;

    // preparing chopstick on table
    for (int i = 0; i < 5; ++i)
    {
        chops.push_back(std::make_shared<Chopstick>(i));
    }

    // populate philosopher at table
    for (int i = 0; i < 5; ++i)
    {
        phis.push_back(Philosopher(i));
        phis.at(i).putChopstickLeft(chops.at(indexPicker(i, 5)));
        phis.at(i).putChopstickRight(chops.at(indexPicker(i + 1, 5)));
    }

    // execute
    std::thread t[5];
    for (int i = 0; i < 5; ++i)
    {
        t[i] = std::thread(&Philosopher::proceed, phis.at(i));
    }

    // join
    for (int i = 0; i < 5; ++i)
    {
        t[i].join();
    }

    // return
    return 0;
}