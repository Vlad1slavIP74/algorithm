#include <iostream>

using namespace std;

void print(int *A, int &size);
void insert(int *&A, int& size, int n);
void shellSort (int *A, int &size);

int main() {
 int size;
 int num;
 int *A = new int[size];

 cout << "Enter size of array: ";
 cin >> size;
 cout <<"Enter number to insert: ";
 cin >> num;

 for (int i = 0; i < size; i++) {
   cout << "Enter element: ";
   cin >> A[i];
 }
 insert(A, size, num);
 print(A, size);
 shellSort(A, size);
 cout << endl;
 print(A, size);
}


void print(int *A, int &size) {
 for (int i = 0; i < size; i++) {
   cout << A[i] << " ";
 }
}

void insert(int *&A, int& size, int n) {
 int *B = new int[size + 1];
 int i = 0;
 while (A[i] < n) {
   B[i] = A[i];
   i++;
 }

 B[i] = n;
 while (i < size) {
   B[i + 1] = A[i];
   i++;
 }
 delete [] A;
 size ++;
 A = B;
}
void shellSort(int* A, int& size) {
 int step = 1;
 while (step < step / 3) {
   step =step * 3 + 1;
 }
 while (step >= 1) {
   for (int j = step; j < size; j++) {
     int key = A[j];
     int i = j -step;
     while (i >= 0 && A[i] > key) {
       A[i + step] = A[i];
       i -= step;
     }
     A[i + step] = key;
     }
  step = (step - 1) /3;
 }
}
