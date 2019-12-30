#pragma once

#include <iostream>
#include <mutex>

class Log
{
    // Singleton with mutex lock: to prevent cout to be overlapped
    // As for singleton, you can go to "Design Pattern - Singleton"
    // to learn more.
    // Overlapped condition is known as "racing condition". The term
    // is commonly use in 'thread safe operation' topic, shared
    // memory implementation and deadlock topic.
private:
    Log() {}
    Log(Log const &) = delete;
    void operator=(Log const &) = delete;

public:
    static Log &get()
    {
        static Log instance;
        return instance;
    }

private:
    std::mutex mutex;

public:
    void out(std::string message)
    {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << message << std::endl;
    };
};