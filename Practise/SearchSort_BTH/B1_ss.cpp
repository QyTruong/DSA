#include<iostream>
#include<fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void init(Node*& head){
    head = NULL;
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushFront(Node*& head, int x){
    Node* newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

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

void inPut(Node*& head){
    ifstream inMyFile("DanhSach.txt");
    if (inMyFile.is_open()){
        while (!inMyFile.eof()){
            int x; inMyFile >> x;
            pushBack(head,x);
            
        }
        inMyFile.close();
    }
    else {
        cout << "Tep tin hien khong the mo!\n";
    }
}

void outPut(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void delFirst(Node*& head){
    Node* p = head;
    head = head->next;
    p->next = NULL;
    delete p;
}

void releaseList(Node*& head){
    while (head != NULL)
        delFirst(head);
}

// Thiết kế các hàm sort
// InsertionSort
void insertionSort(Node*& head){
    
}

void swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

// SelectionSort
void selectionSort(Node*& head){
    for (Node* i = head; i != NULL; i=i->next){
        Node* tmp = i;
        for (Node* j = i->next; j != NULL; j=j->next){
            if (j->data < tmp->data){
                tmp = j;
            }
        }
        swap(i->data,tmp->data);
    }
}

// InterchangeSort
void interchangeSort(Node*& head){
    for (Node* i = head; i->next != NULL; i=i->next){
        for (Node* j = i->next; j != NULL; j=j->next){
            if (j->data > i->data){
                swap(i->data,j->data);
            }
        }
    }
}


// MergeSort
Node* split(Node* head){
    if (head == NULL)
        return head;
    Node* run = head->next;
    while (run != NULL){
        run = run->next;
        if (run == NULL) break;
        run = run->next;
        head = head->next;
    }
    Node* tmp = head->next;
    head->next = NULL;
    return tmp;
}

Node* merge(Node* head1, Node* head2){
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    if (head1->data < head2->data){
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

Node* mergeSort(Node* head1){
    if (!head1 || !head1->next) 
        return head1;
    // Tạo 1 biến head2 để chứa danh sách nửa cuối sau tách danh sách
    Node* head2 = split(head1);

    // Thao tác tách nửa đầu và nửa cuối cho đến khi => head1 mang giá trị của node bên trái, head2 mang node bên phải
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    
    // Sau khi tách xong => trộn 2 cả
    return merge(head1, head2);
}


int main(){
    Node* head;
    init(head);
    inPut(head);
    mergeSort(head);
    outPut(head);
    releaseList(head);

    return 0;
}