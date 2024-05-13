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
        ll sum=(n*(n+1))/2;
        if(sum%2){
            cout<<0<<endl;
            continue;
        }
        vector<vector<ll>>dp(n+1,vector<ll>(sum/2+1,0));
        dp[0][0]=1;
        for(ll i=1;i<n;i++){
            for(ll j=0;j<=sum/2;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=i){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-i])%M;
                }
            }
        }
        cout<<dp[n-1][sum/2]<<endl;
    } 
}