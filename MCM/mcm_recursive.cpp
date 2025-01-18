#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v,int i,int j){
    if(i>=j){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int c1=solve(v,i,k);
        int c2=solve(v,k+1,j);
        int c3=v[i-1]*v[k]*v[j];
        ans=min(ans,c1+c2+c3);
    }
    return ans;
}
int main(){
    vector<int> v={40,20,30,10,30};
    int i=1;
    int j=v.size()-1;
    int ans=solve(v,i,j);
    cout<<ans<<endl;
    return 0;
}

