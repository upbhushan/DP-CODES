#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {40, 20, 30, 10, 30};
    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Iterate over chain lengths (l is the length of the chain being considered)
    for (int i = n-1; i>=1; i--) { 
        for (int j = i+1; j < n; j++) {
            
            dp[i][j] = INT_MAX;

            // Compute minimum cost by splitting at different k
            for (int k = i; k < j; k++) {
                int c1 = dp[i][k];
                int c2 = dp[k + 1][j];
                int c3 = v[i - 1] * v[k] * v[j];
                dp[i][j] = min(dp[i][j], c1 + c2 + c3);
            }
        }
    }

    // The final result is stored in dp[1][n-1]
    cout << "Minimum cost of matrix chain multiplication is: " << dp[1][n - 1] << endl;

    return 0;
}
