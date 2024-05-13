#include <bits/stdc++.h>
using namespace std;
#define int long long
int par[100001];
int find(int u){
    if(par[u]<0)return u;
    return par[u]=find(par[u]);
}
bool merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v)return false;
    if(par[u]<par[v])swap(u,v);
    par[v]+=par[u];
    par[u]=v;
    return true;
}
signed main(){
    int n,m;
    cin>>n>>m;
    fill(par+1,par+n+1,-1);
    int count=n;
    int sz=1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(merge(x,y)){
            count--;
            sz=max(sz,-par[find(x)]);
        }
        cout<<count<<" "<<sz<<endl;
    }
    
}
