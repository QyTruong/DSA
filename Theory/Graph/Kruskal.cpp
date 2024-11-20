#include<iostream>
#include<vector>

using namespace std;

struct Edge {
    int u, v, w;
};

void input(vector<Edge>& edges, int& n, int& m){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
}

void make_set(int*& parent, int n){
    parent = new int[n+1];
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int findParent(int parent[], int v){
    if (v == parent[v]) 
        return v;
    return parent[v] = findParent(parent, parent[v]);
}

bool unionVertex(int*& parent, int u, int v){
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (u == v) 
        return false;
    parent[u] = v;
    return true;
}

void sort(vector<Edge>& edges){
    int n = edges.size();
    for (int i = 1; i < n; i++){
        Edge x = edges[i];
        int j = i-1;
        while (j >= 0 && edges[j].w > x.w){
            edges[j+1] = edges[j];
            j--;
        }
        edges[j+1] = x;
    }
}

int kruskal(vector<Edge>& edges, int n, int m, int* parent){
    int d = 0;
    vector<Edge> mst;
    sort(edges);
    for (int i = 0; i < m; i++){
        if (mst.size() == n-1) break;
        if (unionVertex(parent, edges[i].u, edges[i].v)){
            mst.push_back(edges[i]);
            d += edges[i].w;
        }
    }
    cout << "MST:\n";
    for (auto m : mst){
        cout << m.u << " - " << m.v << " - " << m.w << endl;
    }
    return d;
}

int main(){
    int n,m;
    vector<Edge> edges;  
    int *parent = NULL;
    input(edges,n,m);
    make_set(parent, n);
    sort(edges);
    cout << kruskal(edges, n ,m ,parent);


    delete[] parent;
    return 0;
}