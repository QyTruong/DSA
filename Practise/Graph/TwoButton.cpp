#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[20005];
int dp[20005];
int n, m;

void bfs(){
    dp[n] = 1;
    queue<int> q;
    q.push(n);

    while (!q.empty()){
        int u = q.front(); q.pop();

        for (int v : adj[u]){
            if (!dp[v]){
                dp[v] = dp[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= 10005; i++){
        adj[i].push_back(i - 1);
        adj[i].push_back(i * 2);
    }
    bfs();
    cout << dp[m] - 1;
}

int main(){
    solve();

    return 0;
}