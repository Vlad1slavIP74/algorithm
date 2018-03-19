#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string>
#include <stdio.h>
// видалення елементів за вибором(при цьому вони додаються до дерева)
using namespace std;

typedef int T;

queue<int> myqueue;

typedef struct Node {
  int data;
  Node *LeftBranch;
  Node *RightBranch;
  Node *Parent;
} Node;

Node* getFreeNode(T value, Node *Parent);

void addToTree(Node **head, int value);

void printTree(Node *Root, const char *dir, int level);

Node* minimum(Node *Root);

Node *deleteNode(Node *Root, int key);

void delete2(Node *Root);



int main(int argc, char const *argv[]) {
  int sizeQueue;
  Node *Root = NULL;
  int* arr = new int[14];

  srand(time(NULL));
  for (int i = 0; i < 14; i++) {
    arr[i] = rand() % 198 - 99;
  }



  cout << "Enter number elements to remove " << endl;
  cin >> sizeQueue;
  cout << endl;

  for (int i = 0; i < sizeQueue; i++) {
    int a;
    cout << "Enter elements for queue: ";
    cin >> a;
    addToTree(&Root, a);
    myqueue.push(a);
  }

  for (int i = 0; arr[i]; i++) {
    addToTree(&Root, arr[i]);
  }
    printTree(Root, "Root", 0);

    cout << "Min: " <<minimum(Root)->data;

    cout << endl;
    int elem = 40;

    cout << endl;

    delete2(Root);

    printTree(Root, "Root", 0);
    cout << "finish";
  return 0;
}


Node* getFreeNode(T value, Node *Parent) {
  Node *tmp = (Node*) malloc(sizeof(Node));
  tmp->LeftBranch = tmp->RightBranch = NULL;
  tmp->data = value;
  tmp->Parent = Parent;
  return tmp;
}

void addToTree(Node **head, int value) {
  Node *tmp = NULL;
  Node *ins = NULL;

  if (*head == NULL) {
    *head = getFreeNode(value, NULL);
    return;
  }

  tmp = *head;
  while (tmp) {
    if (value > tmp->data) {
      if (tmp->RightBranch) {
        tmp = tmp->RightBranch;
        continue;
      }
      else {
        tmp->RightBranch = getFreeNode(value, tmp);
        return;
      }
    }
    else if ( value < tmp->data) {
        if (tmp->LeftBranch) {
          tmp = tmp->LeftBranch;
          continue;
        }
        else {
          tmp->LeftBranch = getFreeNode(value, tmp);
          return;
        }
      }

    }
  }


void printTree(Node *Root, const char *dir, int level) {
    if (Root) {
        printf("lvl %d %s = %d\n", level, dir, Root->data);
        printTree(Root->LeftBranch, "left", level + 1);
        printTree(Root->RightBranch, "right", level + 1);
    }
}

Node *minimum(Node *Root) {
    if (Root->LeftBranch == NULL) {
    return Root;
    }
    return minimum(Root->LeftBranch);
}


Node *deleteNode(Node *Root, int key) {
  if (Root == NULL) {
      return Root;
  }
   if (key < Root->data) {
        Root->LeftBranch = deleteNode(Root->LeftBranch, key);

      }
      else if(key > Root->data) {
        Root->RightBranch = deleteNode(Root->RightBranch, key);

      }
      else if (Root->LeftBranch != NULL && Root->RightBranch != NULL) {
        Root->data = minimum(Root->RightBranch)->data;
        Root->RightBranch = deleteNode(Root->RightBranch, Root->data);

      }
      else {
        if (Root->LeftBranch != NULL) {
          Root = Root->LeftBranch;
        }
        else {
          Root = Root->RightBranch;
        }
      }
    return Root;
  }


void delete2(Node *Root) {
  cout << "My queue equal: ";
  while(!myqueue.empty()) {
    cout << myqueue.front() << " ";
    deleteNode(Root, myqueue.front());
    myqueue.pop();
  }

}
