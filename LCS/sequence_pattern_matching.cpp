#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string x; cin>>x;
    string y; cin>>y;
    int n=x.size();
    int m=y.size();
    int ans=0;
    if(n > m){
         ans=lcs(x,y,n,m);
         if(ans==m){
            cout<<"true"<<endl;
         }
         else{
            cout<<"false"<<endl;
         }
    }
    else{
        ans=lcs(y,x,m,n);
        if(ans==n){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    return 0;
    
}