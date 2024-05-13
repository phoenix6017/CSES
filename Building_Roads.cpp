#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it])dfs(it,adj,vis);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,x,y;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int>vis(n,0);
    vector<int>connect;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            connect.push_back(i+1);
            dfs(i,adj,vis);
        }
    }
    cout<<connect.size()-1<<endl;
    for(int i=1;i<connect.size();i++){
        cout<<connect[i]<<" "<<connect[i-1]<<endl;
    }
}
