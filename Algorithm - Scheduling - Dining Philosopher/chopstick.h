#pragma once

#include <mutex>

class Chopstick
{
private:
    int index = -1;
    int philosopher_in_use = -1;
    std::mutex mutex;

public:
    Chopstick(int i_index) : index(i_index) {}
    ~Chopstick() {}

public:
    bool isUsed()
    {
        return (philosopher_in_use < 0) ? false : true;
    }
    void usedBy(int philosopher_id)
    {
        std::lock_guard<std::mutex> lock(mutex);
        philosopher_in_use = philosopher_id;
    }
    void release()
    {
        std::lock_guard<std::mutex> lock(mutex);
        philosopher_in_use = -1;
    }
};