#include<iostream>
#include<string>
#include<cstring>

using namespace std;

// Khởi tạo cấu trúc cho stack
struct Node_ST {
    char* data;
    Node_ST* next;
};

struct Stack {
    Node_ST* top;
};

// Khởi tạo stack rỗng
void init(Stack &s){
    s.top = NULL;
}

// Tạo node cho Stack
Node_ST* makeNode_ST(char* x){
    Node_ST* newNode = new Node_ST;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Kiểm tra stack rỗng
bool isEmpty_ST(Stack s){
    return s.top == NULL;
}

// Thêm 1 node vào stack
void pushNode(Stack &s, char* x){
    Node_ST* newNode = makeNode_ST(x);
    if (newNode != NULL){
        if (s.top == NULL)
            s.top = newNode;
        else {
            newNode->next = s.top;
            s.top = newNode;
        }
    }
    return;
} 

// Lấy ra 1 Node stack
char* pop(Stack &s){
    char* x;
    if (s.top != NULL){
        Node_ST* p = s.top;
        s.top = s.top->next;
        x = p->data;
        p->next = NULL;
        delete p;
    }
    return x;
}

// Chọn ra 1 Node trong stack
char* peek(Stack s){
    return s.top->data;
}

// Khởi tạo cấu trúc Queue
struct Node_QU {
    char* data;
    Node_QU* next;
};

struct Queue
{
    Node_QU* head;
};

void init(Queue &q){
    q.head = NULL;
}

// Tạo Node cho Queue
Node_QU* makeNode_QU(char* x){
    Node_QU* newNode = new Node_QU;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Thêm 1 Node vào queue
void enQueue(Queue &q, char* x){
    Node_QU* newNode = makeNode_QU(x);
    if (q.head == NULL)
        q.head = newNode;
    else {
        Node_QU* p = q.head;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}

// Lấy ra 1 Node trong Queue
char* deQueue(Queue &q){
    char* x;
    if (q.head != NULL){
        Node_QU* p = q.head;
        q.head = q.head->next;
        x = p->data;
        p->next = NULL;
        delete p;
    }
    return x;
}

// Kiểm tra Queue rỗng
bool isEmpty_QU(Queue q){
    return q.head == NULL;
}

// Xét ưu tiên cho dấu
int priority_Op(string op){
    if (op == "/" || op == "*")
        return 2;
    else if (op == "+" || op == "-")
        return 1;
    return 0;
}

// Chuyển trung tố thành hậu tố
void infixToPostfix(char str[]){
    Stack s;
    init(s);
    Queue postfix;
    init(postfix);

    char* p = strtok(str, " ");
    while (p != NULL){
        if (isdigit(*p)){
            enQueue(postfix,p);
        }
        else if (*p == '(')
            pushNode(s,p);
        else if (*p == ')'){
            char* op = pop(s);
            while (*op != '('){
                enQueue(postfix,op);
                op = pop(s);
            }
        }
        else {
            while (!isEmpty_ST(s) && priority_Op(p) <= priority_Op(peek(s))){
                char* op = pop(s);
                enQueue(postfix,op);
            }
            pushNode(s,p);
        }
        p = strtok(NULL," ");
    }
    while (!isEmpty_QU(postfix)){
        cout << deQueue(postfix) << " ";
    }
}

int main(){
    char str[] = "2 + 4 - ( 5 - 3 ) / 2 + 3 - 1 * 5";
    infixToPostfix(str);
    return 0;
}