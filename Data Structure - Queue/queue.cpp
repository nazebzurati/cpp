#include <iostream>

class Data {
    public:
        const static int MAX_ITEM_COUNT = 10;

    private:
        int array[MAX_ITEM_COUNT];
        int current_index = 0;

    public:
        void display() {
            if (!isEmpty()) {
                for (int i = 0; i < current_index; i++) {
                    std::cout << array[i] << " ";
                }
                std::cout << std::endl;
                return;
            }
            std::cout << "Failed: array empty" << std::endl;
        }
        void push(int input) {
            if (current_index < MAX_ITEM_COUNT) {
                array[current_index] = input;
                current_index++;
                return;
            }
            std::cout << "Failed: maximum exceedeed" << std::endl;
        }
        int pop() {
            if (!isEmpty()) {
                int return_value = array[0];
                for (int i = 0; i < current_index; i++) {
                    array[i] = array[i + 1];
                }
                array[current_index] = 0;
                current_index--;
                return return_value;
            }
            std::cout << "Failed: array empty" << std::endl;
            return 0;
        }
        bool isEmpty() {
            return current_index == 0;
        }
};

int main() {

    Data queue;

    queue.push(2);
    queue.display();

    queue.push(3);
    queue.display();

    queue.pop();
    queue.display();

    queue.pop();
    queue.display();

    queue.push(1);
    queue.display();

    queue.push(5);
    queue.display();

    queue.push(7);
    queue.display();

    queue.pop();
    queue.display();

    queue.pop();
    queue.display();

    queue.pop();
    queue.display();

    queue.pop();
    queue.display();

    queue.push(6);
    queue.display();

    queue.pop();
    queue.display();

    return 0;
}