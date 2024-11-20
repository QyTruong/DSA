/*
    Ý tưởng:
    - Từ vị trí thứ min_pos = i trở đi là j = i+1 ta sẽ tìm phần tử a[j] có giá trị nhỏ nhất:
    + Nếu tìm thấy, ta sẽ cập nhật min_pos = j, sau đó hoán vị a[i] và a[min_pos].
    + Nếu không tìm thấy, ta sẽ tăng i lên 1 và lặp lại quá trình trên.
*/

#include<iostream>

using namespace std;

// Độ phức tạp O(n^2)
void selectionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int min_pos = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[min_pos])
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
    }
}

int main(){
    int a[] = {4,3,5,6,1,2,6,9};
    int n = sizeof(a)/sizeof(a[0]);
    selectionSort(a,n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}