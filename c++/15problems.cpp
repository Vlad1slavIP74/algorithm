#include <iostream>

using namespace std;

void print(int* array);
void quickSort(int *array, int left, int right);
void shellSort (int *array);

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(array);
  cout << endl;
  quickSort(array, 0, 9);
  print(array);
  shellSort(array);
  cout << endl;
  print(array);
  return 0;
}
 void print(int* array) {
   for (int i = 0; i < 10; i++) {
     cout<< array[i] << " ";
   }
 }

 void quickSort(int *arr, int left, int right) {

       int i = left, j = right;
       int tmp;
       int pivot = arr[(left + right) / 2];

       while (i <= j) {
             while (arr[i] > pivot)
                   i++;
             while (arr[j] < pivot)
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

 void shellSort(int* array) {
  int step = 1;
  while (step < step / 3) {
    step =step * 3 + 1;
  }
  while (step >= 1) {
    for (int j = step; j < 10; j++) {
      int key = array[j];
      int i = j - step;
      while (i >= 0 && array[i] < key) {
        array[i + step] = array[i];
        i -= step;
      }
      array[i + step] = key;
      }
   step = (step - 1) /3;
  }
 }
