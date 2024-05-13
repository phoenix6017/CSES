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
        vector<ll>dp(n+1,INT_MAX);
        dp[0]=0;
        for(ll i=1;i<=n;i++){
            ll curr=i;
            while(curr){
                ll digit=curr%10;
                curr/=10;
                dp[i]=min(dp[i],1+dp[i-digit]);
            }
        }
        cout<<dp[n]<<endl;
    } 
}
