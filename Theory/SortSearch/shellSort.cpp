#include<iostream>

using namespace std;

void shellSort(int a[], int n){
    int h = 1;

    while (h <= n/3)
        h = h*3 + 1;
    while (h > 0){
        for (int i = h; i < n; i++){
            int x = a[i];
            int j = i;
            while (a[j-h] > x && j >= h) {
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = x;
        }
        h = (h-1)/3;
    }
}

void shellSort_1(int a[], int n){
    for (int gap = n/2; gap >= 0; gap--){
        for (int i = gap; i < n; i++){
            int x = a[i];
            int j;
            for (j = i; j >= gap && a[j-gap] > x; j -= gap)
                a[j] = a[j - gap];
            a[j] = x;
        }
    }
}

void output(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int a[] = {5,2,3,4,1,6,8,7};
    int n = sizeof(a) / sizeof(a[0]);
    shellSort_1(a,n);
    output(a,n);

    return 0;
}