#include<iostream>
#include<vector>

using namespace std;

#define MAX 3001
bool used[MAX];
int n, m, start;
vector<vector<int>> edges;

struct Edge {
    int u, v, w;
};

void input(){
    cin >> n >> m;
    edges.resize(n+1, vector<int> (n+1, -1));
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges[u][v] = w;
        edges[v][u] = w;
    }
    cin >> start;
}

int prim(){
    input();
    vector<Edge> mst;
    int d = 0;
    used[start] = true;
    while (mst.size() < n-1){
        int min_edge = INT_MAX;
        int u, v;
        for (int i = 1; i <= n; i++){
            if (used[i]){
                for (int j = 1; j <= n; j++){
                    if (!used[j] && edges[i][j] != -1 && edges[i][j] < min_edge){
                        min_edge = edges[i][j];
                        u = i; v = j;
                    }
                }
            }
        }
        used[v] = true;
        mst.push_back({u,v,min_edge});
        d += min_edge;
    }
    cout << endl;
    for (auto x : mst){
        cout << x.u << " - " << x.v << " - " << x.w << endl;
    }
    return d;
}

int main(){
    cout << prim();

    return 0;
}

