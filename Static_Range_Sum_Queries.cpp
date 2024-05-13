#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,q,x,y;
    cin>>n>>q;
    vector<ll>v(n),pre(n+1);
    pre[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>v[i-1];
        pre[i]=pre[i-1]+v[i-1];
    }
    while(q--){
        cin>>x>>y;
        cout<<pre[y]-pre[x-1]<<endl;
    }
}