#include<iostream>

#define MAX 100

using namespace std;

// Khởi tạo bộ nhớ danh sách
void init(int *&p, int n){
    p = new int [n];
}

// Giải phóng bộ nhớ
void free(int *&p){
    delete []p;
    p = nullptr;
}

// Hoán vị
void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

// Sắp xếp
void sort(int *&a, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }
    }
}

// Nhập danh sách
void input(int *&a, int &n){
    do {
        cout << "Hay nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0 || n > MAX)
            cout << "Vui long nhap lai!\n";
    } while (n <= 0 || n > MAX);

    init(a,n);
    for (int i = 0; i < n; i++){
        printf("a[%d]: ", i+1);
        cin >> a[i];
    }
    sort(a,n);
}

// Thêm 1 phần tử vào danh sách
void add(int *&a, int &n, int x){
    if (a == NULL){
        n = 1;
        init(a,n);
        a[0] = x;
    }
    else{
        int* tmp = a;
        init(a,n+1);
        for (int i = 0; i < n; i++){
            a[i] = tmp[i];
        }
        a[n] = x;
        n++;
        delete []tmp;
    }
    sort(a,n);
}

// Xuất danh sách
void output(int *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// Tìm kiếm tuần tự
int linearSearch(int *a, int n, int x){
    for (int i = 0; i < n; i++){
        if (a[i] == x)
            return i;
    }
    return -1;
}

// Tìm kiếm nhị phân
// Chỉ dùng cho mảng đã được sắp xếp tăng dần
int binarySearch(int *&a, int n, int x){
    int l = 0, r = n-1;
    while (l <= r){
        int mid = (l+r)/2;
        if (a[mid] == x) return mid;
        if (x > a[mid]) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

// Xóa 1 phần tử tại 1 vị trí bất kỳ
void erase(int *&a, int &n, int pos){
    for (int i = pos+1; i < n; i++){
        a[i-1] = a[i];
    }
    n--;
    int* tmp = NULL;
    init(tmp,n);
    for (int i = 0; i < n; i++){
        tmp[i] = a[i];
    }
    free(a);
    init(a,n);
    for (int i = 0; i < n; i++){
        a[i] = tmp[i];
    }
    free(tmp);
}

// Tìm phần tử trong danh sách, nếu tìm được thì xóa phần tử đó
void findErase(int *&a, int &n, int x){
    if (binarySearch(a,n,x) < 0)
        cout << "Khong tim thay phan tu!!\n";
    else {
        erase(a,n,binarySearch(a,n,x));
        cout << "Da xoa thanh cong!!\n";
    }
}

// Gộp 2 mảng và sắp xếp theo thứ tự
int* merge_arr_sort(int *a, int *b, int n, int m){
    if (a != NULL && b != NULL){
        int* c;
        init(c,n+m);
        if (c != NULL){
            int index = 0;
            for (int i = 0; i < n; i++){
                c[index++] = a[i];
            }
            for (int i = 0; i < m; i++){
                c[index++] = b[i];
            }
        }
        sort(c,n+m);
        return c;
    }
    return nullptr;
}

int main(){
    int *p = NULL;
    int n;
    cout << "=== Noi dung tu cau A-F ===\n";
    cout << "Mang 1:\n";
    input(p,n);
    cout << "Mang 1: "; output(p,n);
    cout << "Sau khi them 1 phan tu o sau: "; 
    add(p,n,15);
    output(p,n);
    int x1; 
    cout << "Hay nhap phan tu ban muon tim va xoa: "; cin >> x1;
    findErase(p,n,x1);
    cout << "Mang 1: "; output(p,n);


    cout << "\n=== Noi dung cau G ===\n";
    int *q = NULL;
    int m;
    cout << "Mang 2:\n";
    input(q,m);
    sort(p,n);
    sort(q,m);
    cout << "Hai mang sau khi duoc sap xep:\n";
    cout << "Mang 1: "; output(p,n);
    cout << "Mang 2: "; output(q,m);
    int *k = merge_arr_sort(p,q,n,m);
    cout << "Hai mang sau gop khi lai va duoc sap xep:\n";
    cout << "Mang tong: "; output(k,m+n);
    

    free(p);
    free(q);
    return 0;
}