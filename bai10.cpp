#include <bits/stdc++.h>
using namespace std;

void decToBin(int n) {
    if (n == 0) return;
    decToBin(n / 2);
    cout << n % 2;
}

int binToDec(int n) {
    if (n == 0) return 0;
    return (n % 10) + 2 * binToDec(n / 10);
}

int main() {
    int choice;
    cout << "1. Thap phan -> Nhi phan\n";
    cout << "2. Nhi phan -> Thap phan\n";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Nhap so he 10: ";
        cin >> n;
        cout << "He 2: ";
        if (n == 0) cout << 0;
        else decToBin(n);
    } else {
        int n;
        cout << "Nhap so he 2: ";
        cin >> n;
        cout << "He 10: " << binToDec(n);
    }
    return 0;
}
