#include <bits/stdc++.h>
using namespace std;
void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&vis,int col,bool &check){
    vis[node]=col;
    for(auto &it:adj[node]){
        if(it!=par){
            if(vis[it]==0)dfs(it,node,adj,vis,3-col,check);
            else if(vis[it]==vis[node])check=false;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>col(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool check=true;
    for(int i=0;i<n;i++){
        if(col[i]==0){
            dfs(i,-1,adj,col,1,check);
            if(check==false){
                break;
            }
        }
    }
    if(!check)cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<n;i++)cout<<col[i]<<" ";
        cout<<endl;
    }
    
}
