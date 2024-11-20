#include<iostream>

#define MAX 7

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void initHash(Node* heads[]){
    for (int i = 0; i < MAX; i++){
        heads[i]= NULL;
    }
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int hashFunc(int x){
    return x % MAX;
}

void insertNode(Node* heads[], int x){
    int index = hashFunc(x);
    Node* h = heads[index];
    Node* prev = NULL;
    
    while (h != NULL && h->data < x){
        prev = h;
        h = h->next;
    }
    Node* newNode = makeNode(x);
    if (prev == NULL){
        heads[index] = newNode;
        newNode->next = h;
    }
    else if (h == NULL){
        prev->next = newNode;
    }
    else {
        prev->next = newNode;
        newNode->next = h;
    }
}

Node* search(Node* heads[], int x){
    int index = hashFunc(x);
    Node* h = heads[index];
    while (h != NULL && h->data != x)
        h = h->next;
    return h;
}

void delNode(Node* heads[], int x){
    if (search(heads, x) != NULL){
        int index = hashFunc(x);
        Node* p = heads[index];
        Node* prev = NULL;

        while (p->data != x){
            prev = p;
            p = p->next;
        }
        if (prev == NULL){
            heads[index] = p->next;
            p->next = NULL;
        }
        else {
            prev->next = p->next;
            p->next = NULL;
        }
        delete p;
    }
    return;
}

void print(Node* heads[]){
    for (int i = 0; i < MAX; i++){
        if (heads[i] != NULL){
            printf("Bucket %d: ", i);
            Node* p = heads[i];
            while (p != NULL){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

int main(){
    Node* heads[MAX];
    initHash(heads);
    insertNode(heads, 8);
    insertNode(heads, 15);
    insertNode(heads,22);
    insertNode(heads, 9);
    insertNode(heads, 12);
    insertNode(heads, 11);
    insertNode(heads, 7);
    insertNode(heads, 3);

    print(heads);

    delNode(heads, 15);
    cout << endl;

    print(heads);

    return 0;
}