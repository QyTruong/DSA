#include<iostream>
#include<queue>

/*  
    Ý tưởng giống với Pacman
    Input:
    5 6
    B...*.
    ..*...
    .**.*.
    ..***.
    *..*.C
    Output:
    9
*/

#define pr pair<int,int> 
using namespace std;

int moveX[] = {-1, 1, 0, 0};
int moveY[] = {0, 0, -1, 1};

char a[1005][1005];
int vis[1005][1005];
int d[1005][1005];
int n, m;
pr start, goal;

void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'B') start = {i,j};
            if (a[i][j] == 'C') goal = {i,j};
        }
    }
}

void bfs(){
    queue<pr> q;
    q.push(start);
    d[start.first][start.second] = 0;
    vis[start.first][start.second] = 1;

    while (!q.empty()){
        pr r = q.front(); q.pop();

        for (int i = 0; i < 4; i++){
            int x = r.first + moveX[i];
            int y = r.second + moveY[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && a[x][y] != '*'){
                d[x][y] = d[r.first][r.second] + 1;
                q.push({x,y});
                if (a[x][y] == 'C') return;
                vis[x][y] = 1;
            }
        }
    }
}

int main(){
    input();
    bfs();
    cout << d[goal.first][goal.second]; 

    return 0;
}