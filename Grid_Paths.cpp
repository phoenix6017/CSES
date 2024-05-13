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
        vector<string>v(n);
        for(auto &it:v)cin>>it;
        if(v[0][0]=='*'){
            cout<<0<<endl;
            continue;
        }
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
        dp[1][1]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(v[i-1][j-1]!='*'){
                    dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
                }
            }
        }
        cout<<dp[n][n]<<endl;
        
    } 
}