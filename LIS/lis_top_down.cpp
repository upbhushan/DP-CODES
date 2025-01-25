#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &v) {
    int n = v.size();
    vector<int> dp(n, 1); // Initialize DP array with 1 (minimum LIS length is 1)

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The answer is the maximum value in the DP table
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << lis(v) << endl;
    return 0;
}
