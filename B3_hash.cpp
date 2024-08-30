#include<iostream>
#include<fstream>
#include<ctime>

#define M 7

using namespace std;

struct UserData {
    int id;
    string name;
    int freq;
};

template<typename T>
struct User {
    T* data;
    int next;
};

template<typename T>
struct HashTable {
    User<T> h[M];
    int r;
};

template<typename T>
void init(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        ht.h[i].data = NULL;
        ht.h[i].next = -1;
    }
    ht.r = M-1;
}

int hashFunc(int key){
    return key % M;
}

template<typename T>
void insertUser(HashTable<T> &ht, UserData* x){
    int k = hashFunc(x->id);
    if (ht.h[k].data == NULL){
        ht.h[k].data = x;
    }
    else {
        if (ht.h[k].data->id == x->id){
            ht.h[k].data->freq += 1;
        }
        else {
            while (ht.h[k].next != -1){
                if (ht.h[k].data->id == x->id){
                    ht.h[k].data->freq += 1;
                }
                k = ht.h[k].next;
            }
            ht.h[ht.r].data = x;
            ht.h[k].next = ht.r;
        }
        while (ht.r >= 0 && ht.h[ht.r].data != NULL){
            ht.r--;
        }
    }
}

template<typename T>
void inputFile(HashTable<T> &ht, T List[]){
    ifstream inFile ("user.txt");
    int i = 0;
    if (inFile.is_open()){
        while (!inFile.eof()){
            UserData u;
            inFile >> u.id;
            inFile.ignore();
            inFile >> u.name;
            u.freq = 1;
            List[i++] = u;
        }
        inFile.close();
    }
    else 
        cout << "Tep tin hien khong the mo!\n";
}

template<typename T>
void insertRandom(HashTable<T> &ht, T List[], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        insertUser(ht, &List[rand()%5]);
    }
}

template<typename T>
void printList(HashTable<T> ht){
    cout << "Danh sach cac users:\n";
    for (int i = 0; i < M; i++){
        if (ht.h[i].data != NULL){
            printf("BUCKET %d: ",i+1);
            cout << ht.h[i].data->id << " | " << ht.h[i].data->name << " | So luot truy cap: " << ht.h[i].data->freq << endl;
        }
    }
}

template<typename T>
void freeList(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        ht.h[i].data = nullptr;
        delete []ht.h[i].data;
    }
}

int main(){
    HashTable<UserData> ht;
    init(ht);

    int n;
    cout << "Nhap so luong user va he thong se tu dong them ngau nhien: ";
    cin >> n;

    UserData List[10];

    inputFile(ht,List);

    insertRandom(ht,List,n);

    printList(ht);

    freeList(ht);

    return 0;
}