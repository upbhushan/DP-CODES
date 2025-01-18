#include<bits/stdc++.h>
using namespace std;
int f(int idx,int w,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
    if(idx==0){
        if(wt[0] <= w) return val[0];
        return 0;
    }
    if(dp[idx][w]!=-1) return dp[idx][w];

    int nottake=0+f(idx-1,w,wt,val,dp);
    int take=-1e8;
    if(wt[idx] <= w){
        take=val[idx]+f(idx-1,w-wt[idx],wt,val,dp);
    }
    return dp[idx][w]=max(take,nottake);
}
int main(){
    vector<int> weights={2,3,4,5};
    vector<int> values={3,4,5,6};
    int n= weights.size();
    int capacity=5;
    // vector<vector<int>> dp(n+1,vector<int> (capacity+1,0));
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=capacity;j++){
    //         if(i==0 || j==0){
    //             dp[i][j]=0;
    //         }
    //         else if(weights[i-1] <= j){
    //             dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
    //         }
    //         else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    // cout<<"Maximum value:"<<dp[n][capacity];
    vector<vector<int>> dp(n,vector<int> (capacity+1,-1));
    cout<<f(n-1,capacity,weights,values,dp);
    return  0;
}





