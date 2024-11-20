#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left, *right;
    int height;
};

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void init(Node*& root){
    root = NULL;
}

int getHeight(Node* root){
    if (root == NULL)
        return 0;
    return root->height;
}

Node* rotateRight(Node* root){
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}

Node* rotateLeft(Node* root){
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}
          

Node* insertNode(Node* root, int x){
    if (root == NULL){
        return makeNode(x);
    }
    if (root->data > x)
        root->left = insertNode(root->left,x);
    else if (root->data < x)
        root->right = insertNode(root->right,x);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getHeight(root->left) - getHeight(root->right);

    if (balance > 1 && root->left->data > x)
        return rotateRight(root);
    if (balance < -1 && root->right->data < x)
        return rotateLeft(root);
    if (balance > 1 && root->left->data < x){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && root->right->data > x){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void delTree(Node*& root){
    if (root == NULL)
        return;
    delTree(root->left);
    delTree(root->right);
    delete root;
}

void releaseTree(Node*& root){
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

void NLR(Node* root){
    if (root != NULL){
        cout << root->data << "(" << root->height << ")" << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(Node* root){
    if (root != NULL){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << "(" << root->height << ")" << " ";
    }
}

int countNode(Node* root){
    if (root == NULL)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimeNode(Node* root){
    if (root == NULL)
        return 0;
    if (isPrime(root->data))
        return 1 + countPrimeNode(root->left) + countPrimeNode(root->right);
    return countPrimeNode(root->left) + countPrimeNode(root->right);
}

int countTwoSubNode(Node* root){
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right != NULL)
        return 1 + countTwoSubNode(root->left) + countTwoSubNode(root->right);
    return countTwoSubNode(root->left) + countTwoSubNode(root->right);
}

int sumNode(Node* root){
    if (root == NULL){
        return 0;
    }
    return root->data + sumNode(root->left) + sumNode(root->right);
}

double avgNode(Node* root){
    if (root == NULL)
        return 0;
    return (double)sumNode(root)/countNode(root);
}

Node* findMaxNode(Node* root){
    if (root != NULL){
        while (root->right != NULL)
        {
            root = root->right;
        }
    }
    return root;
}

Node* searchNode(Node* root, int key){
    if (root != NULL){
        while(root != NULL){
            if (root->data == key)
                return root;
            else if (root->data > key)
                root = root->left;
            else
                root = root->right;
        }
    }
    return NULL;
}

void swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

int countEdgeAtoB(Node* root, int a, int b){
    Node* start = searchNode(root,a);
    Node* end = searchNode(root,b);
    // if (start != NULL){
    //     int cnt = 0;
    //     while (start != NULL){
    //         if (start->data == b)
    //             return cnt;
    //         else if (start->data > b)
    //             start = start->left;
    //         else
    //             start = start->right;
    //         cnt++;
    //     }
    //     return cnt;
    // }
    // return -1;
    
}

int main(){
    Node* tree;
    init(tree);
    tree = insertNode(tree,2);
    tree = insertNode(tree,5);
    tree = insertNode(tree,6);
    tree = insertNode(tree,7);
    tree = insertNode(tree,8);
    tree = insertNode(tree,9);
    tree = insertNode(tree,11);

    cout << "LNR: "; LNR(tree);
    cout << endl << "NLR: "; NLR(tree);
    cout << endl << "LRN: "; LRN(tree);
    //cout << endl << countNode(tree);
    //cout << endl << countPrimeNode(tree);
    cout << endl << countTwoSubNode(tree);
    cout << endl << avgNode(tree);
    cout << endl << findMaxNode(tree)->data;
    cout << endl << countEdgeAtoB(tree, 2, 6);

    cout << endl << "LNR: "; LNR(tree);

    releaseTree(tree);
    return 0;
}