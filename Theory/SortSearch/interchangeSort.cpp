/*
    Ý tưởng:
    # Khởi tạo i = 0 tiến đến n-2
    - Lấy ra a[i] và ta sẽ đem a[i] so sánh với tất cả a[j] với j = i+1 tiến đến j = n-1,
    nếu thỏa điều kiện thì hoán vị chúng, không thì ta để nguyên. Sau khi thực hiện hết với
    các a[j], ta sẽ tăng i lên 1 và lặp lại các thao tác trên.
*/ 

#include<iostream>

using namespace std;

// Độ phức tạp O(n^2)
void interchangeSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

int main(){
    int a[] = {40,60,15,50,90,20,10,70};
    int n = sizeof(a)/sizeof(a[0]);
    interchangeSort(a,n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}