#include <iostream>

const int DATA_SIZE = 5;

// How does bubble sort works?
// It depends on certain condition:-
//      1. complete current loop first
//      2. swap if right number is smaller than right
//      3. sorting is complete if there is no swap occurs

void bubbleSort(int* data) {
    // initial value
    bool swap_occur = true;
    
    while (swap_occur) {

        // reset if previous loop has finished and swap occurs
        // condition 3
        swap_occur = false;

        // condition 1
        for (int j = 0; j < DATA_SIZE - 1; j++) {

            // condition 2
            if (data[j + 1] < data[j]) {
                
                // swap
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;

                // continue
                swap_occur = true;
            }

            // display
            std::cout << data[j] << " ";
            if (j == DATA_SIZE - 2) {
                std::cout << data[j + 1];
            }
        }

        std::cout << std::endl;
    }
}

int main() {

    // use random seed
    srand (time(NULL));

    // populate data with random generated value
    int data[DATA_SIZE];
    std::cout << std::endl << "Original data: " << std::endl;
    for (int i = 0; i < DATA_SIZE; i++) {
        // random value range from 1 to 99
        data[i] = rand() % 99 + 1;
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // bubble sort
    bubbleSort(data);

    // return
    std::cout << std::endl;
    return 0;
}