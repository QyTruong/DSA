/*
    Ý tưởng:
    - Chọn ra phần tử x = a[i], sau đó ta sẽ tìm xem từ vị trí thứ j = (i-1, 0) 
    có phần tử nào lớn hơn x hay không ?
    + Nếu có, ta sẽ thay giá trị tại vị trí đó bằng x.
    + Nếu không, ta sẽ dời a[j] về phía sau (a[j+1] = a[j])
*/

#include<iostream>

using namespace std;

// Độ phức tạp O(n^2)
void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int x = a[i];
        int j = i-1;
        while (j >= 0 && x <= a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

int main(){
    int a[] = {4,6,1,2,9,8,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}