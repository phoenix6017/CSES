#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it])dfs(it,adj,vis);
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>dis(n,1e15);
    vector<pair<int,pair<int,int>>>edge;
    vector<vector<int>>adj(n),adjr(n);
    dis[0]=0;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        edge.push_back({-z,{x,y}});
        adj[x].push_back(y);
        adjr[y].push_back(x); 
    }
    vector<int>vis(n,0),vis1(n,0);
    dfs(0,adj,vis);
    dfs(n-1,adjr,vis1);
    int res=LLONG_MIN;
    for(int i=0;i<n;i++){
        for(auto &it:edge){
            if(dis[it.second.second]>dis[it.second.first]+it.first){
                dis[it.second.second]=dis[it.second.first]+it.first;
                if(i==n-1&&vis[it.second.second]&&vis1[it.second.second]){
                    res=-1;
                    break;
                }
            }
        }
    }
    if(res==-1)cout<<res<<endl;
    else cout<<-1*dis.back()<<endl;
    
}
