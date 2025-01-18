#include<bits/stdc++.h>
using namespace std;
void subset_sum(vector<int> &v,int n,int target_sum){
    vector<vector<bool>> dp( n+1,vector<bool> (target_sum+1,false));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target_sum+1;j++){
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     dp[i][0] = true;
    // }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target_sum+1;j++){
            if(v[i-1]<= j){
                dp[i][j]=dp[i][j-v[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    cout<< dp[n][target_sum];
}

int main(){
    vector<int> v={2,3,7,8,10};
    int n=v.size();
    int target_sum=11;
    subset_sum(v,n,target_sum);
    return 0;
}

