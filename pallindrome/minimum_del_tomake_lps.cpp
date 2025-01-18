#include<bits/stdc++.h>
using namespace std;
int lps(string x,string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
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
    string a; cin>>a;
    string x=a;
    reverse(a.begin(),a.end());
    string y=a;
    int n=x.size();
    int ans=lps(x,y,n,n);
    cout<<(n-ans)<<endl;
    return 0;
}