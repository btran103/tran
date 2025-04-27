#include <iostream>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        if ((a % 2 == 0 && b % 2 != 0)) return false;
        if ((a % 2 != 0 && b % 2 == 0)) return true;
        return a < b;
    }
};

int main() {
    int arr[6] = {10, 2, 4, 8, 6, 9};

    priority_queue<int, vector<int>, Compare> pq;
    for (int i = 0; i < 6; i++) {
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pqIncrease;
    for (int i = 0; i < 6; i++) {
        pqIncrease.push(arr[i]);
    }
    while (!pqIncrease.empty()) {
        cout << pqIncrease.top() << ' ';
        pqIncrease.pop();
    }
    cout << endl;

    return 0;
}

