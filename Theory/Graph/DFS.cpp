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

vector<int> visited(n, 0);
vector<int> previous(n, -1);

void output(){
    stack<int> st;

    int idx = previous[goal];
    while (idx != start){
        st.push(idx + 1);
        idx = previous[idx];
    }
    st.push(start + 1);

    while (!st.empty()){
        cout << st.top() << " -> ";
        st.pop();
    }
    cout << goal + 1;
}

void dfs(){
    stack<int> st;
    st.push(start);

    visited[start] = 1;
    while (!st.empty()){
        int r = st.top();
        st.pop();

        visited[r] = 1;

        if (r == goal){
            output();
            return;
        }
        else {
            for (int i = 0; i < n; i++){
                if (visited[i] == 0 && a[r][i]){
                    st.push(i);
                    visited[i] = -1;
                    previous[i] = r;
                }
            }
        }
    }
}

int main(){
    dfs();

    return 0;
}