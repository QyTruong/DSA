#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

vector<vector<int>> a = {
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0}, // 1
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, // 6
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, // 7
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int n = 12;
int start = 0;
int goal = 11;
vector<int> visited (n, 0); // 0: Chưa thăm, 1: Đã thăm, -1: Đã bỏ qua queue
vector<int> previous (n, -1);

void output(){
    stack<int> t;
    t.push(goal + 1);
    int idx = previous[goal];
    while (idx != start){
        t.push(idx + 1);
        idx = previous[idx];
    }
    t.push(start + 1);
    while (!t.empty()){
        cout << t.top();
        t.pop();
        if (!t.empty()){
            cout << " -> ";
        }
    }
}

void bfs(){
    queue<int> q;
    q.push(start);

    while (!q.empty()){
        int r = q.front();
        q.pop();
        visited[r] = 1;

        if (r == goal){
            output();
            return;
        }
        else {
            for (int i = 0; i < n; i++){
                if (a[r][i] && visited[i] == 0){
                    q.push(i);
                    visited[i] = -1;
                    previous[i] = r;
                }
            }
        }
    }
} 


int main(){
    bfs();

    return 0;
}