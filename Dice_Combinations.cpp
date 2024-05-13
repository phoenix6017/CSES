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
        ll n,s,y;
        cin>>n;
        vector<ll>dp(n+1,0);
        dp[0]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=6;j++){
                if(i-j>=0)dp[i]=(dp[i]+dp[i-j])%M;
            }
        }
        cout<<dp[n]%M<<endl;
    } 
}
