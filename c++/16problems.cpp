#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int* arr,int size);
void remove(int *&arr, int &size);
void shellSort (int *arr, int &size);
void quickSort(int *arr, int left, int right);

int main () {
  int n = 14;
  int size = 14;
  int* arr = new int[14];

  srand(time(NULL));
  for (int i = 0; i < 14; i++) {
    arr[i] = rand() % 198 - 99;
  }
  cout << "Your array is: " << endl;
  print(arr, size);
  remove(arr, size);
  cout << endl;
  cout << "New array is: " << endl;
  print(arr, size);
  cout <<"size: " << size << endl;
  shellSort(arr, size);
  cout << "Array after shellSort" << endl;
  print(arr, size);
  cout << endl;
  cout << "Array after quicksort" << endl;
  quickSort(arr, 0, size - 1);
  print(arr, size);

}

void print(int *arr, int size) {
 for (int i = 0; i < size; i++) {
   cout << arr[i] << " ";
 }
}

void remove(int *&arr,int &size) {
  int newSize = 0;
  for (int i = 0; i < 14; i++) {
    if (arr[i] >= 0) {
      newSize++;
    }
  }
  cout << "New size is: " << newSize << endl;
  int counter = 0;
  int *newArray = new int [newSize];
  for (int i = 0; i < 14; i++) {
    if (arr[i] >= 0) {
        newArray[counter] = arr[i];
        counter++;
      }
    }
  cout << " Counter is: " << counter << endl;
  delete []arr;

  arr = newArray;
  size = newSize;

}

void shellSort (int *arr, int &size) {
  int step = 1;
  while (step < step / 3) {
    step =step * 3 + 1;
  }
  while (step >= 1) {
    for (int j = step; j < size; j++) {
      int key = arr[j];
      int i = j -step;
      while (i >= 0 && arr[i] > key) {
        arr[i + step] = arr[i];
        i -= step;
      }
      arr[i + step] = key;
      }
   step = (step - 1) /3;
  }
}

void quickSort(int *arr, int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      // rec
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
