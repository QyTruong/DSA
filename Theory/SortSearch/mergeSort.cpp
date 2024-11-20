#include<iostream>

using namespace std;

//Độ phức tạp O(nlogn)
void merge(int a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = a[i+l];
    }
    for (int j = 0; j < n2; j++){
        R[j] = a[j+m+1];
    }
    int i = 0, j = 0;
    while (i < n1 && j < n2){
        if (L[i] >= R[j]){
            a[l] = R[j];
            j++; 
        }
        else {
            a[l] = L[i];
            i++;
        }
        l++;
    }
    while (i < n1){
        a[l] = L[i];
        l++; i++;
    }
    while (j < n2){
        a[l] = R[j];
        l++; j++;
    }
}

void mergeSort(int a[], int l, int r){
    if (l >= r) return;
    int middle = (l+r)/2;
    mergeSort(a,l,middle);
    mergeSort(a,middle+1,r);
    merge(a,l,middle,r);
}


int main(){
    int a[] = {2,3,1,9,4,6,7,2};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n-1);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}