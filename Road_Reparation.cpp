#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,pair<int,int>> edges[200001];
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
    for(int i=0;i<m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        edges[i]={d,{x,y}};
    }
    sort(edges,edges+m);
    int res=0;
    int count=1;
    for(int i=0;i<m;i++){
        auto it=edges[i];
        if(merge(it.second.first,it.second.second)){
            res+=it.first;
            count++;
        }
    }
    if(count==n)cout<<res<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
