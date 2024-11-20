#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

#define MAX 100

using namespace std;

// Declare and init data
struct SinhVien {
    long mssv;
    string hovaten;
    char ngaysinh[11];
    string quequan;
    double dtb;
};

struct Node {
    SinhVien data;
    Node* next;
};

ostream& operator << (ostream& out, SinhVien sv){
    cout << "========================\n";
    cout << "Ma so sinh vien: " << sv.mssv << endl;
    cout << "Ho va ten: " << sv.hovaten << endl;
    cout << "Ngay sinh: " << sv.ngaysinh << endl;
    cout << "Que quan: " << sv.quequan << endl;
    cout << "Diem trung binh: " << sv.dtb << endl;
    return out;
}

Node* makeNode(SinhVien x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void init(Node*& head){
    head = NULL;
}


// Input data
void inPutOneStudent(SinhVien& sv){
    cout << "Nhap ma so sinh vien: ";
    cin >> sv.mssv; cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, sv.hovaten);
    cout << "Nhap ngay sinh: "; 
    cin.get(sv.ngaysinh, 11);
    cout << "Nhap que quan: "; cin.ignore();
    getline(cin, sv.quequan);
    cout << "Nhap diem trung binh: ";
    cin >> sv.dtb;
}

void pushFront(Node*& head, SinhVien sv){
    Node* newNode = makeNode(sv);
    if (head == NULL)
        head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
}

void inPutList(Node*& head){
    int choice = 1;
    while (choice != 0){
        SinhVien sv;
        inPutOneStudent(sv);
        pushFront(head, sv);
        cout << "Ban co muon nhap them sinh vien khong (1-Co/0-Khong): "; cin >> choice;
    }
}

void intPutFromFile(Node*& head, string filename){
    ifstream inMyFile(filename);
    if (inMyFile.is_open()){
        int n;
        inMyFile >> n;
        int i = 0;
        while (i++ < n){
            SinhVien sv;
            inMyFile >> sv.mssv; inMyFile.ignore();
            getline(inMyFile, sv.hovaten, '#');
            inMyFile.getline(sv.ngaysinh, 11, '#');
            getline(inMyFile, sv.quequan, '#');
            inMyFile >> sv.dtb;
            pushFront(head, sv);
        }

        inMyFile.close();
    }
    else {
        cout << "Tep tin hien khong the mo duoc!!\n";
    }
}


// Output
void outPut(Node* head){
    while (head != NULL){
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}


// Search
Node* search(Node* head, long mssv){
    Node* tmp = head;
    while (tmp != NULL && tmp->data.mssv != mssv){
        tmp = tmp->next;
    }
    return tmp;
}

Node* search(Node* head, string mystring){
    Node* tmp = head;
    while (tmp != NULL && tmp->data.hovaten != mystring){
        if (tmp->data.quequan == mystring)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

// Delete and release data
void popFront(Node*& head){
    if (head != NULL){
        Node* tmp = head;
        head = head->next;
        tmp->next = NULL;
        delete tmp;
    }
}

void releaseList(Node*& head){
    while (head != NULL)
        popFront(head);
}

// Comparater and sort
int cmpWithMssvAsc(SinhVien sv1, SinhVien sv2){
    return sv1.mssv > sv2.mssv ? 1 : (sv1.mssv < sv2.mssv) ? -1 : 0;
}

int cmpWithMssvDesc(SinhVien sv1, SinhVien sv2){
    return -cmpWithMssvAsc(sv1, sv2);
}

int cmpWithNameAsc(SinhVien sv1, SinhVien sv2){
    return sv1.hovaten > sv2.hovaten ? 1 : (sv1.hovaten < sv2.hovaten) ? -1 : 0;
}

int cmpWithNameDesc(SinhVien sv1, SinhVien sv2){
    return -cmpWithNameAsc(sv1, sv2);
}

int cmpWithQueQuanAsc(SinhVien sv1, SinhVien sv2){
    return sv1.quequan > sv2.quequan ? 1 : (sv1.quequan < sv2.quequan) ? -1 : 0;
}

int cmpWithQueQuanDesc(SinhVien sv1, SinhVien sv2){
    return -cmpWithQueQuanAsc(sv1, sv2);
}

void sortList(Node*& head, int func(SinhVien, SinhVien)){
    for (Node* i = head; i != NULL; i=i->next){
        Node* min_pos = i;
        for (Node* j = i->next; j != NULL; j=j->next){
            if (func(min_pos->data,j->data) == 1){
                min_pos = j;
            }
            SinhVien tmp = i->data;
            i->data = min_pos->data;
            min_pos->data = tmp;
        }
    }
}



int main(){
    SinhVien sv;
    Node* head;
    init(head);
    intPutFromFile(head, "Students.txt");
    //inPutList(head);
    //outPut(head);

    //cout << search(head, "Le Van Cuong")->data.mssv;

    cout << "=================SAU KHI DUOC SAP XEP==================\n";
    sortList(head, cmpWithMssvDesc);
    outPut(head);

    releaseList(head);
    return 0;
}