#include<bits/stdc++.h>
using namespace std;
int lcs_topdown(string x, string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string x; string y;
    cin>>x>>y;
    int ans=lcs_topdown(x,y,x.size(),y.size());
    cout<<ans<<endl;
    return 0;
}