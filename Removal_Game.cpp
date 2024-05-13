#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(auto &it:v)cin>>it;
        vector<vector<ll>>dp(n,vector<ll>(n));
        for(ll k=0;k<n;k++){
            ll i=0;
            ll j=k;
            while(j<n){
                ll x=0,y=0,z=0;
                if(i+2<=j)x=dp[i+2][j];
                if(i+1<=j-1)y=dp[i+1][j-1];
                if(i<=j-2)z=dp[i][j-2];
                dp[i][j]=max(v[i]+min(x,y),v[j]+min(y,z));
                i++;
                j++;
            }
        }
        cout<<dp[0][n-1]<<endl;
    } 
}
