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
        ll n,s;
        cin>>n>>s;
        vector<ll>dp(s+1,0);
        vector<ll>cost(n),pages(n);
        for(auto &it:cost)cin>>it;
        for(auto &it:pages)cin>>it;
        for(ll i=0;i<n;i++){
            for(ll j=s;j>=0;j--){
                if(j>=cost[i]){
                    dp[j]=max(dp[j],dp[j-cost[i]]+pages[i]);
                }
            }
        }
        cout<<dp[s]<<endl;
    } 
}
