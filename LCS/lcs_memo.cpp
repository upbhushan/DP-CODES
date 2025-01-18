#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    else if(x[n-1]==y[m-1]){
        return dp[n][m]=1+lcs(x,y,n-1,m-1);
    }
    else{
        return dp[n][m]=max(lcs(x,y,n,m-1) , lcs(x,y,n-1,m));
    }
    return dp[n][m];
}

int main(){
    string x ;string y; 
    cin>>x>>y;
    int n=x.size() ; int m=y.size();
    dp.resize(n+1,vector<int> (m+1,-1));
    int ans=lcs(x,y,n,m);
    cout<<ans<<endl;
    return 0;
}