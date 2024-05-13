#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k*k<n){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        int l=1;
        int r=k;
        while(true){
            for(int i=r;i>=l;i--)cout<<i<<" ";
            if(r==n)break;
            l=r+1;
            r=min(r+k,n);
        }
        cout<<endl;
    }
}
