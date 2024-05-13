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
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>dp(n+1,vector<ll>(m+1));
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=m;j++){
                if(i==j)dp[i][j]=0;
                else{
                    dp[i][j]=1e9;
                    for(ll k=0;k<i;k++){
                        dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
                    }
                    for(ll k=0;k<j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
                    }
                }
            }
        }
        cout<<dp[n][m]<<endl;
    } 
}