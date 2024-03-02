#include "Sorting.h"

void Sorting::SelectionSort(int * array, int length){
  int endIndex = length-1;

  for(int current = 0; current < endIndex; current++) {
    int minIndex = current;
    
    for(int index = current + 1; index <= endIndex; index++){
      comparisons++;
      if(array[index] < array[minIndex])
	minIndex = index;
    }

    //swap
    int temp = array[current];
    array[current] = array[minIndex];
    array[minIndex] = temp;
  }
}

void Sorting::ReheapDown(int *& array, int root, int bottom){
  int maxChild;
  int rightChild;
  int leftChild;
  
  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;

  comparisons++;
  if(leftChild <= bottom){
    comparisons++;
    if(leftChild == bottom)
      maxChild = leftChild;
    else{
      comparisons++;
      if(array[leftChild] <= array[rightChild])
	maxChild = rightChild;
      else
	maxChild = leftChild;
    }
    comparisons++;
    if(array[root] < array[maxChild]){
      int temp = array[root];
      array[root] = array[maxChild];
      array[maxChild] = temp;

      ReheapDown(array, maxChild, bottom);
    }
  }
}


void Sorting::HeapSort(int * array, int length){
  int index;
  
  //convert to  heap
  for(index = length/2-1; index >=0; index--)
    ReheapDown(array, index, length-1);

  //sort array
  for(index = length-1; index >= 1; index--){
    int temp = array[0];
    array[0] = array[index];
    array[index] = temp;

    ReheapDown(array, 0, index-1); //recursive call
  }
}

void Sorting::Merge(int * array, int leftFirst, int leftLast, int rightFirst, int rightLast, int length){
  int * tempArray = new int[length];
  int index = leftFirst;
  int saveFirst = leftFirst;

  while((leftFirst <= leftLast) && (rightFirst <= rightLast)){
    comparisons++;
    if( array[leftFirst] < array[rightFirst]){
      tempArray[index] = array[leftFirst];
      leftFirst++;
    }
    else{
      tempArray[index] = array[rightFirst];
      rightFirst++;
    }
    index++;
  }
  //copt left half items
  while(leftFirst <= leftLast){
    tempArray[index] = array[leftFirst];
    leftFirst++;
    index++;
  }
  //copy right half items
  while(rightFirst <= rightLast){
    tempArray[index] = array[rightFirst];
    rightFirst++;
    index++;
  }

  for(index = saveFirst; index <= rightLast; index++)
    array[index] = tempArray[index];

  delete [] tempArray; //delete the array to avoid data leak
}

void Sorting::DoMergeSort(int * array, int first, int last, int length){
  if(first < last){
    int middle = (first + last) / 2;

    DoMergeSort(array, first, middle, length);
    DoMergeSort(array, middle + 1, last, length);
    Merge(array, first, middle, middle + 1, last, length);
  }
}

void Sorting::MergeSort(int * array, int length){
  DoMergeSort(array, 0, length-1, length);
}

void Sorting::QuickSort(int * array, int length){
  DoQuickSort(array, 0, length - 1);
}

void Sorting::QuickSortRandom(int * array, int length) {
  DoQuickSortRandom(array, 0, length - 1);
}

void Sorting::DoQuickSort(int * array, int low, int high){
  //quickSort algorithm for first as pivot
  if (low < high) {
    int pi = Split(array, low, high);

    DoQuickSort(array, low, pi - 1);
    DoQuickSort(array, pi + 1, high);
  }
}

void Sorting::DoQuickSortRandom(int * array, int low, int high){
  //quickSort algorithm for random pivot
  if (low < high) {
    int pi = splitRandom(array, low, high);

    DoQuickSort(array, low, pi - 1);
    DoQuickSort(array, pi + 1, high);
  }
}

int Sorting::splitRandom(int * array, int low, int high) {
  //makes a random pivot
  
  srand(time(NULL));
  int random = low + rand() % (high-low);

  int temp = array[random];
  array[random] = array[high];
  array[high] = temp;

  return Split(array, low, high);
}

int Sorting::Split(int * array, int low, int high) {
  int pivot = array[high];
  int i (low - 1);

  for (int j = low; j <= high - 1; j++) {
    comparisons++;
    if (array[j] <= pivot) {
      i++;
      
      //swap values
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
    
  }
  //swap values
  int temp2 = array[i+1];
  array[i+1] = array[high];
  array[high] = temp2;

  return (i+1);
}

int Sorting::getComparisons(){
  return comparisons;
}
