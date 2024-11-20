/*
    Có 3 loại mạng chính: bus, star và ring
    Bus: được kết nối thông qua 1 cáp chung
    Ring: kết nối thành 1 vòng tròn (thường là n > 3)
    Star: 1 nút trum tâm được kết nối với tất cả các nút khác trong mạng

    Đề bài: xác định loại mạng đã cho. Nếu không thể xác định
    thì in ra "unknown topology"
*/

#include<iostream>

using namespace std;
int adj[1000005] = {0};
int n, m;

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x]++; adj[y]++;
    }
    int exp1 = 0, exp2 = 0, exp3 = 0;
    for (int i = 1; i <= n; i++){
        if (adj[i] == 1) exp1++;
        else if (adj[i] == 2) exp2++;
        else exp3++;
    }
    if (exp1 == n-1 && exp3 != 0) cout << "star topology";
    else if (exp2 == n-2 && exp1 == 2) cout << "bus topology";
    else if (exp2 == n && exp3 == 0 && exp1 == 0) cout << "ring topology";
    else cout << "unknown topology";
}

int main(){
    solve();
    return 0;
}