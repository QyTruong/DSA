#include<iostream>
#include<stack>

using namespace std;

// void quickSort(int a[], int left, int right){
//     int l = left;
//     int r = right;
//     int pivot = a[(left+right)/2];
//     while (l < r){
//         while (a[l] < pivot)
//             l++;
//         while (a[r] > pivot)
//             r--;
//         if (l <= r){
//             swap(a[l], a[r]);
//             l++; r--;
//         }
//     }
//     if (left < r)
//         quickSort(a,left, r);
//     if (l < right)
//         quickSort(a,l,right);
// }

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(int arr[], int left, int right) {
    stack<int> stack;

    stack.push(left);
    stack.push(right);

    while (!stack.empty()) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();

        int pivot = partition(arr, left, right);

        // Nếu có phần tử ở bên trái của pivot, thêm vào stack
        if (pivot - 1 > left) {
            stack.push(left);
            stack.push(pivot - 1);
        }

        // Nếu có phần tử ở bên phải của pivot, thêm vào stack
        if (pivot + 1 < right) {
            stack.push(pivot + 1);
            stack.push(right);
        }
    }
}

void output(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int a[] = {5,2,3,6,4,45,12,1};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n-1);

    output(a,n);
    return 0;
}