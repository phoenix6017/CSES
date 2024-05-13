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
        ll n,x;
        cin>>n;
        vector<ll>dp;
        for(ll i=0;i<n;i++){
            cin>>x;
            auto it=lower_bound(dp.begin(),dp.end(),x);
            if(it!=dp.end()){
                *it=x;
            }
            else{
                dp.push_back(x);
            }
        }
        cout<<dp.size()<<endl;
    } 
}
