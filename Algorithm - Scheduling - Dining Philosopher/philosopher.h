#pragma once

#include <thread>
#include <chrono>

#include "chopstick.h"
#include "common.h"

class Philosopher
{
private:
    int index = -1;
    std::shared_ptr<Chopstick> chopstick_left;
    std::shared_ptr<Chopstick> chopstick_right;

public:
    Philosopher(int i_index) : index(i_index){};
    ~Philosopher() {}

public:
    void putChopstickLeft(std::shared_ptr<Chopstick> chopstick)
    {
        chopstick_left = chopstick;
    }
    void putChopstickRight(std::shared_ptr<Chopstick> chopstick)
    {
        chopstick_right = chopstick;
    }
    void proceed()
    {
        while (1)
        {
            // thinking
            int thinking_time_ms = rand() % 500 + 1;
            Log::get().out("Philosopher " + std::to_string(index) + " is thinking for " + std::to_string(thinking_time_ms) + "ms");
            std::this_thread::sleep_for(std::chrono::milliseconds(thinking_time_ms));

            // hungry and try to use chopstick
            Log::get().out("Philosopher " + std::to_string(index) + " is hungry");
            if (chopstick_left->isUsed() || chopstick_right->isUsed())
            {
                Log::get().out("Nearby chopstick is in use. Philosopher " + std::to_string(index) + " rethink ..");
                continue;
            }
            Log::get().out("Philosopher " + std::to_string(index) + " secured both chopstick");
            chopstick_left->usedBy(index);
            chopstick_right->usedBy(index);

            // eating
            int eating_time_ms = rand() % 500 + 1;
            Log::get().out("Philosopher " + std::to_string(index) + " is eating for " + std::to_string(eating_time_ms) + "ms");
            std::this_thread::sleep_for(std::chrono::milliseconds(eating_time_ms));

            // finish
            Log::get().out("Philosopher " + std::to_string(index) + " finish eating");
            chopstick_left->release();
            chopstick_right->release();
            break;
        }
    }
};