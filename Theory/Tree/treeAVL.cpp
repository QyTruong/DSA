#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left, * right;
    int height;
};

void init(Node*& root){
    root = NULL;
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

int getHeight(Node* root){
    if (root == NULL)
        return 0;
    return root->height;
}

Node* rightRotate(Node* root){
    // rotate right
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    // set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}

Node* leftRotate(Node* root){
    // rotate left
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    // set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}

Node* insertNode(Node* root, int x){
    // Insert
    Node* newNode = makeNode(x);
    if (root == NULL)
        return newNode;
    if (root->data > x)
        root->left = insertNode(root->left,x);
    else if (root->data < x)
        root->right = insertNode(root->right,x);
    else
        return root;
    
    // Set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check to rotate
    int balance = getHeight(root->left) - getHeight(root->right);

    // LL
    if (balance > 1 && root->left->data > x)
        return rightRotate(root);
    // RR
    if (balance < -1 && root->right->data < x)
        return leftRotate(root);
    // LR
    if (balance > 1 && root->left->data < x){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if (balance < -1 && root->right->data > x){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


void delNode(Node*& root, int x){
    if (root != NULL){
        Node* p = root;
        Node* parent = NULL;
        while (p != NULL && p->data != x){
            parent = p;
            if (p->data > x)
                p = p->left;
            else 
                p = p->right;
        }
        if (p != NULL){
            if (p->left != NULL && p->right != NULL){
                Node* tmp = p->right;
                while (tmp->left != NULL){
                    parent = tmp;
                    tmp = tmp->left;
                }
                p->data = tmp->data;
                p = tmp;
            }
            Node* t;
            if (p->left == NULL)
                t = p->right;
            else if (p->right == NULL)
                t = p->left;

            if (parent->data > p->data)
                parent->left = t;
            else if (parent->data < p->data)
                parent->right = t;       
            delete p;
        }
    }
}

void delTree(Node*& root){
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

void LNR(Node* root){
    if (root != NULL){
        LNR(root->left);
        cout << root->data << "(" << root->height << ")" << " ";
        LNR(root->right);
    }
}

int main(){
    Node* root;
    init(root);
    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = insertNode(root,4);
    root = insertNode(root,5);
    root = insertNode(root,6);
    LNR(root);
    cout << endl << getHeight(root) << endl;
    delNode(root,6);
    LNR(root);

    del_Tree(root);

    return 0;
}