#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void print(int* arr,int size);
void make(int* arr,int* newArray, int size);
void quickSort(int *arr, int left, int right);
void shellSort (int *arr, int size);

int main() {
  int size;
  int *arr = new int[size];
  int *newArray = new int[size];

  cout <<"Enter size of array: " << endl;
  cin >> size;

  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 198 - 99;
  }
  cout<<"Your array: " << endl;
  print(arr, size);
  make(arr, newArray, size);
  cout << endl;
  cout<<"Your array after magic: " << endl;
  make(arr, newArray, size);
  print(newArray,size);
  cout << endl;
  cout << "Your array after second magic" << endl;
  shellSort(newArray, size);
  print(newArray,size);
}

void print(int *arr, int size) {
 for (int i = 0; i < size; i++) {
   cout << arr[i] << " ";
 }
}

void make(int* arr,int* newArray, int size) {
  for (int i = 0; i < size; i++) {
    newArray[i] = arr[i];
    quickSort(newArray, 0, i);
  }
}

void quickSort(int *newArray, int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = newArray[(left + right) / 2];

      while (i <= j) {
            while (newArray[i] < pivot)
                  i++;
            while (newArray[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = newArray[i];
                  newArray[i] = newArray[j];
                  newArray[j] = tmp;
                  i++;
                  j--;
            }
      };
      // rec
      if (left < j)
            quickSort(newArray, left, j);
      if (i < right)
            quickSort(newArray, i, right);
}

void shellSort (int *newArray, int size) {
  int step = 1;
  while (step < step / 3) {
    step =step * 3 + 1;
  }
  while (step >= 1) {
    for (int j = step; j < size; j++) {
      int key = newArray[j];
      int i = j -step;
      while (i >= 0 && newArray[i] > key) {
        newArray[i + step] = newArray[i];
        i -= step;
      }
      newArray[i + step] = key;
      }
   step = (step - 1) /3;
  }
}
