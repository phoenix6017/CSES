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
        for(ll i=0;i<n;i++){
            for(ll j=1;j<=s;j++){
                if(j-v[i]>=0){
                    dp[j]=(dp[j]+dp[j-v[i]])%M;
                }
            }
        }
        cout<<dp[s]<<endl;
    } 
}
