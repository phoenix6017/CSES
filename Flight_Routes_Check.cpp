#include <bits/stdc++.h>
using namespace std;
#define int long long 
void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(it!=par&&!vis[it]){
            dfs(it,node,adj,vis);
        }
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n),adjr(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adjr[y].push_back(x);
    }
    vector<int>vis1(n,0),vis2(n,0);
    dfs(0,-1,adj,vis1);
    dfs(0,-1,adjr,vis2);
    for(int i=0;i<n;i++){
        if(!vis1[i]||!vis2[i]){
            cout<<"NO"<<endl;
            if(!vis1[i]){
                cout<<1<<" "<<i+1<<endl;
            }
            else{
                cout<<i+1<<" "<<1<<endl;
            }
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
