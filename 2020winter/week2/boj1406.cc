#include <iostream>
#include <string>

using namespace std;

struct node {
    char ch;
    struct node * prev;
    struct node * next;
};

struct node * cursor;

struct node * init(string str) {
    if(str.length() == 0)
        return nullptr;
    
    struct node * ptr = new struct node;
    ptr->ch = 0;
    ptr->prev = nullptr;
    ptr->next = nullptr;

    int len = str.length();
    
    for(int i = 0; i < len; i++) {
        struct node * n = new struct node;
        n->ch = str[i];
        n->prev = ptr;
        n->next = nullptr;
        ptr->next = n;
        ptr = ptr->next;
    }
    return ptr;
}

void go_left() {
    if(cursor->prev) {
        cursor = cursor->prev;
    }
}

void go_right() {
    if(cursor->next) {
        cursor = cursor->next;
    }
}

void add_node(char ch) {
    struct node * n = new struct node;
    n->ch = ch;
    n->prev = cursor;
    n->next = cursor->next;
    if(cursor->next)
        cursor->next->prev = n;
    cursor->next = n;
    cursor = cursor->next;
}

void del_node() {
    if(cursor->prev) {
        struct node * tmp;
        cursor->prev->next = cursor->next;
        if(cursor->next)
            cursor->next->prev = cursor->prev;
        tmp = cursor->prev;
        delete cursor;
        cursor = tmp;   
    }
}

void print() {
    struct node * ptr = cursor;
    while(ptr->prev) {
        ptr = ptr->prev;
    }
    

    if(ptr)
        ptr = ptr->next;
    
    while(ptr) {
        printf("%c", ptr->ch);
        ptr = ptr->next;
    }
}

int main() {
    int n;
    string str;
    cin >> str;
    cursor = init(str);
    
    cin >> n;
    
    
    
    while(n--) {
        char op1, op2;
        cin >> op1;
        if(op1 == 'P') {
            cin >> op2;
            add_node(op2);
        }
        else if(op1 == 'L') {
            go_left();
        }
        else if(op1 == 'D') {
            go_right();
        }
        else {
            del_node();
        }
    }

    print();

    return 0;
}