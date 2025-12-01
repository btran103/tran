#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int a[], int l, int m, int r) {
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = m; i >= l; i--) {
        sum += a[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;

    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArray(int a[], int l, int r) {
    if (l == r)
        return a[l];

    int m = (l + r) / 2;

    int left_max  = maxSubArray(a, l, m);
    int right_max = maxSubArray(a, m + 1, r);
    int cross_max = maxCrossingSum(a, l, m, r);

    return max(max(left_max, right_max), cross_max);
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    int a[1000];
    cout << "Nhap day so: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = maxSubArray(a, 0, n - 1);

    cout << "Tong day con lien tuc lon nhat: " << result << endl;

    return 0;
}

