#include <iostream>
#include <ctime>

// Selection Sort - Gary

// Insertion Sort - Brian

// Bubble Sort - Raf
void bubbleSort(int arr[]) {
    //compare left item to right item
    //if left item is larger, swap
    //increment index
    //repeat with -1 smaller size
    //repeat until all numbers are sorted

    int x = 0;
    int y = 1;
}

// Merge Sort - Gary

// Quick Sort - Brian

// Heap Sort - Raf
//tsetassd
//test 123

// Display Menu
void displayMenu() {
    std::cout << "----- Sorting Menu -----" << std::endl;
    std::cout << "1) Selection Sort" << std::endl;
    std::cout << "2) Insertion Sort" << std::endl;
    std::cout << "3) Bubble Sort" << std::endl;
    std::cout << "4) Merge Sort" << std::endl;
    std::cout << "5) Quick Sort" << std::endl;
    std::cout << "6) Heap Sort" << std::endl;
    std::cout << "Select a sorting algorithm: ";
}

// Validate User Input
void validateInput(int& userChoice) {

    std::cin >> userChoice;
    while (std::cin.fail() || userChoice < 1 || userChoice > 6)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid Input. Please enter a valid option [1-6]: ";
        std::cin >> userChoice;
    }
}

// Randomize List
void randomize(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 10000) + 1;
    }
}

// Copy Array
void copyArray(int original[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = original[i];
    }
}

// Print Array (first 50)
void printArray(int arr[]) {
    std::cout << "-----Items in Array-----" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::cout << "Array[" << i << "]: " << arr[i] << std::endl;
    }
}

// Driver
int main() {
    int const size = 1000;
    int numList[size];
    int numListBackup[size];
    int userChoice;

    randomize(numList, size);
    copyArray(numList, numListBackup, size);

    displayMenu();
    validateInput(userChoice);

    printArray(numList);
    printArray(numListBackup);

    switch (userChoice) {
    case 1:;
        break;
    case 2:;
        break;
    case 3: bubbleSort(numList); // added directly to main branch
        break;
    case 4:;
        break;
    case 5:;
        break;
    case 6:;
        break;
    }

}
    
