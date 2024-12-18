#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<fstream>

/*  (6 vertexes - 8 edges - start: 1 - goal: 5)
    (u:1 - v:2 - w:7)
    (...............)
    (u:5 - v:6 - w: 5)
    Test case:
        6 8 1 
        1 2 7
        1 3 12
        2 3 2
        2 4 9
        3 5 10
        4 6 1
        5 4 4
        5 6 5
    Result:
        0 7 9 16 19 17 
*/

#define MAX 20
#define inf 1e9

using namespace std;

vector<pair<int, int>> adj[MAX];
int previous[MAX];
int n, m, s, g;

void input(){
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

void dijkstra(int start){
    vector<int> d(n+1, inf);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()){
        auto r = pq.top(); pq.pop();
        int u = r.second;
        int kc = r.first;

        if (kc > d[u])
            continue;
        
        for (auto x : adj[u]){
            int v = x.first;
            int w = x.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
                previous[v] = u;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
} 

// struct Edge {
//     int u, v;
//     int w;
// };

// struct Node {
//     int u;
//     int w; // tong trong so nho nhat di tu start -> u
// };

// vector<vector<Edge>> edges;
// vector<int> parent;
// vector<bool> visited;
// vector<int> d;
// int n, m, start, goal;

// void readData(){
//     ifstream f;
//     f.open("shortestpath.txt");

//     f >> n >> m;
//     f >> start >> goal;
//     edges.resize(n + 1);

//     for (int i = 0; i < m; i++){
//         Edge e;
//         f >> e.u >> e.v >> e.w;
//         edges[e.u].push_back(e);
//     }
// }

// void initData(){
//     readData();

//     parent.resize(n + 1, -1);
//     visited.resize(n + 1, false);

//     d.resize(n + 1, INT_MAX);
//     d[start] = 0;
// }

// void dijkstra_1(){
//     auto cmp = [](Node n1, Node n2){return n1.w > n2.w;};
//     priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);

//     q.push({start, d[start]});

//     while (!q.empty()){
//         Node x = q.top(); q.pop();
//         int u = x.u;
//         if (visited[u] == false){
//             visited[u] = true;
//         }
//         for (auto e: edges[u]){
//             int v = e.u;
//             if (d[v] > d[u] + e.w){
//                 d[v] = d[u] + e.w;
//                 parent[v] = u;
//             }
//         }
//     }
// }

int main(){
    input();
    dijkstra(1);

    return 0;
}



