#include<iostream>
#include<stack>

#define M 100

using namespace std;

// Tree
struct Node {
    int data;
    Node *left, *right;
    int height;
};

// Tạo node cho cây 
Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Queue (Linked list)
struct Node_QU{
    Node* value;
    Node_QU* next;
};

struct Queue {
    Node_QU* front, *rear;
};

void initTree(Node*& root){
    root = NULL;
}

void initQueue(Queue& qu){
    qu.front = qu.rear = NULL;
}

// Tạo node cho queue
Node_QU* makeNode(Node* x){
    Node_QU* newNode = new Node_QU;
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

void pushQueue(Queue& qu, Node* x){
    Node_QU* newNode = makeNode(x);
    if (qu.rear == NULL)
        qu.front = newNode;
    else
        qu.rear->next = newNode;
        qu.rear = newNode;
}

Node* popQueue(Queue& qu){
    if (qu.front != NULL){
        Node_QU* p = qu.front;
        Node* x = qu.front->value;
        qu.front = qu.front->next;
        if (qu.front == NULL)
            qu.rear = NULL;
        delete p;
        return x;   
    }
    return NULL;
}

int isEmptyQueue(Queue qu){
    return qu.front == NULL;
}


int getHeight(Node* root){
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(Node* root){
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(Node*& root){
    if (root != NULL)
        root->height = 1 + (getHeight(root->left), getHeight(root->right));
}

void rightRotate(Node*& root){
    Node* p = root->left;
    root->left = p->right;
    p->right = root;

    updateHeight(root);
    updateHeight(p);

    root = p;
}

void leftRotate(Node*& root){
    Node* p = root->right;
    root->right = p->left;
    p->left = root;

    updateHeight(root);
    updateHeight(p);

    root = p;
}

// Thêm node vào cây (dùng AVL cho tối ưu)
void insertNodeTree(Node*& root, int x){
    if (root == NULL)
        root = makeNode(x);
    if (x > root->data)
        insertNodeTree(root->right, x);
    else if (x < root->data)
        insertNodeTree(root->left, x);
    else
        return;

    updateHeight(root);

    int balance = getBalance(root);
    if (balance > 1 && root->left->data > x)
        rightRotate(root);
    else if (balance < -1 && root->right->data < x)
        leftRotate(root);
    else if (balance > 1 && root->left->data < x){
        leftRotate(root->left);
        rightRotate(root);
    }
    else if (balance < -1 && root->right->data > x){
        rightRotate(root->right);
        leftRotate(root);
    }
    
}

// Stack (Array)
struct Stack {
    Node* a[M];
    int top;
};

void initStack(Stack& s){
    s.top = -1;
}

void pushStack(Stack& s, Node* x){
    if (s.top < M)
        s.a[++s.top] = x;
}

int isEmpty(Stack s){
    return s.top == -1;
}

Node* popStack(Stack& s){
    if (!isEmpty(s)){
        return s.a[s.top--];
    }
    return NULL;
}

void LNR(Node* root){
    if (root != NULL){
        LNR(root->left);
        cout << root->data << "(" << root->height << ")" << " ";
        LNR(root->right);
    }
}

void LRN(Node* root){
    if (root != NULL){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << "(" << root->height << ")" << " ";
    }
}

void NLR(Node* root){
    if (root != NULL){
        cout << root->data << "(" << root->height << ")" << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

// LNR không đệ quy
void LNR_NOREC(Node* root){
    if (root != NULL){
        Stack s;
        initStack(s);

        Node* p = root;

        while (!isEmpty(s) || p != NULL){
            while (p != NULL){
                pushStack(s, p);
                p = p->left;
            }
            p = popStack(s);
            cout << p->data << "(" << p->height << ")" << " ";
            p = p->right;
        }
    }
}


// NLR không đệ quy
void NLR_NOREC(Node* root){
    if (root != NULL){
        Stack s;
        initStack(s);

        Node* p = root;
        while (!isEmpty(s) || p != NULL){
            while (p != NULL){
                cout << p->data << "(" << p->height << ")" << " ";
                pushStack(s,p);
                p = p->left;
            }
            p = popStack(s);
            p = p->right;
        }
    }
}

// Duyệt cây theo chiều rộng
void BFS(Node* root){
    if (root != NULL){
        Queue q;
        initQueue(q);

        Node* p = root;
        pushQueue(q,p);
        
        while (!isEmptyQueue(q)){
            Node* r = popQueue(q);
            cout << r->data << "(" << r->height << ")" << " ";

            if (r->left != NULL)
                pushQueue(q, r->left);
            if (r->right != NULL)
                pushQueue(q, r->right);
        }
    }
}

// Queue sử dụng chung cho phương pháp tịnh tiến và vòng
struct QueueArray
{
    Node* a[M];
    int front, rear;
};

void initQueueArray(QueueArray& qu){
    qu.front =  qu.rear = -1;
}

int isEmptyQueueArray(QueueArray qu){
    return qu.front == -1;
}

// Theo phương pháp tịnh tiến
void pushQueueTranslation(QueueArray& qu, Node* x){
    if (qu.rear - qu.front == M-1)
        return;
    else {
        if (qu.front == -1)
            qu.front = 0;
        if (qu.rear == M-1){
            for (int i = qu.front; i <= qu.rear; i++){
                qu.a[i-qu.front] = qu.a[i];
            }
            qu.rear = M-1-qu.front;
            qu.front = 0;
        }
        qu.a[++qu.rear] = x;
        return;
    }
}

Node* popQueueTranslation(QueueArray& qu){
    if (qu.front != -1){
        Node* p = qu.a[qu.front++];
        if (qu.front > qu.rear){
            qu.front = -1;
            qu.rear = -1;
        }
        return p;
    }
    return NULL;
}

// Theo phương pháp vòng
void pushQueueCircle(QueueArray& qu, Node* x){
    if (qu.rear - qu.front == M-1 || (qu.rear - qu.front == -1))
        return;
    if (qu.front == -1)
        qu.front = 0;
    if (qu.rear == M-1)
        qu.rear = -1;
    qu.a[++qu.rear] = x;
}

Node* popQueueCircle(QueueArray& qu){
    if (qu.front != -1){
        Node* p = qu.a[qu.front];
        if (qu.front == qu.rear){
            qu.front = -1;
            qu.rear = -1;
        }
        else {
            qu.front++;
            if (qu.front > M-1)
                qu.front = 0;
        }
        return p;
    }
    return NULL;
}

// Duyệt cây theo chiều rộng (Tịnh tiến)
void BFS_Translation(Node* root){
    if (root != NULL){
        QueueArray q;
        initQueueArray(q);

        Node* p = root;
        pushQueueTranslation(q,p);
        
        while (!isEmptyQueueArray(q)){
            Node* r = popQueueTranslation(q);
            cout << r->data << "(" << r->height << ")" << " ";

            if (r->left != NULL)
                pushQueueTranslation(q, r->left);
            if (r->right != NULL)
                pushQueueTranslation(q, r->right);
        }
    }
}

// Duyệt cây theo chiều rộng (Vòng)
void BFS_Circle(Node* root){
    if (root != NULL){
        QueueArray q;
        initQueueArray(q);

        Node* p = root;
        pushQueueCircle(q, p);
        while (!isEmptyQueueArray(q)){
            Node* r = popQueueCircle(q);
            cout << r->data << "(" << r->height << ")" << " ";
            
            if (r->left != NULL)
                pushQueueCircle(q, r->left);
            if (r->right != NULL)
                pushQueueCircle(q, r->right);
        }
    }
}

int isPrime(int n){
    if (n < 2)
        return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

// Đếm số node chứa giá trị số nguyên tố
int countNodePrime(Node* root, int cnt = 0){
    if (root == NULL)
        return cnt;
    if (isPrime(root->data))
        return 1 + countNodePrime(root->left) + countNodePrime(root->right);
    else 
        return countNodePrime(root->left) + countNodePrime(root->right);
}

Node* searchNode(Node* root, int x){
    if (root != NULL){
        if (root->data == x)
            return root;
        else if (root->data < x)
            searchNode(root->right,x);
        else
            searchNode(root->left,x);
    }
    return NULL;
}

int main(){
    Node* root;
    initTree(root);

    insertNodeTree(root, 1);
    insertNodeTree(root, 2);
    insertNodeTree(root, 3);
    insertNodeTree(root, 4);
    insertNodeTree(root, 5);
    insertNodeTree(root, 6);
    insertNodeTree(root, 7);

    cout << "so luong so nguyen to: " << countNodePrime(root) << endl;

    BFS_Circle(root);

    return 0;
}