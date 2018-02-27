#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int arr[]) {
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << "--";
    }
    cout << endl;
}

void quickSort(int arr[], int left, int right) {

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

int main() {
  int A[10];
  int B[10];
  cout << "Enter your array" << endl;
       for (int i = 0; i < 10; i++) {
           cout << "[" << i + 1 << "]" << ": ";
           cin >> A[i];
       }
  for (int i = 0; i < 10; i++) {
    B[i] = A[i];
  }
  quickSort(B, 0, 9);
  cout << "Array A:" << endl;
  print(A);
  cout << "Array B: " <<endl;
  print(B);
  return 0;
}
