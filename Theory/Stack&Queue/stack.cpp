#include<iostream>

#define MAX 100

using namespace std;

// Stack với danh sách đặc
struct Stack {
    int data[MAX];
    int top;
};

void initStack(Stack& s){
    s.top = -1;
} 

void pushStack(Stack& s, int x){
    if (s.top < MAX){
        s.data[++s.top] = x;
    }
}

int isEmpty(Stack s){
    return s.top == -1;
}


int popStack(Stack& s, int& x){
    if (s.top != -1){
        x = s.data[s.top--];
        return 1;
    }
    return 0;
}

int peek(Stack& s, int& x){
    if (s.top != -1){
        x = s.data[s.top];
        return 1;
    }
    return 0;
}

// Stack với linked list
struct Node {
    int data;
    Node* next;
};

struct Stack_LL {
    Node* top;
};

void initStackLinkedList(Stack_LL& s){
    s.top = NULL;
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
}

void pushStack_LL(Stack_LL& s, int x){
    Node* p = makeNode(x);
    p->next = s.top;
    s.top = p;
}

int popStack_LL(Stack_LL& s, int& x){
    if (s.top != NULL){ 
        Node* p = s.top;
        x = p->data;
        s.top = s.top->next;
        p->next = NULL;
        delete p;
        return 1;
    }
    return 0;
}



int main(){


    return 0;
}