#include<iostream>
#include<ctime>

using namespace std;

// Khai báo cấu trúc danh sách
struct Node{
    int data;
    Node* next;
};

// Tạo node 
Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Xuất danh sách
void outputList(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Tìm 1 phần tử trong danh sách
Node* search(Node* head, int x){
    Node* tmp = head;
    while (tmp != NULL && tmp->data != x){
        tmp = tmp->next;
    }
    return tmp;
}

// Thêm 1 phần tử vào đầu danh sách
void pushFront(Node** head, int x){
    Node* newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

// Xóa phần tử đầu danh sách
int popFront(Node** head){
    if (*head == NULL){
        return -1;
    }
    Node* tmp = *head;
    *head = tmp->next;
    delete tmp;
    return 1;
}

// Thêm 1 phần tử vào cuối danh sách
void pushBack(Node** head, int x){
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

// Xóa phần tử cuối danh sách
int popBack(Node** head){
    if (*head == NULL) return -1;
    Node* tmp = *head;
    if (tmp->next == NULL){
        *head = NULL;
        delete tmp;
        return 1;
    }
    while (tmp->next->next != NULL){
        tmp = tmp->next;
    }
    Node* lastNode = tmp->next;
    tmp->next = NULL;
    delete lastNode;
    return 1;
}

// Xóa 1 phần tử giữa danh sách
int erase(Node** head, Node*p){
    if (*head == NULL) return -1;
    Node* tmp = *head;
    if (*head == p){
        // Node* tmp1 = p;
        // *head = tmp1->next;
        // delete tmp1;
        popFront(head);
        return 1;
    }
    while (tmp->next != p){
        tmp = tmp->next;
    }
    Node* tmp2 = p;
    tmp->next = tmp2->next;
    delete tmp2;
    return 1;
}

// Tìm 1 phần tử trong mảng, nếu thấy thì xóa nó
int searchDel(Node** head, int x){
    if (search(*head,x) == NULL)
        return -1;
    else {
        erase(head,search(*head,x));
        return 1;
    }
}

// Sắp xếp danh sách
void sortDs(Node** head){
    for (Node* i = *head; i != NULL; i=i->next){
        Node* min = i;
        for (Node* j = i->next; j != NULL; j=j->next){
            if (min->data > j->data){
                min = j;
            }
        }
        int tmp = i->data;
        i->data = min->data;
        min->data = tmp;
    }
}

int main(){
    // Khởi tạo danh sách rỗng
    Node* head = NULL;
    srand(time(NULL));

    // Câu c và câu g
    cout << "\n======Them=======\n";
    cout << "\tThem cuoi:\n";
    for (int i = 1; i <= 5; i++){
        int x = rand()%21;
        pushBack(&head,x);
    }
    outputList(head);
    cout << "\tThem dau:\n";
    for (int i = 1; i <= 5; i++){
        int x = rand()%21;
        pushFront(&head,x);
    }
    outputList(head);

    // Câu f và câu h
    cout << "\n======Xoa=======\n";
    cout << "\t Xoa dau:\n";
    popFront(&head);
    outputList(head);
    cout << "\tXoa cuoi:\n";
    popBack(&head);
    outputList(head);

    // Trong phần này câu d đã được lồng vào câu i
    cout << "\n======Tim kiem=======\n";
    int x; cout << "Nhap phan tu ban muon tim: "; cin >> x;
    if (searchDel(&head,x) < 0)
        cout << "Khong tim thay\n";
    else
        cout << "Da tim thay phan tu va xoa thanh cong!!\n";
    outputList(head);

    // Câu j
    cout << "\n======Sap xep=======\n";
    cout << "Mang sau khi duoc sap xep: ";
    sortDs(&head);
    outputList(head);
    return 0;
}