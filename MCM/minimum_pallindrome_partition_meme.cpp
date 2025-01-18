#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
bool ispallindrome(string x,int i,int j){
    while(i < j){
        if(x[i]!=x[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string x,int i ,int j){
    if(i >= j){
        return 0;
    }
    if(ispallindrome(x,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        // int res=1+solve(x,i,k)+solve(x,k+1,j);
        // ans=min(ans,res);
        // MORE OPTIMIZED
        int left,right;
        if(dp[i][k]!=-1){
            left=dp[i][k];
        }
        else{
            left=solve(x,i,k);
        }
        if(dp[k+1][j]!=-1){
            right=dp[k+1][j];
        }
        else{
            right=solve(x,k+1,j);
        }
        int res=1+left+right;
        ans=min(ans,res);

    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main(){
    string x; cin>>x;
    int n=x.size();
    dp.resize(n+1,vector<int> (n+1,-1));
    int ans=solve(x,0,n-1);
    cout<<ans<<endl;
}