#include<iostream>

using namespace std;

// Khởi tạo
struct Node {
    int data;
    Node* left,* right;
};

void init(Node*& root){
    root = NULL;
}

struct Node_ST {
    Node* value;
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
Node_ST* makeNode_ST(Node* x){
    Node_ST* newNode = new Node_ST;
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

// Kiểm tra stack rỗng
bool isEmpty_ST(Stack s){
    return s.top == NULL;
}

// Thêm 1 node vào stack
void pushNode(Stack &s, Node* x){
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
Node* pop(Stack &s){
    Node_ST* p = s.top;
    Node* x = NULL;
    if (p != NULL){
        s.top = s.top->next;
        x = p->value;
        p->next = NULL;
        delete p;
    }
    return x;
}

// Chọn ra 1 Node trong stack
int peek(Stack s){
    return s.top->value->data;
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Tìm kiếm
Node* search(Node* root, int key){
    while (root != NULL){
        if (root->data == key)
        return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

Node* search1(Node* root, int key){
    if (root != NULL){
        if (root->data == key)
        return root;
        else if (root->data > key)
            return search1(root->left,key);
        else
            return search1(root->right,key);
    }
    return NULL;
}

// Thêm vào node cây
void insertNode(Node*& root, int x){
    if (root == NULL){
        Node* newNode = makeNode(x);
        root = newNode;
        return;
    }
    else {
        if (root->data == x){
            cout << "Phan tu nay da co roi!\n";
            return;
        }
        else if (root->data > x)
            return insertNode(root->left,x);
        else
            return insertNode(root->right,x);
    }

}

// Xóa node trong cây
void findLeftInf(Node*& p, Node*& q){
    if (q->left == NULL){
        p->data = q->data;
        p = q;
        q = q->right;
    }
    else
        findLeftInf(p,q->left);
}

void delNode(Node*& root, int x){
    if (root == NULL)
        return;
    if (root->data == x){
        Node* p = root;
        if (root->right == NULL)
            root = root->left;
        else if (root->left == NULL)
            root = root->right;
        else {
            findLeftInf(p,root->right);
        }
        delete p;
        return; 
    }
    else {
        if (root->data > x)
            return delNode(root->left,x);
        else
            return delNode(root->right,x);
    }

}

// Duyệt cây
void LNR(Node* root){
    if (root != NULL){
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
    
}

void LNR_ST(Node* root){
    Stack s;
    init(s);
    Node* p = root;
    while (true){
        while (p != NULL){
            pushNode(s,p);
            p = p->left;
        }
        if (!isEmpty_ST(s)){
            Node* value = pop(s);
            cout << value->data << " ";
            if (value->right != NULL){
                p = value->right;
            }
        }
        else
            break;
    }
}

void NLR(Node* root){
    if (root != NULL){
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(Node* root){
    if (root != NULL){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}

// Xóa cây
void delTree(Node* root){
    if (root == NULL)
        return;
    delTree(root->left);
    delTree(root->right);
    delete root;
}

void del_Tree(Node*& root){
    delTree(root);
    root = NULL;
}



int main(){
    Node* root;
    init(root);
    insertNode(root,9);
    insertNode(root,8);
    insertNode(root,10);
    
    LNR_ST(root);
    delNode(root,8);
    cout << endl;
    LNR_ST(root);

    del_Tree(root);
    return 0;
}