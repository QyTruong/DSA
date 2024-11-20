#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

struct SinhVien {
    string hoVaTen;
    long mssv;
    string lop;
    long sdt;
    double dtb;
};

struct Node {
    SinhVien data;
    Node* prev, *next;
};

struct DoubleLink {
    Node *head, *tail;
};

void init(DoubleLink &dl){
    dl.head = dl.tail = NULL;
}

Node* makeNode(SinhVien sv){
    Node* newNode = new Node;
    newNode->data = sv;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(DoubleLink &dl, SinhVien sv){
    Node* newNode = makeNode(sv);
    if (dl.head == NULL){
        dl.head = dl.tail = newNode;
        return;
    }
    else {
        newNode->prev = dl.tail;
        dl.tail->next = newNode;
        dl.tail = newNode;
    }
}


void inputByKeyBoard(DoubleLink &dl){
    int n;
    do {
        cout << "Hay nhap so luong sinh vien: ";
        cin >> n;
        if (n <= 0)
            cout << "So luong nhap vao khong hop le !\n";
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        printf("Sinh vien thu %d: \n",i+1);
        SinhVien sv;
        cout << "Ho va ten: "; cin.ignore(); getline(cin, sv.hoVaTen); 
        cout << "Ma so sinh vien: "; cin >> sv.mssv;
        cout << "Lop: "; cin >> sv.lop;
        cout << "So dien thoai: "; cin >> sv.sdt;
        cout << "Diem trung binh: "; cin >> sv.dtb;
        insertNode(dl,sv);
    }
}


void inputByFile(DoubleLink& dl){
    ifstream inFile ("otgk_sinhvien.txt");
    if (inFile.is_open()){
        while (!inFile.eof()){
            SinhVien sv;
            getline(inFile, sv.hoVaTen, '#');
            inFile >> sv.mssv; inFile.ignore(1);
            getline(inFile, sv.lop, '#');
            inFile >> sv.sdt; inFile.ignore(1);
            inFile >> sv.dtb; inFile.ignore(1);
            insertNode(dl,sv);
        }

        inFile.close();
    }   
    else 
        cout << "Tep tin hien khong mo duoc!\n";
}

void outputOnConsole(DoubleLink dl){
    cout << "================================\n";
    int i = 1;
    while (dl.head != NULL){
        printf("Sinh vien thu %d: \n", i);
        cout << "Ho va ten: " << dl.head->data.hoVaTen << endl
            << "Ma so sinh vien: " << dl.head->data.mssv << endl
            << "Lop: " << dl.head->data.lop << endl
            << "So dien thoai: " << dl.head->data.sdt << endl
            << "Diem trung binh: " << dl.head->data.dtb << endl
            << "=================\n";
        i++;
        dl.head = dl.head->next;
    }
}

void popFront(DoubleLink& dl){
    if (dl.head != NULL){
        Node* p = dl.head;
        dl.head = dl.head->next;
        p->next = NULL;
        delete p;
    }
    return;
}



void outputEachInfo(DoubleLink dl, vector<int>& choice){
    cout << "================================\n";
    int i = 1;
    int n = choice.size();
    
    while (dl.head != NULL){
        printf("Sinh vien thu %d: \n", i);
        if (choice[0]) cout << "Ho va ten: " << dl.head->data.hoVaTen << endl;
        if (choice[1]) cout << "Ma so sinh vien: " << dl.head->data.mssv << endl;
        if (choice[2]) cout << "Lop: " << dl.head->data.lop << endl;
        if (choice[3]) cout << "So dien thoai: " << dl.head->data.sdt << endl;
        if (choice[4]) cout << "Diem trung binh: " << dl.head->data.dtb << endl;
        cout << "=======================\n";
        i++;
        dl.head = dl.head->next;
    }
}



void menu(vector<int>& choiceList, int& choice){
    cout << "1. Ho Va Ten" << endl
        << "2. MSSV" << endl
        << "3. Lop" << endl
        << "4. So Dien Thoai" << endl
        << "5. Diem Trung Binh" << endl;
    cout << "Hay nhap lua chon cua ban (vd: 134) : ";
    cin >> choice;

    while (choice > 0){
        int pos = choice%10-1;
        choiceList[pos] = 1;
        choice /= 10;
    }
}


void freeList(DoubleLink& dl){
    while (dl.head != NULL){
        popFront(dl);
    }
}

int main(){
    DoubleLink dl;
    vector<int> choiceList (5, 0);
    int n = choiceList.size();
    int choice;

    init(dl);

    inputByFile(dl);
    menu(choiceList, choice);
    
    outputEachInfo(dl, choiceList);

    //outputOnConsole(dl);

    freeList(dl);
    return 0;
}