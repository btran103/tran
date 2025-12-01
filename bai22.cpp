#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, const vector<int>& w, const vector<int>& v) {
    vector<vector<int>> F(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            F[i][j] = F[i - 1][j];  
            if (j >= w[i]) {        
                int take = v[i] + F[i - 1][j - w[i]];
                if (take > F[i][j])
                    F[i][j] = take;
            }
        }
    }
    return F[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    cout << knapsack(n, W, w, v);
    return 0;
}
