#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    ll i=0;
    ll j=0;
    cin>>s;
    ll n=s.size();
    ll res=0;
    while(i<n){
        while(j<n&&s[i]==s[j])j++;
        res=max(res,j-i);
        i=j;
    }
    cout<<res<<endl;
}
