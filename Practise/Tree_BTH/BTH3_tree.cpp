#include<iostream>

using namespace std;

template<class T> 
struct Node {
    T data;
    Node *left, *right;
    int height;
};

template<class T>
void init(Node<T>* &t){
   Node<T>* root = NULL;
}



template<class T>
Node<T>* makeNode(T x){
    Node<T>* newNode = new Node<T>;
    newNode->data = x;
    newNode->left = NULL;
    newNode.right = NULL;
    return newNode;
}

template<class T>
int getHeight(Node<T>* root){
    if (root == NULL)
        return 0;
    return root->height;
}

template<class T>
Node<T>* rightRotate(Node<T>* root){
    Node<T>* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}

template<class T>
Node<T> leftRotate(Node<T>* root){
    Node<T> tmp = root->right;
    root->right = tmp.left;
    tmp.left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    tmp.height = 1 + max(getHeight(tmp.left), getHeight(tmp.right));

    return tmp;
}

template<class T>
Node<T> insertNode(Node<T>* root, T x){
    Node<T> newNode = makeNode(x);
    
}

template<class T>
int main(){
    Node<T>* root;
    init(root);

    return 0;
}