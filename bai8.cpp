#include <bits/stdc++.h>
using namespace std;


int sumSquares(int n) {
    if (n == 1) return 1;
    return n * n + sumSquares(n - 1);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Tong binh phuong 1 -> " << n << " = " << sumSquares(n);
    return 0;
}

