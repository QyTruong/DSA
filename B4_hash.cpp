/*
    Quản lý từ  điển
*/
#include<iostream>
#include<fstream>

#define M 17

using namespace std;

struct Word {
    string word;
    string type;
    string mean;
};

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
struct HashTable {
    Node<T>* h[M];
};

template<typename T>
void init(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        ht.h[i] = NULL;
    }
}

template<typename T>
Node<T>* makeNode(T x){
    Node<T>* newNode = new Node<T>;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int hashFunc(string str){
    int key = 0;
    for (int i = 0; i < str.length(); i++){
        key += (int)tolower(str[i])*(i+1);
    }
    return key % M;
}

string normalize(string str){
    for (int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

template<typename T>
void insertWord(HashTable<T> &ht, T x){
    int k = hashFunc(x.word);

    Node<T>* p = ht.h[k];

    Node<T>* newNode = makeNode(x);
    if (p == NULL){
        ht.h[k] = newNode;
    }
    else {
        while (p != NULL){
            if (normalize(p->data.word) == normalize(x.word)){
                return;
            }
            if (p->next != NULL){
                p = p->next;
            }
            else 
                break;
        }
        p->next = newNode;
    }
}

template<typename T>
void printDict(HashTable<T> ht){
    for (int i = 0; i < M; i++){
        if (ht.h[i] != NULL){
            Node<T>* p = ht.h[i];
            printf("BUCKET %d: ", i);
            while (p != NULL){
                cout << p->data.word << "(" << p->data.type << "): " << p->data.mean; 
                if (p->next != NULL){
                    cout << " | ";
                }
                p = p->next;
            }
            cout << endl;
        }
    }
}

template<typename T>
void inputFile(HashTable<T> &ht){
    ifstream inFile("dictionary.txt");
    if (inFile.is_open()){
        while (!inFile.eof()){
            Word w;
            getline(inFile, w.word, '#');
            getline(inFile, w.type, '#');
            getline(inFile, w.mean);
            insertWord(ht,w);
        }

        inFile.close();
    }
    else 
        cout << "Tep tin hien khong the mo !\n";
}

template<typename T>
void deleleWord(HashTable<T> &ht, string x){
    int k = hashFunc(x);
    Node<T>* p = ht.h[k];
    Node<T>* parent = NULL;
    while (p != NULL && normalize(ht.h[k]->data.word) != normalize(x)){
        parent = p;
        p = p->next;
    }
    if (p == NULL)
        return;

    if (parent == NULL)
        ht.h[k] = p->next;
    else 
        parent->next = p->next;
    p->next = NULL;
    delete p;
}

template<typename T>
Node<T>* searchWord(HashTable<T> &ht, string s){
    int k = hashFunc(s);
    Node<T>* p = ht.h[k];
    while (p != NULL && normalize(p->data.word) != normalize(s)){
        p = p->next;
    }
    return p;
}

template<typename T>
void updateWord(HashTable<T> &ht, T w){
    int k = hashFunc(w.word);
    Node<T>* p = ht.h[k];
    while (p != NULL){
        if (normalize(ht.h[k]->data.word) == normalize(w.word)){
            ht.h[k]->data.type = w.type;
            ht.h[k]->data.mean = w.mean;
            return;
        }

        p = p->next;
    }
}


template<typename T>
void freeDict(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        while (ht.h[i] != NULL){
            Node<T>* p = ht.h[i];
            ht.h[i] = ht.h[i]->next;
            p->next = NULL;
            delete p;
        }
    }
}



int main(){
    HashTable<Word> ht;
    init(ht);

    inputFile(ht);

    printDict(ht);

    cout << "\n=====SAU UPDATE=======\n";

    Word x1;
    x1.word = "Match";
    x1.type = "V";
    x1.mean = "ket hop";
    updateWord(ht,x1);
    printDict(ht);

    cout << "\n=====SAU DELETE=======\n";
    deleleWord(ht, "match");
    printDict(ht);

    freeDict(ht);
    return 0;
}