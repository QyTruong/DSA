#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void initList(Node*& head){
    head = NULL;
}

void pushFront(Node*& head, int x){
    Node* newNode = makeNode(x);
    if (head == NULL){
        head = newNode;
        head->next = newNode;
        return;
    }
    else {
        Node* p = head;
        while (p->next != head)
            p = p->next;
        newNode->next = head;
        p->next = newNode;
        head = newNode;
        return;
    }
}

void popFront(Node*& head){
    if (head != NULL){
        Node* p = head;
        Node* pLast = head;
        while (pLast->next != head){
            pLast = pLast->next;
        }
        if (pLast == head){
            head = NULL;
        }
        else {
            head = head->next;
            pLast->next = head;
        }
        p->next = NULL;
        delete p;
    }   
    return;
}

void pushBack(Node*& head, int x){
    Node* newNode = makeNode(x);
    if (head == NULL){
        head = newNode;
        head->next = newNode;
    }
    else {
        Node* p = head;
        while (p->next != head)
            p = p->next;
        newNode->next = head;
        p->next = newNode;
    }
    return;
}

void popBack(Node*& head){
    if (head != NULL){
        Node* p = head;
        Node* pLast = NULL;
        if (head->next == head){
            head = NULL;
            delete p;
            return;
        }
        while (p->next->next != head)
            p = p->next;
        pLast = p->next;
        p->next = head;
        pLast->next = NULL;
        
        delete pLast;
    }
    return;
}

Node* search(Node* head, int key){
    Node* p = head;
    while (p != head && p->data != key)
        p = p->next;
    return p;
}

void outPutList(Node* head){
    if (head != NULL){
        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }
    cout << endl;
}

void releaseList(Node*& head){
    while (head != NULL)
        popFront(head);
}

int main(){
    Node* head;
    initList(head);
    pushBack(head, 5);
    //pushBack(head, 5);
    popBack(head);
    outPutList(head);

    releaseList(head);
    return 0;
}