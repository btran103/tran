#include <iostream>
using namespace std;

struct Interval {
    int a, b;
};

// ki?m tra giao nhau
bool overlap(Interval x, Interval y) {
    return !(x.b <= y.a);
}

// d?m s? lu?ng không giao nhau theo th? t?
int countSet(Interval A[], int n) {
    Interval chosen[100];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < cnt; j++)
            if (overlap(chosen[j], A[i])) ok = false;
        if (ok)
            chosen[cnt++] = A[i];
    }
    return cnt;
}

// s?p x?p theo a
void sortByStart(Interval A[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j].a > A[j + 1].a) {
                Interval t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
}

// s?p x?p theo d? dài (b-a)
void sortByLength(Interval A[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((A[j].b - A[j].a) > (A[j + 1].b - A[j + 1].a)) {
                Interval t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
}

// s?p theo b
void sortByEnd(Interval A[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j].b > A[j + 1].b) {
                Interval t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    Interval a[100], A[100], B[100], C[100];

    for (int i = 0; i < n; i++)
        cin >> a[i].a >> a[i].b;

    for (int i = 0; i < n; i++)
        A[i] = B[i] = C[i] = a[i];

    sortByStart(A, n);
    cout << "\nTheo bat dau som nhat: " << countSet(A, n);

    sortByLength(B, n);
    cout << "\nTheo do dai nho nhat: " << countSet(B, n);

    sortByEnd(C, n);
    int last = -1000000000, cnt = 0;
    for (int i = 0; i < n; i++)
        if (C[i].a >= last) {
            cnt++;
            last = C[i].b;
        }

    cout << "\nTheo ket thuc som nhat: " << cnt << endl;

    return 0;
}

