#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <istream>

#include "Sorting.h"

using namespace std;

int main() {
  Sorting sort;
  char algorithm;
  int length;
  
  cout << "selection-sort (s), merge-sort (m), heap-sort (h), quick-sort-fp (q), quick-sort-rp (r)" << endl;
  cout << "Enter the algorithm: ";
  cin >> algorithm;

  cout << "Enter the size of the input you would like to test: ";
  cin >> length;
  
  //creates array of user defined length and sets random values into array
  srand(time(NULL));  
  int* array = new int[length];
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    array[i] = rand() % length;
  }
  
  switch (algorithm) {
  case 's': { //selection-sort                                                                         
    sort.SelectionSort(array, length);
    for (int i = 0; i < length; i++) {
       cout << array[i] << " ";
    }
    cout << "\n#Selection-sort comparisons: " <<  sort.getComparisons() << endl;

    break;
  }
  case 'm': { //merge-sort        
    sort.MergeSort(array, length);
    cout << "\n#Merge-sort comparisons: " <<  sort.getComparisons() << endl;

    break;
  }
  case 'h': { //heap-sort                                                                                         
    sort.HeapSort(array, length);
    cout << "\n#Heap-sort comparisons: " <<  sort.getComparisons() << endl;

    break;
  }
  case 'q': { //quick-sort-fp 
    sort.QuickSort(array, length);
    cout << "\n#Quick-sort-fp comparisons: " <<  sort.getComparisons() << endl;

    break;
  }
  case 'r': { //quick-sort-rp 
    sort.QuickSortRandom(array, length);
    cout << "\n#Quick-sort-rp comparisons: " <<  sort.getComparisons() << endl;

    break;
  }
  default: //invalid command                                                                          
    cout << "Invalid command, exiting program..." << endl;

    break;
  }
  
  delete[] array;
}
