#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    ll res=0;
    for(auto &it:v)cin>>it;
    for(ll i=1;i<n;i++){
        if(v[i]<v[i-1]){
            res+=(v[i-1]-v[i]);
            v[i]=v[i-1];
        }
    }
    cout<<res<<endl;
}