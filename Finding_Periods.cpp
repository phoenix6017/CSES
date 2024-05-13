#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
 
vector<ll> base_pow(1000001);
 
void createHash(string &s, vector<unsigned long long>& prefix) {
    int n = s.size();
    unsigned long long int p = 101;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = (prefix[i - 1] * p + s[i - 1]) % M;
    }
}
auto get_hash(string &s, int L, int R, vector<unsigned long long>& prefix) {
    unsigned long long int p = 101;
    unsigned long long hash_LR = (prefix[R + 1] - (prefix[L] * base_pow[R-L+1]) % M + M) % M;
    return hash_LR<0?hash_LR+M:hash_LR;
}
int main(){
    base_pow[0] = 1;
    for (int i = 1; i <= 1e6; i++) { base_pow[i] = base_pow[i - 1] * 101 % M; }
    string s;
    cin>>s;
    int n=s.size();
    vector<unsigned long long>prefix(n+1);
    createHash(s,prefix);
    for(int i=0;i<n;i++){
        bool res=true;
        int j=0;
        while(j<n){
            int len=min(i+1,n-j);
            if(get_hash(s,0,len-1,prefix)==get_hash(s,j,j+len-1,prefix))res&=1;
            else res&=0;
            j+=len;
        }
        if(res)cout<<i+1<<" ";
    }
    cout<<endl;
}
