#include<iostream>
#include<ctime>
#include<string>

#define MAX 100

using namespace std;

// Khởi tạo stack rỗng
void init(int a[], int &sp){
    sp = -1;
}

// Kiểm tra danh sách rỗng
int isEmpty(int a[], int sp){
    if (sp == -1)
        return 1;
    return 0;
}

// Kiểm tra danh sách đầy
int isFull(int a[], int sp){
    if (sp == MAX-1)
        return 1;
    return 0;
}

// Thêm phần tử 
int push(int a[], int &sp, int x){
    if (sp < MAX-1){
        a[++sp] = x;
        return 1;
    }
    return 0;
}

// Lấy phần tử ra
int pop(int a[], int &sp, int &x){
    if (sp != -1){
        x = a[sp--];
        return 1;
    }
    return 0;
}

// Nhập danh sách
void input(int a[], int &sp, int &n){
    do {
        cout << "Nhap so luong phan tu ban muon cho vao stack: ";
        cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        printf("So luong phan tu hien co trong stack: %d\n", sp+1);
        int x1; 
        printf("Phan thu %d: ", sp+2); cin >> x1;
        push(a,sp,x1);
    }   
}

// Xuất danh sách
void output(int a[], int sp){
    printf("\tDanh sach %d phan tu trong stack:\n", sp+1);
    for (int i = 0; i <= sp; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[MAX];
    int sp;
    int n;
    srand(time(NULL));

    cout << "=== Nhap xuat co ban (co thao tac push) ===\n";
    init(a,sp);
    input(a,sp,n);
    output(a,sp);

    cout << "\n=== Lay phan tu ra khoi stack ===\n";
    int x1;
    if (pop(a,sp,x1)){
        cout << "Da xoa thanh cong!!\n";
        cout << "Phan tu da duoc lay ra: " << x1 << endl;
    }
    else 
        cout << "Da het phan tu de xoa!!\n";
    output(a,sp);

    // Có thể dùng 2 thao tác dưới đây để kiểm tra isEmpty || isFull (nếu cần)
    // for (int i = 0; i < MAX; i++){
    //     push(a,sp,rand()%11);
    // }
    // while (!isEmpty(a,sp)){
    //     int x2;
    //     pop(a,sp,x2);
    // }
    // output(a,sp);

    cout << "\n=== Kiem tra danh rong hoac day ===\n";
    string ch[2] = {"Danh sach rong", "Danh sach day"};
    if (!isEmpty(a,sp) && !isFull(a,sp))
        cout << "So luong phan tu trong stack dang la: " << sp+1 << endl;
    else 
        cout << ch[isEmpty(a,sp) < isFull(a,sp)];

    return 0;
}