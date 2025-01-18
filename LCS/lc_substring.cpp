#include<bits/stdc++.h>
using namespace std;

int lc_substring(string x ,string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    
    int max_len=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                max_len=max(max_len,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return max_len;
}

int main(){
    string x; string y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    int ans=lc_substring(x,y,n,m);
    cout<<ans;
    return 0;
}