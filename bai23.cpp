#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong dong tien (n chan): ";
    cin >> n;

    vector<int> v(n+1);
    cout << "Nhap gia tri " << n << " dong tien:\n";
    for(int i = 1; i <= n; i++)
        cin >> v[i];

  
    vector<vector<int>> M(n+2, vector<int>(n+2, 0));

    
    for(int i = 1; i < n; i++)
        M[i][i+1] = max(v[i], v[i+1]);


    for(int len = 3; len < n+1; len++) {
        for(int i = 1; i + len <= n; i++) {
            int j = i + len;

            int pickLeft  = min(M[i+1][j-1], M[i+2][j]) + v[i];
            int pickRight = min(M[i+1][j-1], M[i][j-2]) + v[j];

            M[i][j] = max(pickLeft, pickRight);
        }
    }

    cout << "\nSo tien lon nhat nguoi A co the dat duoc: " << M[1][n] << endl;

    return 0;
}
