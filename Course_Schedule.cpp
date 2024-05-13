#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs2(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&v){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it])dfs2(it,adj,vis,v);
    }
    v.push_back(node);
}
bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis))return true;
        }
        else if(vis[it]==1)return true;
    }
    vis[node]=2;
    return false;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>vis(n,0),vis1(n,0),v;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[y].push_back(x);
    }
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]&&dfs(i,adj,vis)){
            cycle=true;
            break;
        }
        if(!vis1[i])dfs2(i,adj,vis1,v);
    }
    if(cycle)cout<<"IMPOSSIBLE"<<endl;
    else{
        for(auto &it:v)cout<<it+1<<" ";
        cout<<endl;
    }
}
