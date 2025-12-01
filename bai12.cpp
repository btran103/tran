#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& a, int left, int right) {
    if (left >= right) return;
    swap(a[left], a[right]);
    reverseArray(a, left + 1, right - 1);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    vector<int> a(n);
    cout << "Nhap day: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    reverseArray(a, 0, n - 1);

    cout << "Day sau khi dao nguoc: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}

