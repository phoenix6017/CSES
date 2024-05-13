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
        vector<ll>dp(s+1,0);
        dp[0]=1;
        for(ll i=1;i<=s;i++){
            for(ll j=0;j<n;j++){
                if(i-v[j]>=0){
                    dp[i]=(dp[i]+dp[i-v[j]])%M;
                }
            }
        }
        cout<<dp[s]<<endl;
    } 
}
