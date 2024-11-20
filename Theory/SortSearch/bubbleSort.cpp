/*
    Ý tưởng:
    # khởi tạo i = 0 tiến đến i = n-1;
    - Bắt đầu từ vị trí từ cuối mảng j = n-1 tiến về j > i, ta so sánh các cặp phần tử kế nhau
    nếu thỏa điều kiện thì hoán vị chúng, nếu không thì ta để nguyên. Và ta cứ tiếp tục
    so sánh các cặp phần tử cho đến khi phần tử nhỏ nhất tiến về đầu dãy, sau đó
    ở lần thứ i tiếp theo ta sẽ không xét đến phần tử nhỏ nhất đấy nữa.
*/

#include<iostream>

using namespace std;

// Độ phức tạp O(n^2)
void bubbleSort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = n-1; j > i; j--){
            if (a[j-1] > a[j])
                swap(a[j], a[j-1]);
        }
    }
}

int main(){
    int a[] = {40,60,15,50,90,20,10,70};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }


    return 0;
}