#include <bits/stdc++.h>
using namespace std;

int timMax(int a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    int max1 = timMax(a, l, m);
    int max2 = timMax(a, m + 1, r);
    return (max1 > max2) ? max1 : max2;
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }

    int kq = timMax(a, 0, n - 1);
    cout << "\nSo lon nhat trong day la: " << kq << endl;

    return 0;
}
