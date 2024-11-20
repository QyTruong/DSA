#include<iostream>

#define MAX 7

using namespace std;

struct Item {
    int data;
    int next;
};

struct HashTable {
    Item h[MAX];
    int r;
};

void initTable(HashTable &t){
    for (int i = 0; i < MAX; i++){
        t.h[i].data = -1;
        t.h[i].next = -1;
    }
    t.r = MAX-1;
}

int hashFunc(int x){
    return x % MAX;
}

void insertHB(HashTable &t, int x){
    if (t.r >= 0){
        int idx = hashFunc(x);
        
        if (t.h[idx].data == -1)
            t.h[idx].data = x;
        else {
            t.h[t.r].data = x;
            while (t.h[idx].next != -1)
                idx = t.h[idx].next;
            t.h[idx].next= t.r;
        }
        while (t.r >= 0 && t.h[t.r].data != -1)
                t.r--;
    }
}

int search(HashTable t, int x){
    int index = hashFunc(x);
    do {
        if (t.h[index].data == x)
            return index;
        index = t.h[index].next;
    } while (index >= 0);
    return - 1;
}

void print(HashTable t){
    for (int i = 0; i < MAX; i++){
        if (t.h[i].data != -1){
            cout << t.h[i].data << " - " << t.h[i].next << endl;
        }
    }
}

int main(){
    HashTable t;
    initTable(t);
    insertHB(t,5);
    insertHB(t,7);
    insertHB(t,9);
    insertHB(t,3);
    insertHB(t,2);
    insertHB(t,4);
    insertHB(t,8);
    insertHB(t,14);


    print(t);

    return 0;
}