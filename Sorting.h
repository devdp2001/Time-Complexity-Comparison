#ifndef SORTING_H
#define SORTING_H

#include <iostream>

using namespace std;

//sorting header file with function prototypes
class Sorting {
 public:
  void SelectionSort(int *array, int length);
  void Merge(int * array, int leftFirst, int leftLast, int rightFirst, int rightLast, int length);
  void DoMergeSort(int * array, int first, int last, int length);
  void MergeSort(int *array, int length);
  void ReheapDown(int *& array, int root, int bottom);
  void HeapSort(int *array, int length);
  void DoQuickSort(int * array, int low, int high);
  void DoQuickSortRandom(int * array, int low, int high);
  void QuickSort(int *array, int length);
  void QuickSortRandom( int *array, int length);
  int splitRandom(int *array, int low, int high);
  int Split( int *array, int low, int high);
  int getComparisons();
  
 private:
  int comparisons = 0;
};
#endif
