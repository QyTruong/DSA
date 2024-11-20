#include<iostream>
#include <string.h>

using namespace std;

#define ll long long

ll edges[105][105][105];
ll vis[1005];
ll n, m;
void input(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges[c][a][b] = edges[c][b][a] = 1;
    }
}

void dfs(int color, int start){
    vis[start] = 1;
    for (int goal = 1; goal <= n; goal++){
        if (edges[color][start][goal] && !vis[goal])
            dfs(color, goal);
    }
}

void solve(){
    ll q; cin >> q;
    while (q--){
        ll u, v, res = 0; cin >> u >> v;
        for (int i = 1; i <= m; i++){
            memset(vis, 0, sizeof vis);
            dfs(i, u);
            if (vis[v]) res++;
        }
        cout << res << endl;
    }
}

int main(){
    input();
    solve();

    return 0;
}