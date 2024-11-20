/*
    Đếm số thành phần liên thông
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> adj[10005];
int visited[10005];


void dfs(int u){
    visited[u] = 1;
    for (auto x : adj[u]){
        if (!visited[x])
            dfs(x);
    }
}

int cnt = 0;
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            cnt++;
        }
    }
}

int main(){
    solve();
    cout << cnt;

    return 0;
}