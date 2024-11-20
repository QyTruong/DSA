#include<iostream>

/*
    Input:
    5 8
    ########
    #..#...#
    ####.#.#
    #..#...#
    ########    
    Output:
    3
*/

using namespace std;

char a[1005][1005];
int moveX[] = {-1, 1, 0, 0};
int moveY[] = {0, 0, -1, 1};
int n, m;
void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

void dfs(int i, int j){
    a[i][j] = '#';
    for (int k = 0; k < 4; k++){
        int x = i + moveX[k];
        int y = j + moveY[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.')
            dfs(x, y);
    }
}

int count_rooms(){
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (a[i][j] == '.'){
                dfs(i, j);
                cnt++;
            }
        }
    return cnt;
}

int main(){
    input();
    cout << count_rooms();
    

    return 0;
}