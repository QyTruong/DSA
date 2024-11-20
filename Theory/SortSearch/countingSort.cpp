#include<iostream>

using namespace std;

void countingSort(int a[], int n){
    int b[105];
    for (int i = 0; i < 100; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        b[a[i]]++;

    int idx = 0;
    for (int i = 0; i < 100; i++){
        while (b[i] > 0){
            a[idx++] = i;
            b[i]--;
        }
    }
}

void output(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main(){
    int a[] = {5,6,3,2,1,8,7,9,4};
    int n = sizeof(a) / sizeof(a[0]);
    countingSort(a,n);
    output(a,n);

    return 0;
}