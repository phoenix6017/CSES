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
        vector<ll>v(n);
        ll sum=0;
        for(auto &it:v){
            cin>>it;
            sum+=it;
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
        dp[0][0]=true;
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<=sum;j++){
                dp[i][j]=dp[i][j]|dp[i-1][j];
                if(j>=v[i-1]){
                    dp[i][j]=dp[i][j]|dp[i-1][j-v[i-1]];
                }
            }
        }
        vector<ll>res;
        for(ll i=1;i<=sum;i++){
            if(dp[n][i])res.push_back(i);
        }
        cout<<res.size()<<endl;
        for(auto &it:res){
            cout<<it<<" ";
        }
        cout<<endl;
    } 
}
