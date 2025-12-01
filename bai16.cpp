#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Nhap so nguyen: ";
    cin >> n;

    queue<int> q;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            q.push(i);
            n /= i;
        }
    }

    cout << "Cac thua so nguyen to: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

