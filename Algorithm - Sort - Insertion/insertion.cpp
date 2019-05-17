#include <iostream>

const int DATA_SIZE = 15;

// How does insertion sort works?
// It depends on certain condition:-
//      1. use an index marker to indicate first item of unsorted group. index marker will be increment by one for each item and restart the loop.
//      2. compare the last item on sorted group with the first item of unsorted group. 
//          if the first item of unsorted group is lower than the last item of sorted group,
//              re-sort the sorted group with the first item of unsorted group.
//      3. sorting is complete if the index marker have reached the final item.

void insertionSort(int* data) {
    // set initial value index marker
    int index_marker = 1;

    // condition 3
    while (index_marker != DATA_SIZE) {

        // condition 2
        if (data[index_marker] < data[index_marker - 1]) {
            for (int j = index_marker + 1; j > 0; j--) {
                if (data[j] < data[j - 1]) {
                    // swap
                    int temp = data[j - 1];
                    data[j - 1] = data[j];
                    data[j] = temp;
                }
            }
        }

        // display
        for (int i = 0; i < index_marker + 1; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;

        // increase the index marker
        index_marker++;
    }
}

int main() {

    // use random seed
    srand (time(NULL));

    // populate data with random generated value
    int data[DATA_SIZE];
    std::cout << std::endl << "Original data: " << std::endl;
    for (int i = 0; i < DATA_SIZE; i++) {
        // random value range from 0 to 99
        data[i] = rand() % 100 + 1;
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // bubble sort
    insertionSort(data);

    // return
    std::cout << std::endl;
    return 0;
}