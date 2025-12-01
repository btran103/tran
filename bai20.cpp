#include <iostream>
#include <cmath>
using namespace std;

// a) Ch?n c?p có sai khác nh? nh?t tru?c
void greedy1(int h[], int s[], int n) {
    bool usedP[100], usedS[100];
    for (int i = 0; i < n; i++) usedP[i] = usedS[i] = false;

    cout << "\nThuat toan 1:\n";

    for (int k = 0; k < n; k++) {
        int bestP = -1, bestS = -1;
        int bestDiff = 1000000000;

        for (int i = 0; i < n; i++)
            if (!usedP[i])
                for (int j = 0; j < n; j++)
                    if (!usedS[j]) {
                        int diff = abs(h[i] - s[j]);
                        if (diff < bestDiff) {
                            bestDiff = diff;
                            bestP = i;
                            bestS = j;
                        }
                    }

        usedP[bestP] = true;
        usedS[bestS] = true;

        cout << "Nguoi " << bestP + 1 << " -> Giay " << bestS + 1 << endl;
    }
}

// hàm s?p x?p n?i b?t dành cho BIT++
void bubbleSort(int a[], int idx[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                // d?i giá tr?
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;

                // d?i index
                int t2 = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = t2;
            }
}

// b) Ghép theo s?p x?p
void greedy2(int h[], int s[], int n) {
    int ph[100], ps[100];
    int H[100], S[100];

    for (int i = 0; i < n; i++) {
        ph[i] = ps[i] = i;
        H[i] = h[i];
        S[i] = s[i];
    }

    bubbleSort(H, ph, n);
    bubbleSort(S, ps, n);

    cout << "\nThuat toan 2:\n";
    for (int i = 0; i < n; i++)
        cout << "Nguoi " << ph[i] + 1 << " -> Giay " << ps[i] + 1 << endl;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int h[100], s[100];

    cout << "Nhap chieu cao nguoi:\n";
    for (int i = 0; i < n; i++) cin >> h[i];

    cout << "Nhap chieu cao giay:\n";
    for (int i = 0; i < n; i++) cin >> s[i];

    greedy1(h, s, n);
    greedy2(h, s, n);

    return 0;
}

