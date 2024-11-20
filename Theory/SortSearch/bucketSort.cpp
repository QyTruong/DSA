#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void BucketSort(float a[], int n){

 vector<float> b[n];


 for (int i = 0; i < n; i++) { 
    int bi = n * a[i]; 
    b[bi].push_back(a[i]); 
}
    

    
 for (int i = 0; i < n; i++) { 
    insertionSort(b[i]);
 }
 //nối các buckets lại với nhau
 int index = 0; 
for (int i = 0; i < n; i++) { 
    for (auto x : b[i]) { 
        a[index++] = x; 
    }
 }
 }

int main(){
    float a[] = {0.1,0.15,0.1,0.1,0.9};
    int n = sizeof(a) / sizeof(a[0]);
    BucketSort(a,n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}