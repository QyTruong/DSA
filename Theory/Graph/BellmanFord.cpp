#include<iostream>
#include<vector>
#include<queue>
#include <string.h>

using namespace std;


// 5 5
// 1 2 5
// 2 3 1
// 2 4 2
// 3 5 1
// 5 4 -1
// res: 0 5 6 6 7 

void bellman(int u, vector<pair<int, pair<int, int>>> edges, int distance[], bool inqueue[]){
    queue<int> q;
    distance[u] = 0;
    q.push(u);
    inqueue[u] = true;

    while (!q.empty()){
        u = q.front();
        inqueue[u] = false;
        q.pop();
       
        for (auto e : edges){
            if (e.first == u){
                int v = e.second.first;
                int w = e.second.second;
                if (distance[v] > distance[u] + w){
                    distance[v] = distance[u] + w;
                    if (!inqueue[v]){
                        q.push(v);
                        inqueue[v] = true;
                    }
                }
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    bool inqueue[n+1];
    int distance[n+1];
    for (int i = 1; i <= n; i++){
        distance[i] = INT_MAX;
    }
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v , w}});
    }

    bellman(1, edges, distance, inqueue);
    for (int i = 1; i <= n; i++){
        cout << distance[i] << " ";
    }

    return 0;
}
