#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    if(n==2||n==3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    for(ll i=2;i<=n;i+=2)cout<<i<<" ";
    for(ll i=1;i<=n;i+=2)cout<<i<<" ";
    cout<<endl;
}
