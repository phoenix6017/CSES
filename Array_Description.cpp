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
        ll n,s;
        cin>>n>>s;
        vector<ll>v(n);
        for(auto &it:v)cin>>it;
        vector<vector<ll>>dp(n,vector<ll>(s+2,0));
        if(v[0]==0){
            for(ll i=1;i<=s;i++)dp[0][i]=1;
        }
        else dp[0][v[0]]=1;
        for(ll i=1;i<n;i++){
            if(v[i]==0){
                for(ll j=1;j<=s;j++){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%M;
                }
            }
            else{
                dp[i][v[i]]=(dp[i-1][v[i]]+dp[i-1][v[i]-1]+dp[i-1][v[i]+1])%M;
            }
        }
        ll res=0;
        for(ll i=1;i<=s;i++){
            res=(res+dp[n-1][i])%M;
        }
        cout<<res<<endl;
    } 
}
