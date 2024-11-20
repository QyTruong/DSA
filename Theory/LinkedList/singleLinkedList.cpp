#include<iostream>

using namespace std;

// Khởi tạo
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

// tìm kiếm
Node* searchNode(Node* head, int x){
    if (head != NULL){
        Node* p = head;
        while (p != NULL){
            if (p->data == x)
                return p;
            p = p->next;
        }
    }
    return NULL;
}

// thêm đầu
void pushFront(Node*& head, int x){
    Node* newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

// xóa đầu
void popFront(Node*& head){
    if (head != NULL){
        Node* p = head;
        head = head->next;
        p->next = NULL;
        delete p;
    }
}

// thêm cuối
void pushBack(Node*& head, int x){
    Node* newNode = makeNode(x);    
    if (head == NULL){
        head = newNode;
        return;
    }
    Node* p = head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = newNode;
}

// xóa cuối
void popBack(Node*& head){
    if (head != NULL){
        if (head->next == NULL){
            head = NULL;
            delete head;
            return;
        }
        Node* p = head;
        Node* prev = NULL;
        while (p->next != NULL){
            prev = p;
            p = p->next;
        }
        prev->next = NULL;
        delete p;
    }
}

// Xóa node chỉ định
void eraseNode(Node*& head, int x){
    if (head != NULL){
        if (head->next == NULL || head->data == x){
            popFront(head);
            return;
        }
        Node* p = head;
        Node* prev = NULL;
        while (p->data != x && p != NULL){
            prev = p;
            p = p->next;
            if (p == NULL)
                return;
        }

        prev->next = p->next;
        p->next = NULL;
        delete p;
    }
}

// in danh sách
void printList(Node*& head){
    if (head != NULL){
        while (head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
    }
}

// giải phóng bộ nhớ
void freeList(Node*& head){
    while (head != NULL){
        popFront(head);
    }
}


int main(){
    Node* head = NULL;
    for (int i = 0; i < 2; i++){
        //pushFront(head,i);
        pushBack(head, i);
    }

    eraseNode(head, 3);
    //popBack(head);
    printList(head);
    
    
    freeList(head);
    return 0;
}