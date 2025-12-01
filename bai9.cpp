#include <bits/stdc++.h>
using namespace std;

double power(double a, int n) {
    if (n == 0) return 1;
    if (n > 0) return a * power(a, n - 1);
    return 1 / power(a, -n);
}

int main() {
    double a; int n;
    cout << "Nhap a va n: ";
    cin >> a >> n;
    cout << a << "^" << n << " = " << power(a, n);
    return 0;
}

