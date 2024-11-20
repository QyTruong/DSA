#include<iostream>
#include<string>
#include<cstring>

#define MAX 50

using namespace std;

// Khai báo cấu trúc stack
struct stack {
    char* a[MAX];
    int top;
};

// Khởi tạo stack rỗng
void init(stack &s){
    s.top = -1;
}

// Các tao tác trong stack
// Thêm
void push(stack &s, char * x){
    if (s.top < MAX){
        s.a[++s.top] = x;
    }
    return;
}

// Kiểm tra stack rỗng
bool isEmpty(stack s){
    return s.top == -1;
}

// Lấy ra
char* pop(stack &s){
    if (!isEmpty(s))
        return s.a[s.top--];
    return NULL;
}

// Chọn ra phần tử nằm trên cùng stack
char* peek(stack &s){
    if (!isEmpty(s))
        return s.a[s.top];
    return NULL;
}

int main(){

}