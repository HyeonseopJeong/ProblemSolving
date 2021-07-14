// 6-2. 요세푸스 문제 0	https://www.acmicpc.net/problem/11866

// circular queue로 푸는 문제.

#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    Node(int value, Node * next) {
      this->value = value;
      this->next = next;
    }

    int value;
    Node * next;
};

Node * head = NULL;
Node * tail = NULL;

bool isEmpty() {
  return head == NULL && tail == NULL;
}

void push(int value) {
  Node * newNode = new Node(value, head);

  if(isEmpty()) {
    head = tail = newNode;
    head->next = tail;
    tail->next = head;
    return;
  }

  if(head == tail) {
    head->next = newNode;
  } else {
    tail->next = newNode;
  }

  tail = newNode;
}

int pop(int idx = 0) {
  if(isEmpty()) return -1;

  if(head == tail) {
    int ret = head->value;

    free(head);
    head = tail = NULL;
    return ret;
  }

  while(idx--) {
    tail = head; // ( == tail->next)
    head = head->next;
  }

  int ret = head->value;

  Node * ptr = head;
  tail->next = head->next;
  head = head->next;
  
  free(ptr);
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= n; i++)
    push(i);

  vector<int> ans;

  while(!isEmpty()) {
    int v = pop(k - 1);
    ans.push_back(v);
  }

  cout << '<';
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if(i != (int)ans.size() - 1) cout << ", ";
  }
  cout << '>';

  return 0;
}