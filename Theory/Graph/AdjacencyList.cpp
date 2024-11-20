#include<iostream>

using namespace std;

#define MAX 20

struct Node {
    int data;
    Node* next;
};

struct Graph {
    int n;
    Node* head[MAX];
};

Node* createNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices){
    Graph* newGraph = new Graph;
    newGraph->n = vertices;

    for (int i = 0; i < newGraph->n; i++){
        Node* tmp = createNode(i);
        newGraph->head[i] = tmp;
    }
    return newGraph;
}

void addEdge(Graph*& gh, int start, int end){
    Node* newNode = createNode(end);
    newNode->next = gh->head[start]->next;
    gh->head[start]->next = newNode;

    newNode = createNode(start);
    newNode->next = gh->head[end]->next;
    gh->head[end]->next = newNode;
}

void output(Graph* gh){
    for (int i = 0; i < gh->n; i++){
        Node* tmp = gh->head[i]->next;
        cout << "Dinh " << gh->head[i]->data+1 << ": ";
        while (tmp != NULL){
            cout << tmp->data+1 << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}


int main(){
    Graph* gh = createGraph(4);
    addEdge(gh, 0,1);
    addEdge(gh, 0,2);
    addEdge(gh, 0,3);
    addEdge(gh, 1,2);

    output(gh);

    return 0;
}