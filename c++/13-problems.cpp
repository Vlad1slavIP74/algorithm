#include <iostream>

using namespace std;

void shellsort(int a[]) {
  int i, j, k, h, b;
  b = 6;
  k = b / 2;
  while (k > 0) {
    for (i = 0; i < b - k; i++) {
      j = i;
      while(j >= 0 && a[j] < a[j+k]) {
        h = a[j];
        a[j] = a[j + k];
        a[j + k] = h;
        j--;
      }
    }
    k = k / 2;
  }
}

int main() {
 int A[6] = {889,65,345,123,12,2};
 int B[6];
 for (int i = 0; i < 6; i++) {
   B[i] = A[i];
 }
 shellsort(B);
 for (int i =0; i < 6; i++) {
   cout << A[i] << endl;
 }
 cout << endl;
 for (int i =0; i < 6; i++) {
   cout << B[i] << endl;
 }
}
