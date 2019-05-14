#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <future>
#include <condition_variable>

// define USE_QUEUE as false to disable thread queue

#define USE_QUEUE true
#define MAX_THREAD 100

class SafeQueue
{
    public:
        SafeQueue() {
            m_thread = std::thread(&SafeQueue::dequeue, this);
        };
        ~SafeQueue() {
            {
                std::unique_lock<std::mutex> lock(m_mutex);
                finished = true;
                m_condition_variable.notify_one();
            }

            if (m_thread.joinable()) {
                m_thread.join();
            }
        };

    // Add an element to the queue.
    void enqueue(int input)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_int_queue.push(input);
        finished = false;
        m_condition_variable.notify_one();
    }

    // If the queue is empty, wait till a element is avaiable.
    void dequeue()
    {
        // infinite
        while (!finished) {

            // not necessary but mutex will be automatically unlocked after out of braces
            {
                std::unique_lock<std::mutex> lock(m_mutex);            
                while(!finished && m_int_queue.empty())
                {
                    // release lock as long as the wait and reaquire it afterwards.
                    m_condition_variable.wait(lock);
                }

                if (finished) {
                    return;
                }
            }
                    
            // operations
            int val = m_int_queue.front();
            m_int_queue.pop();

            // your code lies here
            std::cout << "#" << val << " - done" << std::endl;
        }
    }

    static SafeQueue& get() {
        static SafeQueue safe;
        return safe;
    }

    private:
        bool finished;
        std::mutex m_mutex;
        std::thread m_thread;
        std::queue<int> m_int_queue;
        std::condition_variable m_condition_variable;
    private:
        SafeQueue(SafeQueue const&) = delete; // prevent the singleton be created
        void operator = (SafeQueue const&) = delete; // prevent the singleton be copied by reference
};

void exec(int a) {
    int val = rand() % 10 + 1;
    std::this_thread::sleep_for(std::chrono::microseconds(val));
    if (!USE_QUEUE) {
        std::cout << "#" << a << " - done" << std::endl;
    } else {
        SafeQueue::get().enqueue(a);
    }
}

int main() {

    std::thread t[MAX_THREAD];

    std::cout << "a" << std::endl;
    for (int a = 0; a < MAX_THREAD; a++) {
        t[a] = std::thread(exec, a);
    }
    for (int a = 0; a < MAX_THREAD; a++) {
        t[a].join();
    }

    std::cout << "fin" << std::endl;

    return 0;
}