#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void radixSort(vector<int>& a){
    int mx = *max_element(a.begin(), a.end());
    int exp = 1;
    
    while (mx / exp > 0){
        vector<int> bucket[10];
        for (int i = 0; i < a.size(); i++){
            int digit = (a[i] / exp) % 10;
            bucket[digit].push_back(a[i]);
        }
        int idx = 0;
        for (int i = 0; i < 10; i++){
            for (auto x : bucket[i]){
                a[idx++] = x;
            }
        }

        exp *= 10;
    }
}

void output(vector<int> a){
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
}

int main(){
    vector<int> a = {5,2,3,4,6,7,9,8,1};
    radixSort(a);
    output(a);

    return 0;
}