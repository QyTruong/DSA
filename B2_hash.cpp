#include<iostream>
#include<cstring>

#define M 17

using namespace std;

template<typename T>
struct InternalData {
    T word;
    int freq;
};

template<typename T>
struct Node {
    InternalData<T>* data;
    int next;
};

template<typename T>
struct HashTable {
    Node<T> h[M];
    int r;
};

template<typename T>
void init(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        ht.h[i].data = NULL;
        ht.h[i].next = - 1;
    }   
    ht.r = M-1;
}

template<typename T>
int hashFunc(T x){
    int key = 0;
    for (int i = 0; i < strlen(x); i++){
        key += (int)*(x+i)*(i+1);
    }
    return key % M;
}

template<typename T>
void insertNode(HashTable<T> &ht, InternalData<T>* x){
    int k = hashFunc(x->word);
    
    if (ht.h[k].data == NULL){
        ht.h[k].data = x;
    }
    else {
        if (strcmp(ht.h[k].data->word, x->word) == 0){
            ht.h[k].data->freq += 1;
        }
        else {
            while (ht.h[k].next != -1){
                if (strcmp(ht.h[k].data->word, x->word) == 0){
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
void printList(HashTable<T> ht){
    for (int i = 0; i < M; i++){
        if (ht.h[i].data != NULL){
            printf("BUCKET %d: ", i);
            cout << ht.h[i].data->word << "(" << ht.h[i].data->freq << ")" << endl;
        }
    }
}

template<typename T>
void inputString(HashTable<T> &ht, T str){
    char* p = strtok(str, " ");
    while (p != NULL){
        InternalData<T>* x = new InternalData<T>;
        x->word = p;
        x->freq = 1;
        insertNode(ht,x);
        p = strtok(NULL, " ");
    }
}


template<typename T>
void freeList(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        ht.h[i].data = nullptr;
        delete[]ht.h[i].data;
    }
}

template<typename T>
void maxFreq(HashTable<T> ht){
    int maxF = 0;
    for (int i = 0; i < M; i++){
        if (ht.h[i].data != NULL){
            if (ht.h[i].data->freq > maxF)
            maxF = ht.h[i].data->freq;
        }
    }
    cout << "Cac tu khoa xuat hien nhieu nhat: ";
    for (int i = 0; i < M; i++){
        if (ht.h[i].data != NULL){
            if (ht.h[i].data->freq == maxF)
            cout << ht.h[i].data->word << " ";
        }
    }
}

int main(){
    HashTable<char*> ht;
    init(ht);
    char s[] = "apple banana apple cherry date banana cherry fig grape date";
    
    inputString(ht,s);
    printList(ht);

    maxFreq(ht);

    freeList(ht);

    return 0;
}