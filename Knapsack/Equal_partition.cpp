#include<bits/stdc++.h>
using namespace std;
void subset_sum(vector<int> &v,int n,int target_sum){
    vector<vector<bool>> dp(n+1,vector<bool> (target_sum+1,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<target_sum;j++){
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target_sum;j++){
            if(v[i-1] <= j){
                dp[i][j]=dp[i-1][j] || dp[i][j-v[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][target_sum]==1) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return ;
}
int main(){
    vector<int> v={4,1,7,12};
    int n=v.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    if(sum%2!=0){
        cout<<"false"<<endl;
    }
    else{
        subset_sum(v,n,sum/2);;
    }
    return 0;
}