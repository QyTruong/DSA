#include<iostream>

using namespace std;

int parent[1001];
int n;

void make_set(){
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int v){
    if (v == parent[v])
        return v;
    return parent[v] = (parent[v]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a; // a trước hay b trước đều được 
}

int main(){
    

    return 0;
}