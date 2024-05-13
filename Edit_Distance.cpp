#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        string s,r;
        cin>>s;
        cin>>r;
        ll n=s.size();
        ll m=r.size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1));
        for(ll i=1;i<=n;i++)dp[i][0]=i;
        for(ll i=1;i<=m;i++)dp[0][i]=i;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(s[i-1]==r[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
        cout<<dp[n][m]<<endl;
    } 
}
