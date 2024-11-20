#include<iostream>
#include<bitset>

using namespace std;

/*

    x   y   &   |   ^   
    0   0   0   0   0   
    0   1   0   1   1
    1   0   0   1   1
    1   1   1   1   0   

    &: min
    |: max
    ^: cộng không nhớ
    ~ hay !: đảo bit 0 -> 1 hay 1 -> 0

    n + ~n = -1 (luôn đúng)

    Kiểm tra chẵn lẻ (n&1)
*/

/* 
    # Tắt, bật, đảo bit tại vị trí i
    - Tắt bit: (n & ~(1 << i))
    - Bật bit: (n | (1 << i))
    - Đảo bit: (n ^ (1 << i))
*/

/*
    n & (n-1): chuyển bit cuối (1) của n trở về sau sang 0 (Hay dùng trong Fenwich Tree)
    n | (n-1): chuyển bit cuôi (1) của n trở về sau sang 1
    n ^ (n-1): chuyển các bit trước bit cuối (1) của n sang 0

    ex:
        01011000        01011000        01011000        01011000        
    &               |               ^               ~
        01010111        01010111        01010111        01010111      
    ------------    ------------    ------------    ------------
        01010000        01011111        00001111        10100111
*/

/*
    Độ ưu tiên:
    () + - * /   -->  & | ^ ~   -->  || &&
*/

int main(){
    int a = 8;
    // right shift a / (2^k) (a >> k)
    cout << (a>>5) << endl;
    
    // left shift a x (2^k) (a << k)
    cout << (a<<5) << endl;

    // bitset <> () : biểu diễn số lượng bit của 1 số thập phân -> nhị phân
    cout << bitset<32>(5) << endl; // số 5 ở dạng 32 bit

    // __builtin_popcount(): đếm số lượng bit 1 của 1 số
    // __builtin_popcountll(): đếm được 64 bit
    cout << __builtin_popcount((15)) << endl; // Mã nhị phân của 15: 1111

    // __builtin_ctz(): đếm số bit 0 phải -> trải đến khi gặp bit 1 (count tail zero)
    // __builtin_clz(): đếm số bit 0 trái -> phải đến khi gặp bit 1 (count leading zero)
    cout << __builtin_ctz(8) << endl;
    cout << __builtin_clz(8) << endl;

    

    return 0;
}