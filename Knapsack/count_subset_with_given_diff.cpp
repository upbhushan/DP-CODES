#include<bits/stdc++.h>
using namespace std;
int count_of_subset_target(vector<int> &v ,int n,int target_sum){
    vector<vector<int>> dp(n+1,vector<int>(target_sum+1,0));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target_sum+1;j++){
            if(i==0) dp[i][j]=0;
            if(j==0) dp[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target_sum+1;j++){
            if(v[i-1] <= j){
                dp[i][j]=dp[i-1][j] + dp[i-1][j-v[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target_sum];
}
int main(){
    vector<int> v={1,1,2,3};
    int n=v.size();
    int diff=1;
    int sum=accumulate(v.begin(),v.end(),0);
    // s1-s2=1
    //s1+s2=s
    //s1=(sum+diff)/2
    if ((sum + diff) % 2 != 0) {
        cout << "No valid partition exists" << endl;
        return 0;
    }
    int target_sum=(sum+diff)/2;
    int ans=count_of_subset_target(v,n,target_sum);
    cout<<ans;
    return 0;
}