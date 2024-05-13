#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ones=1;
        ll two=1;
        for(ll i=2;i<=n;i++){
            ll nones=(2*ones+two)%M;
            ll ntwos=(4*two+ones)%M;
            ones=nones;
            two=ntwos;
        }
        cout<<(ones+two)%M<<endl;
    } 
}