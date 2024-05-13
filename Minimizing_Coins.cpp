#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=998244353;
 
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
        vector<ll>dp(s+1,INT_MAX);
        dp[0]=0;
        for(ll i=1;i<=s;i++){
            for(ll j=0;j<n;j++){
                if(i-v[j]>=0){
                    if(dp[i-v[j]]!=INT_MAX&&dp[i-v[j]]+1<dp[i])dp[i]=dp[i-v[j]]+1;
                }
            }
        }
        if(dp[s]!=INT_MAX)cout<<dp[s]<<endl;
        else cout<<-1<<endl;
    } 
}