#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>v(n);
    for(auto &it:v)cin>>it.first>>it.second;
    sort(v.begin(),v.end());
    ll res=0;
    multiset<ll>check;
    for(ll i=0;i<k;i++)check.insert(v[i].second);
    for(ll i=k;i<n;i++){
        auto st=check.begin();
        auto en=check.end();
        en--;
        if(v[i].first>=(*st)){
            res++;
            check.erase(st);
            check.insert(v[i].second);
        }
        else if(v[i].second<(*en)){
            check.erase(en);
            check.insert(v[i].second);
        }
    }
    res+=check.size();
    cout<<res<<endl;
}