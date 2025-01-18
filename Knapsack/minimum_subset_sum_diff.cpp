#include<bits/stdc++.h>
using namespace std;

vector<bool> solve(vector<int> &v, int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // Initialize first column as true (sum = 0)
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (v[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<bool> res(sum / 2 + 1);
    for (int j = 0; j <= sum / 2; j++) {
        res[j] = dp[n][j]; // Store results for sums from 0 to sum / 2
    }

    return res;
}

int main() {
    vector<int> v = {5,6,1};
    int n = v.size();
    int sum = accumulate(v.begin(), v.end(), 0); // Calculate sum of elements

    vector<bool> possible_sums = solve(v, n, sum);

    int answer = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (possible_sums[i]) {
            answer = min(answer, sum - 2 * i); // Minimize the difference
        }
    }

    cout << answer << endl;
    return 0;
}
