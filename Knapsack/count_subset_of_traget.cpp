// #include<bits/stdc++.h>
// using namespace std;

// int solve(){

// }
// int count_subset_sum(vector<int> &v,int n,int target_sum){
//     vector<vector<int>> dp(n+1,vector<int> (target_sum+1,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<target_sum;j++){
//             if(i==0) dp[i][j]=0;
//             if(j==0) dp[i][j]=1;
//         }
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=target_sum;j++){
//             if(v[i-1] <= j){
//                 dp[i][j]=dp[i-1][j] + dp[i-1][j-v[i-1]];
//             }
//             else{
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//     }
//     return dp[n][target_sum];
// }
// int main(){
//     vector<int> v={2,3,5,8,6,10};
//     int n=v.size();
//     int target_sum=10;
//     int x=count_subset_sum(v,n,target_sum);
//     cout<<x<<endl;
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n, int target_sum, vector<vector<int>> &dp) {
    if (target_sum == 0) return 1; 
    if (n == 0) return 0;          

    if (dp[n][target_sum] != -1) return dp[n][target_sum];

    if (v[n - 1] <= target_sum) {
        dp[n][target_sum] = solve(v, n - 1, target_sum, dp) +
                            solve(v, n - 1, target_sum - v[n - 1], dp);
    } else {
        dp[n][target_sum] = solve(v, n - 1, target_sum, dp);
    }

    return dp[n][target_sum];
}

int count_subset_sum(vector<int> &v, int n, int target_sum) {
    vector<vector<int>> dp(n + 1, vector<int>(target_sum + 1, -1));
    return solve(v, n, target_sum, dp);
}

int main() {
    vector<int> v = {2, 3, 5, 8, 6, 10};
    int n = v.size();
    int target_sum = 10;
    int result = count_subset_sum(v, n, target_sum);
    cout << result << endl; 
    return 0;
}
