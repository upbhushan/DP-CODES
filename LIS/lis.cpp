#include <bits/stdc++.h>
using namespace std;

int lis_helper(int idx, int prev_idx, int n, vector<int> &v) {
    if (idx == n) return 0; 

    // Exclude the current element
    int exclude = lis_helper(idx + 1, prev_idx, n, v);

    // Include the current element if it's greater than the last included element
    int include = 0;
    if (prev_idx == -1 || v[idx] > v[prev_idx]) {
        include = 1 + lis_helper(idx + 1, idx, n, v);
    }

    return max(include, exclude);
}

int lis(vector<int> &v) {
    int n = v.size();
    return lis_helper(0, -1, n, v); 
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Length of LIS: " << lis(v) << endl;
    return 0;
}
