#include<iostream>

#define M 7

using namespace std;

template<typename T>
struct InternalData {
    T key;
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
        ht.h[i].next = -1;
    }
    ht.r = M-1;
}

template<typename T>
int hashFunc(T key){
    return key % M;
}

template<typename T>
void insertNode(HashTable<T> &ht, InternalData<T>* x) {
    int k = hashFunc(x->key);
    if (ht.h[k].data == NULL){
        ht.h[k].data = x;
    }
    else {
        if (ht.h[k].data->key == x->key){
            ht.h[k].data->freq += 1;
        }
        else {
            while (ht.h[k].next != -1){
                if (ht.h[k].data->key == x->key){
                    ht.h[k].data->freq += 1;
                }
                k = ht.h[k].next;
            }
            ht.h[ht.r].data = x;
            ht.h[k].next = ht.r;
        }
    }
    while (ht.r >= 0 && ht.h[ht.r].data != NULL){
        ht.r--;
    }
}

template<typename T>
void printList(HashTable<T> ht){
    for (int i = 0; i < M; i++){
        if (ht.h[i].data != NULL){
            printf("BUCKET %d: ",i); cout << ht.h[i].data->key << "(" << ht.h[i].data->freq << ")" 
                                            << " next: " << ht.h[i].next << endl;
        }
    }
}

template<typename T>
void freeList(HashTable<T> &ht){
    for (int i = 0; i < M; i++){
        ht.h[i].data = nullptr;
        delete[]ht.h[i].data;
    }
}

int main(){
    HashTable<int> ht;
    init(ht);
    int a[] = {15,7,9,7,13,15,20,11,9,15,14};
    int n = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < n; i++){
        InternalData<int>* x = new InternalData<int>;
        x->key = a[i];
        x->freq = 1;
        insertNode(ht,x);
    }

    printList(ht);

    freeList(ht);
    return 0;
}