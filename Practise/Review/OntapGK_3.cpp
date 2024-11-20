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

int isPrime(int n){
    if (n < 2)
        return 0;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void pushBack(Node*&head, int x){
    Node* newNode = makeNode(x);
    if (head == NULL){
        head = newNode;
        head->next = newNode;
        return;
    }
    Node* p = head;
    while (p->next != head){
        p = p->next;
    }
    newNode->next = head;
    p->next = newNode;
}

void printList(Node* head){
    if (head != NULL){
        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }
    cout << endl;
}

Node* search(Node* head, int key){
    Node* p = head;
    do {
        p = p->next;
    } while (p != head && p->data != key);
    if (p->data != key) return NULL;
    return p;
}


void popFront(Node*& head){
    if (head != NULL){
        Node* p = head;
        Node* pLast = head;
        while (pLast->next != head)
            pLast = pLast->next;
        if (pLast == head)
            head = NULL;
        else {
            head = head->next;
            pLast->next = head;
        }
        p->next = NULL;
        delete p;
    }
    return;
}

Node* playGame(Node*& head, int start){
    head = search(head,start);
    int i = 0;
    while (true){
        i++;
        if (isPrime(i)){
            popFront(head);
        }
        else head = head->next;
        if (head->next == head) break;
    }
    return head;
}



void freeList(Node*& head){
    while (head != NULL){
        popFront(head);
    }
}

int main(){
    Node* head = NULL;
    int n; 
    cout << "So nguoi trong vong tron: "; cin >> n;
    for (int i = 1; i <= n; i++){
        pushBack(head, i);
    }

    cout << "Danh sach nguoi trong vong tron:\n";
    printList(head);

    cout << "\nYeu cau 1:\n";
    int yc1; 
    cout << "Ban muon nguoi thu may la nguoi dem 1: "; cin >> yc1;
    printf("Neu nguoi thu %d dem 1 -> nguoi con lai la nguoi thu: %d (nguoi chien thang)\n", yc1, playGame(head,yc1)->data);


    
   

    freeList(head);
    return 0;
}