// 6-1. 카드2	https://www.acmicpc.net/problem/2164

// deque 구현!

#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    Node(int value, Node * prev = NULL, Node * next = NULL) {
      this->value = value;
      this->prev = prev;
      this->next = next;
    }

    int value;
    Node * prev;
    Node * next;
};

Node * head = NULL;
Node * tail = NULL;

void link(Node * prev, Node * next) {
  prev->next = next;
  next->prev = prev;
}


bool isEmpty() {
  return head == NULL && tail == NULL;
}

void pushToHead(int val) {
  Node * newNode = new Node(val, NULL, NULL);
  if(isEmpty()) {
    head = tail = newNode;
    return;
  }

  link(newNode, head);
  head = newNode;
}

void pushToTail(int val) {
  Node * newNode = new Node(val, NULL);
  if(isEmpty()) {
    head = tail = newNode;
    return;
  }
  
  link(tail, newNode);
  tail = newNode;
}

int popFromHead() {
  if(isEmpty()) return -1;

  int ret = head->value;
  Node * ptr = head;
  head = head->next;
  if(head == NULL) tail = NULL;
  else head->prev = NULL;

  free(ptr);
  return ret;
}

int popFromTail() {
  if(isEmpty()) return -1;

  int ret = tail->value;
  Node * ptr = tail;
  tail = tail->prev;
  if(tail == NULL) head = NULL;
  else tail->next = NULL;

  free(ptr);
  return ret;
}

int isLast() {
  if(head->prev == NULL && tail->next == NULL)
    return head->value;

  return 0;
}

void printAll() {
  Node * ptr = head;

  if(ptr) cout << "The deque is empty.\n";
  while(ptr) {
    cout << ptr->value << ' ';
    ptr = ptr->next;
  }
  cout << '\n';
}



int main() {
  int n; cin >> n;

  for(int i = 1; i <= n; i++) {
    pushToTail(i);
  }

  int ans = -1;
  while(1) {
    ans = popFromHead();
    if(isEmpty()) break;

    int val = popFromHead();
    pushToTail(val);
  }

  cout << ans;
  return 0;
}