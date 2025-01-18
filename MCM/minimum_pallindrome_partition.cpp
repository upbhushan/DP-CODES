#include<bits/stdc++.h>
using namespace std;

bool ispallindrome(string s,int i,int j){
    while(i < j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string x, int i,int j){
    if(i >= j){
        return 0;
    }
    if(ispallindrome(x,i,j)){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int res=1+solve(x,i,k)+solve(x,k+1,j);
        ans=min(ans,res);
    }
    return ans;
}
int main(){
    string x; cin>>x;
    int n=x.size();
    int i=0;
    int j=n-1;
    int ans=solve(x,i,j);
    cout<<ans<<endl;
    return 0;
}