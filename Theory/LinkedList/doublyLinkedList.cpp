#include<iostream>

using namespace std;

// khởi tạo
struct Node {
    int data;
    Node *prev, *next;
};

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct DoublyLinkList {
    Node *head, *tail;
};

void init(DoublyLinkList& dl){
    dl.head = dl.tail = NULL;
}

// tìm kiếm
Node* searchNode(DoublyLinkList dl, int x){
    if (dl.head != NULL){
        Node* p = dl.head;
        while (p != NULL){
            if (p->data == x)
                return p;
            p = p->next;
        }
    }
    return NULL;
}

// thêm vào đầu
void pushFront(DoublyLinkList& dl, int x){
    Node* newNode = makeNode(x);
    if (dl.head == NULL){
        dl.head = dl.tail = newNode;
        return;
    }
    newNode->next = dl.head;
    dl.head->prev = newNode;
    dl.head = newNode;
}

// xóa đầu
void delFirst(DoublyLinkList& dl){
    if (dl.head != NULL){
        Node* p = dl.head;
        dl.head = dl.head->next;
        if (dl.head == NULL)
            dl.tail = NULL;
        else
            dl.head->prev = NULL;
        p->next = NULL;
        delete p;
    }
}


// thêm vào cuối
void pushBack(DoublyLinkList& dl, int x){
    Node* newNode = makeNode(x);
    if (dl.head == NULL){
        dl.head = dl.tail = newNode;
        return;
    }
    newNode->prev = dl.tail;
    dl.tail->next = newNode;
    dl.tail = newNode;
}

// xóa cuối
void delLast(DoublyLinkList& dl){
    if (dl.head != NULL){
        Node* p = dl.tail;
        dl.tail = dl.tail->prev;
        if (dl.tail == NULL)
            dl.head = NULL;
        else
            dl.tail->next = NULL;
        p->prev = NULL;
        delete p;
    }
}


// xóa phần tử chỉ định
void eraseNode(DoublyLinkList& dl, int x){
    if (dl.head != NULL){
        Node* p = searchNode(dl,x);
        if (p != NULL){
            if (p == dl.head){
                delFirst(dl);
                return;
            }
            else if (p == dl.tail){
                delLast(dl);
                return;
            }
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            p->next = NULL;
            p->prev = NULL;
            delete p;
        }
    }
}

// in danh sách
void printListASC(DoublyLinkList dl){
    if (dl.head != NULL){
        while (dl.head != NULL){
            cout << dl.head->data << " ";
            dl.head = dl.head->next;
        }
    }
}

void printListDESC(DoublyLinkList dl){
    if (dl.head != NULL){
        while (dl.tail != NULL){
            cout << dl.tail->data << " ";
            dl.tail = dl.tail->prev;
        }
    }
}

void freeList(DoublyLinkList& dl){
    while (dl.head != NULL){
        delFirst(dl);
    }
}


int main(){
    DoublyLinkList dl;
    init(dl);

    for (int i = 0; i < 1; i++){
        pushBack(dl,i);
    }

    eraseNode(dl, 0);
    cout << "Danh sach theo chieu thuan\n";
    printListASC(dl);
    cout << "\nDanh sach theo chieu nghich\n";
    printListDESC(dl);

    freeList(dl);

    return 0;
}