#include<iostream>

using namespace std;

void init(int a[], int &sp){
    sp = -1;
}

void push(int a[], int &sp, int x){
    a[++sp] = x;
}

int pop(int a[], int &sp, int &x){
    if (sp != -1){
        x = a[sp--];
        return 1;
    }
    return 0;
}

int isEmpty(int a[], int &sp){
    if (sp == -1)
        return 1;
    return 0;
}

long decToBinary(int a[], int sp, int dec){
    int bin = 0;
    while (dec)
    {
        int x = dec%2;
        push(a,sp,x);
        dec /= 2;
    }
    while (!isEmpty(a,sp)){
        int x1;
        pop(a,sp,x1);
        bin = bin * 10 + x1;
    }
    return bin;
}   

long decToHex(int a[], int sp, int dec){
    int bin = 0;
    while (dec)
    {
        int x = dec%16;
        push(a,sp,x);
        dec /= 16;
    }
    while (!isEmpty(a,sp)){
        int x1;
        pop(a,sp,x1);
        bin = bin * 10 + x1;
    }
    return bin;
}

long decToOct(int a[], int sp, int dec){
    int bin = 0;
    while (dec)
    {
        int x = dec%8;
        push(a,sp,x);
        dec /= 8;
    }
    while (!isEmpty(a,sp)){
        int x1;
        pop(a,sp,x1);
        bin = bin * 10 + x1;
    }
    return bin;
}

int main(){
    int a[100];
    int sp;
    init(a,sp);
    int dec;
    cout << "Hay nhap 1 so he thap phan bat ky: "; cin >> dec;
    cout << "He nhi phan: " << decToBinary(a,sp, dec) << endl;
    cout << "He bat phan: " << decToOct(a,sp,dec) << endl;
    cout << "He thap luc phan: " << decToHex(a,sp,dec) << endl;
    return 0;
}