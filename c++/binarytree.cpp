#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int tabs = 0;


struct Branch {
  int Data;
  Branch *LeftBranch;
  Branch *RightBranch;
};


queue <int> myqueue;

void addToTree(int aData, Branch *&aBranch);
void print(Branch *aBranch);
void find(Branch *&Root, int n);
Branch *remove(Branch *Root, int n);

int main() {

  int N,elm;
  cout << "Enter number for work in tree" << endl;
  cin >> N;
  cout << "Enter element into tree" << endl;
  cin >> elm;


  Branch *Root = 0;
  int* arr = new int[14];

  srand(time(NULL));
  for (int i = 0; i < 14; i++) {
    arr[i] = rand() % 198 - 99;
  }


  for (int i = 0; arr[i]; i++) {
    addToTree(arr[i], Root);
  }
  addToTree(elm,Root);
  cout << "Tree" << endl;
  print(Root);

   cout <<"Element: " << endl;
   find(Root, N);
   cout <<"Queue "<<myqueue.front() << endl;
   remove(Root, elm);
   cout << "After" << endl;
   print(Root);
  // cin.get();
}
void addToTree(int aData, Branch *&aBranch) {
  if (!aBranch) {
    aBranch = new Branch;
    aBranch->Data = aData;
    aBranch->LeftBranch = 0;
    aBranch->RightBranch = 0;
    return;
  }
  else if (aBranch->Data > aData) {
    addToTree(aData, aBranch->LeftBranch);
  }
  else {
    addToTree(aData, aBranch->RightBranch);
  };
}

void print(Branch *aBranch) {
  if (!aBranch) return;

  tabs++;
  print(aBranch->LeftBranch);

  for (int i = 0; i < tabs; i++) cout << " ";
  cout << aBranch->Data << endl;

  print(aBranch->RightBranch);
  tabs--;
  return;
}
void find(Branch *&Root, int n) {
  if (Root == NULL) return;
  if (Root->Data % 2 == 0) {
    myqueue.push(*&Root->Data);
    find(Root->LeftBranch, n);
    find(Root->RightBranch, n);
  }
  else {
    find(Root->LeftBranch, n);
    find(Root->RightBranch, n);
  }

}

Branch *remove(Branch *Root, int elm) {
  if (Root == NULL) return 0;
  if (Root->Data < elm) {
    Root->RightBranch = remove(Root->RightBranch, elm);
    return Root;
  }
  else
  if (elm < Root->Data) {
    Root->LeftBranch = remove(Root->LeftBranch, elm);
    return Root;
  }
}
