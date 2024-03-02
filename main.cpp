#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <istream>

#include "Sorting.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  ifstream listFile(argv[1]);
  int value;
  int length = 0;
  Sorting sort;
  
  if (!listFile)
    {
      cout << ("Error: File not found");
      exit (EXIT_FAILURE);
    }

  //create array for values                                              
  int array[10000];

  //add values for txt file into array
  for(int i = 0; i < 10000; i++) {
    if (listFile >> value)
      {
        array[i] = value;

        length++;
      }
  }
  
  char command;
  
  cout << "selection-sort (s), merge-sort (m), heap-sort (h), quick-sort-fp (q), quick-sort-rp (r)" << endl;
  cout << "Enter the algorithm: ";
  cin >> command;
  
  switch (command) {
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
    for	(int i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "\n#Merge-sort comparisons: " <<  sort.getComparisons() << endl;
    
    break;
  }
  case 'h': { //heap-sort
    sort.HeapSort(array, length);
    for	(int i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "\n#Heap-sort comparisons: " <<  sort.getComparisons() << endl;          
    
    break;
  }
  case 'q': { //quick-sort-fp                                                           
    sort.QuickSort(array, length);
    for	(int i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "\n#Quick-sort-fp comparisons: " <<  sort.getComparisons() << endl;
        
    break;
  }
  case 'r': { //quick-sort-rp
    sort.QuickSortRandom(array, length);
    for (int i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "\n#Quick-sort-rp comparisons: " <<  sort.getComparisons() << endl;    
    
    break;
  }
  default: //invalid command
    cout << "Invalid command, exiting program..." << endl;

    break;
  }
} 
