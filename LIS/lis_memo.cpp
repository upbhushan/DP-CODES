#include <bits/stdc++.h>
using namespace std;

int lis_helper(int idx, int prev_idx, int n, vector<int> &v, vector<vector<int>> &dp) {
    if (idx == n) return 0;

    // Memoization check
    if (dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];

    // Exclude the current element
    int exclude = lis_helper(idx + 1, prev_idx, n, v, dp);

    // Include the current element if it forms an increasing sequence
    int include = 0;
    if (prev_idx == -1 || v[idx] > v[prev_idx]) {
        include = 1 + lis_helper(idx + 1, idx, n, v, dp);
    }

    // Store the result in the DP table and return
    return dp[idx][prev_idx + 1] = max(include, exclude);
}

int lis(vector<int> &v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // DP table
    return lis_helper(0, -1, n, v, dp);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Length of LIS: " << lis(v) << endl;
    return 0;
}
