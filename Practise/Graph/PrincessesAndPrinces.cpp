#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define maxN 100005

int main(){
    int t = 1; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++){
            int k; cin >> k;
            while (k--){
                int j; cin >> j; j--;
                if (!a[i] && !b[j]){
                    a[i] = b[j] = 1;
                }
            }
        }
        int x = find(a.begin(), a.end(), 0) - a.begin();
        int y = find(b.begin(), b.end(), 0) - b.begin();
        if (x == n) cout << "OPTIMAL\n";
        else cout << "IMPROVE\n" << x+1 << " " << y+1 << endl;
    }

    return 0;
}