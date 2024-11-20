#include<iostream>

/*
    Input: 
    8 7
    4 3 2 2 1 0 1
    3 3 3 2 1 0 1
    2 2 2 2 1 0 0
    2 1 1 1 1 0 0
    1 1 0 0 0 1 0
    0 0 0 1 1 1 0
    0 1 2 2 1 1 0
    0 1 1 1 2 1 0
    Output:
    3
*/

using namespace std;

int moveX[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int moveY[] = {0, 0, -1, 1, 1, -1, -1, 1};

int a[1005][1005];
int visited[1005][1005];
int n, m;
void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

int ok;
void dfs(int i, int j){
    visited[i][j] = 1;
    for (int k = 0; k < 8; k++){
        int x = i + moveX[k];
        int y = j + moveY[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m){
            if (a[i][j] < a[x][y]) ok = 0;
            if (!visited[x][y] && a[x][y] == a[i][j])
                dfs(x, y);
        }
    }
}

int findPeek(){
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!visited[i][j]){
                ok = 1;
                dfs(i, j);
                if (ok) res++;
            }
        }
    }
    return res;
}

int main(){
    input();
    cout << findPeek();

    return 0;
}