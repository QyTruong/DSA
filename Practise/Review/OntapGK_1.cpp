#include<iostream>
#include<stack>

#define M 100

using namespace std;

void init(int *&a, int n){
    a = new int [n];
}

void input(int *&a, int& n){
    do {
        cout << "Nhap so phan tu: "; cin >> n;
        if (n <= 0 || n > M)
            cout << "Vui long nhap lai!\n";
    } while (n <= 0 || n > M);

    init(a,n);
    printf("Nhap danh sach %d phan tu:\n", n);
    for (int i = 0; i < n; i++){
        printf("a[%d]: ", i+1);
        cin >> a[i];
    }
}

void output(int *a, int n){
    cout << "\n================\n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int search(int *a, int n, int x){
    for (int i = 0; i < n; i++){
        if (a[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int *a, int n, int x){
    int left = 0, right = n-1, mid;
    while (left <= right){
        mid = (left+right)/2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}


void pushBack(int *&a, int &n, int x){
    if (n < M){
        a[n++] = x;
    }
    return;
}

void popBack(int *&a, int &n){
    if(n > 0)
        n--;
    return;
}

void delAtPos(int *&a, int &n, int pos){
    for (int i = pos+1; i < n; i++){
        a[i-1] = a[i];
    }
    n--;
}

void insertAtPos(int *&a, int &n, int x,int pos){
    if (a == NULL){
        n = 1;
        init(a,n);
        a[0] = x;
    }
    else {
        for (int i = n; i >= pos; i--){
            a[i] = a[i-1];
        }
        a[pos] = x;
        n++;
    }
    return;
}

int findMax(int *a, int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++){
        if (a[i] >= max)
            max = a[i];
    }
    return max;
}

int findSecondMax(int *a, int n){
    int max1 = findMax(a,n);
    int max2 = INT_MIN;
    for (int i = 0; i < n; i++){
        if (a[i] > max2 && a[i] != max1)
            max2 = a[i];
    }
    return max2;
}

void selectionSort(int *&a, int n){
    for (int i = 0; i < n; i++){
        int max = i;
        for (int j = i+1; j < n; j++){
            if (a[j] > a[max])
                max = j;
        }
        swap(a[i], a[max]);
    }
}

void insertionSort(int *&a, int n){
    for (int i = 1; i < n; i++){
        int x = a[i];
        int j = i-1;
        while (j >= 0 && x >= a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void bubbleSort(int *&a, int n){
    for (int i = 0; i < n; i++){
        for (int j = n-1; j > i; j--){
            if (a[i] < a[j])
                swap(a[i],a[j]);
        }
    }
}

void interchangeSort(int *&a, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] < a[j])
                swap(a[i], a[j]);
        }
    }
}

void heapify(int *&a, int n, int i){
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;

    if (l < n && a[l] < a[largest])
        largest = l;
    if (r < n && a[r] < a[largest])
        largest = r;
    
    if (largest != i){
        swap(a[largest], a[i]);
        heapify(a,n,largest);
    }
}

void heapSort(int *&a, int n){
    for (int i = n/2-1; i >= 0; i--){
        heapify(a,n,i);
    }
    for (int i = n-1; i >= 0; i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void quickSort_Rec(int *&a, int left, int right){
    int l = left;
    int r = right;
    int pivot = a[(left+right)/2];
    
    while (l < r){
        while (a[l] > pivot)
            l++;
        while (a[r] < pivot)
            r--;
        if (l <= r){
            swap(a[l], a[r]);
            l++; r--;
        }
    }

    if (left < r){
        quickSort_Rec(a,left, r);
    }
    if (l < right){
        quickSort_Rec(a,l, right);
    }
}

int partition(int *&a, int left, int right){
    int pivot = a[right];
    int i = left;

    for (int j = left; j < right; j++){
        if (a[j] > pivot){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i;
}

void quickSort_nonRec(int *&a, int left, int right){
    stack<int> st;
    st.push(left);
    st.push(right);

    while (!st.empty()){
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();

        int pivot = partition(a, left, right);

        if (pivot-1 > left){
            st.push(left);
            st.push(pivot-1);
        }
        if (pivot+1 < right){
            st.push(pivot+1);
            st.push(right);
        }
    }
}

void merge(int *&a, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int* L = new int [n1];
    int* R = new int [n2];

    for (int i = 0; i < n1; i++){
        L[i] = a[l+i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = a[m+1+i];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[l++] = R[j++];
        }
        else {
            a[l++] = L[i++];
        }
    }

    while (i < n1){
        a[l++] = L[i++];
    }
    while (j < n2){
        a[l++] = R[j++];
    }

    L = nullptr;
    R = nullptr;
    delete[]L;
    delete[]R;
    
}

void mergeSort(int *&a, int left, int right){
    if (left >= right)
        return;
    int mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a,left,mid,right);
}

void freeList(int *&a){
    delete[]a;
    a = nullptr;
}

int main(){
    int *a = NULL;
    int n;

    input(a,n);
    output(a,n);

    insertAtPos(a,n,23,0);
    mergeSort(a,0,n-1);
    output(a,n);


    freeList(a);

    return 0;
}