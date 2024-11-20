#include<iostream>
#include<ctime>

using namespace std;

// Khai báo cấu trúc
struct Node {
    int data;
    Node *next, *prev;
};

struct DoubleLink {
    Node *head, *tail;
};

// Khởi tạo danh sách
void initList(DoubleLink &dl){
    dl.head = dl.tail = NULL;
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Xuất danh sách xuối
void outputList_asc(DoubleLink dl){
    cout << "Danh sach xuoi: ";
    while (dl.head != NULL){
        cout << dl.head->data << " ";
        dl.head = dl.head->next;
    }
    cout << endl;
}

// Xuất danh sách ngược
void outputList_decr(DoubleLink dl){
    cout << "Danh sach nguoc: ";
    while (dl.tail != NULL){
        cout << dl.tail->data << " ";
        dl.tail = dl.tail->prev;
    }
    cout << endl;
}

// Thêm đầu
void pushFront(DoubleLink &dl, int x){
    Node* newNode = makeNode(x);
    if (dl.head == NULL){
        dl.head = dl.tail = newNode;
    }
    else {
        newNode->next = dl.head;
        dl.head->prev = newNode;
        dl.head = newNode;
    }
}

// Thêm cuối
void pushBack(DoubleLink &dl, int x){
    Node* newNode = makeNode(x);
    if (dl.head == NULL){
        dl.head = dl.tail = newNode;
    }
    else {
        newNode->prev = dl.tail;
        dl.tail->next = newNode;
        dl.tail = newNode;
    }
}

// Xóa đầu
int delFirst(DoubleLink &dl){
    if (dl.head == NULL)
        return 0;
    if (dl.head == dl.tail){
        delete dl.head;
        dl.head = dl.tail = NULL;
        return 1;
    }
    Node* tmp = dl.head;
    dl.head->next->prev = NULL;
    dl.head = dl.head->next;
    tmp->next = NULL;
    delete tmp;
    return 1;
}

// Xóa cuối
int delLast(DoubleLink &dl){
    if (dl.head == NULL)
        return 0;
    if (dl.head == dl.tail){
        delete dl.head;
        dl.head = dl.tail = NULL;
        return 1;
    }
    Node* tmp = dl.tail;
    dl.tail->prev->next = NULL;
    dl.tail = dl.tail->prev;
    tmp->prev = NULL;
    delete tmp;
    return 1;
}

// Tìm phần tử
Node* search(DoubleLink dl, int key){
    Node* tmp = dl.head;
    while (tmp != NULL && tmp->data != key){
        tmp = tmp->next;
    }
    return tmp;
}

// Tìm và xóa
int searchDel(DoubleLink &dl, int key){
    Node *p = search(dl, key);
    if (p == NULL)
        return 0;
    else {  
        if (dl.head == p)
            delFirst(dl);
        else if (dl.tail == p)
            delLast(dl);
        else { 
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->next = NULL;
            p->prev = NULL;
            delete p;
        }
    }
    return 1;
}

// Tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần tử x nhập vào; Thêm một phần tử trước phần tử tìm thấy.
Node* lowerBound(DoubleLink dl, int x){
    int min_x = INT_MAX;
    int minBest = INT_MAX;
    Node* tmp = dl.head;
    Node* tmp1 = NULL;
    while (tmp != NULL){
        if (tmp->data >= x){
            min_x = min(min_x, tmp->data-x);
            if (min_x < minBest){
                minBest = min_x;
                tmp1 = tmp;
            }
        }
        tmp = tmp->next;
    }
    return tmp1;
}

// Thêm trước 1 phần tử sau khi tìm kiếm lowerBound ở trên
int addBeforeLowberBound(DoubleLink &dl, int x, int extra){
    Node* p = lowerBound(dl, x);
    if (p == NULL)
        return 0;
    else if (p == dl.head){
        pushFront(dl,extra);
        return 1;
    }
    else {
        Node* newNode = makeNode(extra);
        newNode->next = p;
        newNode->prev = p->prev;
        p->prev->next = newNode;
        p->prev = newNode;
        return 1;
    }
}

// Giải phóng bộ nhớ
void freeList(DoubleLink &dl){
    while (dl.head != NULL)
        delFirst(dl);
}

int main(){
    DoubleLink dl;
    initList(dl);
    srand(time(NULL));

    // Câu d
    cout << "\n=====Them dau=====\n";
    for (int i = 0; i < 5; i++){
        pushFront(dl, rand()%51);
    }
    outputList_asc(dl);
    outputList_decr(dl);

    // Câu e
    cout << "\n=====Them cuoi=====\n";
    for (int i = 0; i < 5; i++){
        pushBack(dl, rand()%51);
    }
    outputList_asc(dl);
    outputList_decr(dl);

    // Câu f
    cout << "\n=====Xoa dau=====\n";
    if (delFirst(dl))
        cout << "Xoa thanh cong!!\n";
    else 
        cout << "Con gi nua dau ma xoa =((\n";
    outputList_asc(dl);
    outputList_decr(dl);
    
    // Câu g
    cout << "\n=====Xoa cuoi=====\n";
    if (delLast(dl))
        cout << "Xoa thanh cong!!\n";
    else 
        cout << "Con gi nua dau ma xoa =((\n";
    outputList_asc(dl);
    outputList_decr(dl);

    // Câu h
    cout << "\n=====Tim va xoa=====\n";
    cout << "Hay chon phan tu ban muon tim va xoa: ";
    int x; cin >> x;
    if (searchDel(dl, x) != 0){
        cout << "Da xoa thanh cong!!\n";
    }
    else {
        cout << "Khong tim thay phan tu!!\n";
    }
    outputList_asc(dl);
    outputList_decr(dl);
    
    // Caau i
    cout << "\n=====Tim gia tri >= x va gan voi x nhat, sau do them phan tu truoc gia tri do=====\n";
    cout << "Nhap x: "; 
    int x1; cin >> x1;
    cout << "Nhap phan tu ban muon them: ";
    int x2; cin >> x2; 
    if (addBeforeLowberBound(dl,x1,x2)){
        cout << "Da them thanh cong!!\n";
    }
    else
        cout << "Khong tim thay phan tu!!\n";
    outputList_asc(dl);
    outputList_decr(dl);

    freeList(dl);
    return 0;
}