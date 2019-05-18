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
                int return_value = array[current_index - 1];
                array[current_index - 1] = 0;
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

    Data stack;

    stack.push(2);
    stack.display();

    stack.push(3);
    stack.display();

    stack.push(1);
    stack.display();

    stack.push(5);
    stack.display();

    stack.push(7);
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    stack.push(6);
    stack.display();

    stack.pop();
    stack.display();

    return 0;
}