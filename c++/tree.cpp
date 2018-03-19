#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string>
#include <stdio.h>
// видалення парних
using namespace std;

typedef int T;

queue <int> myqueue;

typedef struct Node {
  int data;
  Node *LeftBranch;
  Node *RightBranch;
  Node *Parent;
} Node;

Node* getFreeNode(T value, Node *Parent);

void addToTree(Node **head, int value);

void printTree(Node *Root, const char *dir, int level);

int min(Node *Root);

int find(Node *Root, int elem);

Node *deleteNode(Node *Root, int key);

void delete2(Node *Root);

int main(int argc, char const *argv[]) {

  Node *Root = NULL;
  int* arr = new int[14];

  srand(time(NULL));
  for (int i = 0; i < 14; i++) {
    arr[i] = rand() % 198 - 99;
  }

  for (int i = 0; arr[i]; i++) {
    addToTree(&Root, arr[i]);
  }

    printTree(Root, "Root", 0);

    cout << "Min: " <<min(Root);

    cout << endl;
    int elem = 2;

    find(Root, elem);

    cout << endl;

    delete2(Root);

    printTree(Root, "Root", 0);
    cout << "finish";

  return 0;
}


Node* getFreeNode(T value, Node *Parent) {
  Node *tmp = (Node*) malloc(sizeof(Node));  // malloc виділення певного розмірув пам'яті
  tmp->LeftBranch = tmp->RightBranch = NULL;
  tmp->data = value;
  tmp->Parent = Parent;
  return tmp;
}

void addToTree(Node **head, int value) {
  Node *tmp = NULL; //допоміжна змінна
  Node *ins = NULL; // те,що вставляємо

  if (*head == NULL) { // якщо дерево пусте,то в корінь
    *head = getFreeNode(value, NULL);
    return;
  }

  tmp = *head;
  while (tmp) { // прохід по дерево - пошук місця для вставки
    if (value > tmp->data) { // якщо правий вузол не пустий то корінь - права вітка і розпочинаємо цикл з початку
      if (tmp->RightBranch) {
        tmp = tmp->RightBranch;
        continue;
      }
      else {// якщо правої вітки немає,то вставляємо вузел з права
        tmp->RightBranch = getFreeNode(value, tmp);
        return;
      }
    } // аналогічно опрацьовуємо ліву вітку
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
    if (Root) { // доки рут не фолс то
        printf("lvl %d %s = %d\n", level, dir, Root->data);
        printTree(Root->LeftBranch, "left", level + 1);
        printTree(Root->RightBranch, "right", level + 1);
    }
}


int min(Node *Root) {
 while (Root->LeftBranch) {
   Root = Root->LeftBranch;
 }
 
 return Root->data;
}


int find(Node *Root, int elem) {
  if (Root == NULL) {
     return 0;
  }
  if (Root->data % elem == 0) {
    myqueue.push(Root->data);
    //deleteNode(Root, Root->data);
  }
  find(Root->LeftBranch, elem);
  find(Root->RightBranch, elem);
}

Node *minimum(Node *Root) {
    while (Root->LeftBranch) {
        Root = Root->LeftBranch;
    }
    return Root;
}


Node *deleteNode(Node *Root, int key) {
  if (Root == NULL) {
      return Root;
  }
  else {
     if (key < Root->data) {
        Root->LeftBranch = deleteNode(Root->LeftBranch, key);

      }
      else if(key > Root->data) {
        Root->RightBranch = deleteNode(Root->RightBranch, key);

      }
      //якщо елемент знаходиться в корні поточного піддерева і має два вузла,то слід
      //замінити його мінімальним елементом з правого піддерева і рекурсивно видалити цей мінімальний
      // елемент з правого піддерева
      else if (Root->LeftBranch != NULL && Root->RightBranch != NULL) {
        Root->data = minimum(Root->RightBranch)->data;
        Root->RightBranch = deleteNode(Root->RightBranch, Root->data);

      } // якщо один дочірній вузол - заміна нащадком
      else {
        if (Root->LeftBranch != NULL) {
          Root = Root->LeftBranch;
        }
        else {
          Root = Root->RightBranch;
        }
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
  // if( Root->data % 2 == 0) {
  //   deleteNode(Root, Root->data);
  // }
}
