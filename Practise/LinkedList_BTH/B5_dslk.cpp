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

void selectionSort(Node** head){
    for (Node* i = *head; i != NULL; i = i->next){
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next){
            if (i->data > j->data)
                minNode = j;
        }
        int tmp = i->data;
        i->data = minNode->data;
        minNode->data = tmp;
    }
}

void pushBack(Node** head, const int x){
    Node* newNode = makeNode(x);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    Node* tmp = *head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void inputList(Node** head, int& n){
    do {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0)
            cout << "Vui long nhap lai!!\n";
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        printf("a[%d]: ", i+1);
        int x; cin >> x;
        pushBack(head, x);
    }
    selectionSort(head);
}

int size(Node* head){
    int cnt = 0;
    while (head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void outputList(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* search(Node* head, const int key){
    Node* tmp = head;
    while (tmp != NULL && tmp->data != key){
        tmp = tmp->next;
    }
    return tmp;
}

void delFirst(Node** head){
    if (*head == NULL)
        return;
    Node* tmp = *head;
    *head = tmp->next;
    delete tmp;
}

void erase(Node** head, int key){
    Node* p = search(*head, key);
    if (p == NULL){
        cout << "Danh sach nay khong con phan tu de xoa!!\n";
        return;
    }
    else {
        cout << "Da xoa thanh cong!!\n";
        Node* tmp = p->next;
        *p = *(p->next);
        tmp->next = NULL;
        delete tmp;
    }
}
 
void delList(Node** head){
    while (*head != NULL){
        delFirst(head);
    }
}

int main(){ 
    Node* head = NULL;
    int n;
    inputList(&head, n);
    outputList(head);
    int x;
    cout << "Hay nhap so ban muon xoa: "; cin >> x;
    erase(&head, x);
    outputList(head);
    
    delList(&head);
    return 0;
}