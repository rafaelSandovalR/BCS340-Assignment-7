#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

// Selection Sort - Gary
void selectionSort(int a[] , int size) {
  int outer, inner, min;
  for (outer = 0; outer < size - 1; outer++) {
    min = outer;
    for (inner = outer + 1; inner < size ; inner++) {
      if (a[inner] < a[min]) {
        min = inner;
    }
  }
  int temp = a[outer];
  a[outer] = a[min];
  a[min] = temp;
  }
}
// Insertion Sort - Brian

// Bubble Sort - Raf
void bubbleSort(int arr[]) {
    //compare left item to right item
    //if left item is larger, swap
    //increment index
    //repeat with -1 smaller size
    //repeat until all numbers are sorted
}

// Merge Sort - Gary
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

// Quick Sort - Brian

// Heap Sort - Raf

// Display Menu 
void displayMenu() {
    cout << "\n----- Sorting Menu -----" << endl;
    cout << "1) Print Array" << endl;
    cout << "2) Selection Sort" << endl;
    cout << "3) Insertion Sort" << endl;
    cout << "4) Bubble Sort" << endl;
    cout << "5) Merge Sort" << endl;
    cout << "6) Quick Sort" << endl;
    cout << "7) Heap Sort" << endl;
    cout << "8) Reset Array" << endl;
    cout << "9) Exit" << endl;
    cout << "Select a sorting algorithm: ";
}

// Validate User Input
void validateInput(int& userChoice) {

    cin >> userChoice;
    while (cin.fail() || userChoice < 1 || userChoice > 9)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Please enter a valid option [1-9]: ";
        cin >> userChoice;
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
    cout << "\n-----Items in Array-----" << endl;
    for (int i = 0; i < 25; i++) {
        cout << "Array[" << i << "]: " << arr[i] << "\t\tArray[" << i+25 << "]: " << arr[i + 25] << endl;
    }
}

void ResetArray(int arr[], int copyarr[], int size) {
  for (int i = 0; i < size; i++) {
        arr[i] = copyarr[i];
    }
}

double TimeSnap() {
    time_t t = clock();
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken;
}

// Driver
int main() {
    int const size = 1000;
    int numList[size];
    int numListBackup[size];
    int userChoice;
    double t1, t2;
  
    randomize(numList, size);
    copyArray(numList, numListBackup, size);
  
    while (userChoice != 9)
      {
        displayMenu();
        validateInput(userChoice);
    
        switch (userChoice) {
          case 1: printArray(numList);
          break;
          case 2: 
            t1 = TimeSnap();
            selectionSort(numList, size);
            t2 = TimeSnap();
            cout << "\n-----***Array after Sort***-----" << endl;
            printArray(numList);
            cout << "Run Time: " << fixed << t2 - t1 << endl;
          break;
          case 3: ; //Insertion sort gets called here
          break;
          case 4: bubbleSort(numList); // added directly to main branch
          break;
          case 5: 
            t1 = TimeSnap();
            mergeSort(numList, 0, size - 1);
            t2 = TimeSnap();
            cout << "\n-----***Array after Sort***-----" << endl;
            printArray(numList);
            cout << "Run Time: " << fixed << t2 - t1 << endl;
          break;
          case 6:; // Quick sort gets called here
          break;
          case 7: // Heap sort gets called here
          break;
          case 8: 
            ResetArray(numList, numListBackup, size);
            cout << "\n***ARRAY RESET***" << endl;
          break;
      }
    
    }

}
