#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
 
ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2){
        long long temp=((res%M) * (res%M))%M;
        return ((temp%M)*a)%M;
    }
    else
        return ((res%M) * (res%M))%M;
}
 
int main(){
    ll n;
    cin>>n;
    cout<<binpow(2,n)<<endl;
}
