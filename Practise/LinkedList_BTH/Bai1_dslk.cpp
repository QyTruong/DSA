#include<iostream>

#define MAX 100

using namespace std;

// Nhập danh sách
void input(int arr[], int &n){
    do {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0 || n > MAX)
            cout << "Vui long nhap lai!\n";
    } while (n <= 0 || n > MAX);

    for (int i = 0; i < n; i++){
        printf("a[%d]: ",i+1);
        cin >> arr[i];
    }
}

// Xuất danh sách
void output(int arr[], int n){
    cout << "\tDANH SACH CAC PHAN TU:\n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Tìm 1 phần tử trong danh sách
// Độ phức tạp O(n);
int findElement(int arr[], int n, int x){
    for (int i = 0; i < n; i++){
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Thêm 1 phần tử vào cuối danh sách
int pushBack(int arr[], int &n, int x){
    if (n == MAX){
        return 0;
    }
    arr[n] = x;
    n++;
    return 1;
}

// Xóa phần tử cuối danh sách
int popBack(int arr[], int &n){
    if (n == 0){
        return 0;
    }
    arr[n] = 0;
    n--;
    return 1;
}

// Xóa phần tử tại vị trí thứ i
int erase(int arr[], int &n, int pos){
    if (n == 0){
        return 0;
    }
    for (int i = pos+1; i < n; i++){
        arr[i-1] = arr[i];
    }
    n--;
    return 1;
}

// Thêm 1 phần tử tại vị trí i
int add(int arr[], int &n, int x, int pos){
    if (n == MAX){
        return 0;
    }
    for (int i = n; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = x;
    n++;
    return 1;
}

// Tìm một phần tử trong danh sách. Nếu tìm thấy, xoá phần tử đó
int findErase(int arr[], int &n, int x){
    if (n == 0){
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            erase(arr,n,i);
            return 1;
        }
    }
    return 0;
}

void menu(){
    cout << "0.Chuong trinh ket thuc!!\n";
    cout << "1.Nhap danh sach\n";
    cout << "2.Xuat danh sach\n";
    cout << "3.Tim 1 phan tu va tinh do phuc tap\n";
    cout << "4.Them 1 phan tu vao cuoi danh sach\n";
    cout << "5.Xoa phan tu vao cuoi danh sach\n";
    cout << "6.Xoa phan tu tai vi tri i trong danh sach\n";
    cout << "7.Them 1 phan tu vao danh sach tai vi tri i\n";
    cout << "8.Tim 1 phan tu trong sanh sach. Neu thay thi xoa\n";
}

int main(){
    int a[MAX], n;
    int choice;
    do {
        system("cls");
        menu();
        cout << "Your choice: "; cin >> choice;
        switch (choice)
        {
        case 0:{
            cout << "Chuong trinh ket thuc!!\n";
            break;
        }
        case 1:{
            cout << "\tNhap danh sach:\n";
            input(a,n);
            break;
        }
        case 2:{
            cout << "\tXuat danh sach\n";
            output(a,n);
            break;
        }
        case 3:{
            cout << "\tTim 1 phan tu va tinh do phuc tap\n";
            cout << "Do phuc tap cua thuat toan: O(n)\n";
            int x; cout << "Nhap phan tu can tim: "; cin >> x;
            if (findElement(a,n,x) < 0)
                cout << "Khong tim thay phan tu!!\n";
            else 
                cout << "Nam tai vi tri thu: " << findElement(a,n,x)+1 << endl;
            break;
        }
        case 4:{
            cout << "\tThem 1 phan tu vao cuoi danh sach\n";
            int x; cout << "Phan tu ban muon them: "; cin >> x;
            if (pushBack(a,n,x))
                cout << "Da them thanh cong!!\n";
            else
                cout << "Khong the them phan tu vao danh sach!!\n";
                break;
        }
        case 5:{
            cout << "\tXoa phan tu vao cuoi danh sach\n";
            if (popBack(a,n))
                cout << "Da xoa thanh cong!!\n";
            else
                cout << "Khong co phan tu de xoa\n";
            break;
        }
        case 6:{
            cout << "\tXoa phan tu tai vi tri i trong danh sach\n";
            int x; cout << "Hay nhap vi tri ban muon xoa: "; cin >> x;
            if (erase(a,n,x-1))
                cout << "Da xoa thanh cong!!\n";
            else
                cout << "Khong co phan tu de xoa\n";
            break;
        }
        case 7:{
            cout << "\tThem 1 phan tu vao danh sach tai vi tri i\n";
            int x; cout << "Phan tu ban muon them: "; cin >> x;
            int x1; cout << "Vi tri ban muon them: "; cin >> x1;
            if (add(a,n,x,x1-1))
                cout << "Da them thanh cong!!\n";
            else
                cout << "Khong the them phan tu vao danh sach!!\n";
                break;
        }
        case 8:{
            cout << "\tTim 1 phan tu trong sanh sach. Neu thay thi xoa\n";
            int x; cout << "Phan tu ban muon tim: "; cin >> x;
            if (findErase(a,n,x))
                cout << "Da tim thay va xoa thanh cong!!\n";
            else
                cout << "khong tim thay\n";
            break;
        }
        default:
            cout << "Lua chon khong hop le!!\n";
            break;
        }
        system("pause");
    } while (choice != 0);

    return 0;
}