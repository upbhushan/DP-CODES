#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> lcs_topdown(string x, string y,int n,int m){
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
    return dp;
}
string solve(string x,string y,int n,int m,vector<vector<int>> &ans){
    int i=n,j=m;
    string com="";
    while(i > 0 || j > 0){
        if(x[i-1]==y[i-1]){
            com+=x[i-1];
            i--;
            j--;
        }
        else{
            if(ans[i][j-1] > ans[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(com.begin(),com.end());
    return com;
}

int main(){
    string x; string y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    vector<vector<int>> ans=lcs_topdown(x,y,n,m);
    string res=solve(x,y,n,m,ans);
    cout<<res<<endl;
    return 0;
}