// #include <bits/stdc++.h>
// using namespace std;
// #define int long long 
// void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&topo){
//     vis[node]=1;
//     for(auto &it:adj[node]){
//         if(!vis[it]){
//             dfs(it,adj,vis,topo);
//         }
//     }
//     topo.push(node);
// }
// void scc(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&sc,int col){
//     vis[node]=1;
//     sc[node]=col;
//     for(auto &it:adj[node]){
//         if(!vis[it]){
//             scc(it,adj,vis,sc,col);
//         }
//     }
// }
// int depth(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dp){
//     int res=0;
//     vis[node]=1;
//     for(auto &it:adj[node]){
//         if(!vis[it])res=max(res,depth(it,adj,vis,dp));
//         else res=max(res,dp[it]);
//     }
//     return dp[node]+=res;
// }
// signed main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>v(n);
//     for(auto &it:v)cin>>it;
//     vector<vector<int>>adj(n+5),adjr(n+5);
//     for(int i=0;i<m;i++){
//         int x,y;
//         cin>>x>>y;
//         x--;
//         y--;
//         adj[x].push_back(y);
//         adjr[y].push_back(x);
//     }
//     vector<int>vis(n+5,0);
//     stack<int>topo;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             dfs(i,adj,vis,topo);
//         }
//     }
//     vector<int>sc(n+5,0);
//     vis.assign(n+5,0);
//     int count=0;
//     while(!topo.empty()){
//         auto it=topo.top();
//         topo.pop();
//         if(!vis[it]){
//             scc(it,adjr,vis,sc,count);
//             count++;
//         }
//     }
//     vector<vector<int>>grid(count+5);
//     vector<int>dp(count+5,0);
//     vector<vector<bool>>visi(count+5,vector<bool>(count+5,false));
//     for(int i=0;i<n;i++){
//         dp[sc[i]]+=v[i];
//         for(auto &it:adj[i]){
//             if(sc[i]!=sc[it]&&!visi[sc[i]][sc[it]]){
//                 grid[sc[i]].push_back(sc[it]);
//                 visi[sc[i]][sc[it]]=true;
//             }
//         }
//     }
//     int res=0;
//     vector<int>vi(count+5,0);
//     for(int i=0;i<count;i++){
//         if(!vi[i]){
//             res=max(res,depth(i,grid,vi,dp));
//         }
//     }
//     cout<<res<<endl;
// }
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
#define int long long
 
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& topo) {
    vis[node] = 1;
    for (auto &it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, topo);
        }
    }
    topo.push(node);
}
 
void scc(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& sc, int col) {
    vis[node] = 1;
    sc[node] = col;
    for (auto &it : adj[node]) {
        if (!vis[it]) {
            scc(it, adj, vis, sc, col);
        }
    }
}
 
int depth(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dp) {
    if (vis[node]) return dp[node];
    vis[node] = 1;
    int res = 0;
    for (auto &it : adj[node]) {
        res = max(res, depth(it, adj, vis, dp));
    }
    return dp[node] = res + dp[node];
}
 
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
 
    vector<vector<int>> adj(n + 1), adjr(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adjr[y].push_back(x);
    }
 
    vector<int> vis(n + 1, 0);
    stack<int> topo;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, adj, vis, topo);
        }
    }
 
    vis.assign(n + 1, 0);
    vector<int> sc(n + 1, 0);
    int count = 0;
    while (!topo.empty()) {
        int node = topo.top();
        topo.pop();
        if (!vis[node]) {
            scc(node, adjr, vis, sc, ++count);
        }
    }
 
    vector<vector<int>> grid(count + 1);
    vector<int> dp(count + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[sc[i]] += v[i];
        for (auto &it : adj[i]) {
            if (sc[i] != sc[it]) {
                grid[sc[i]].push_back(sc[it]);
            }
        }
    }
 
    int res = 0;
    vis.assign(n + 1, 0);
    for (int i = 1; i <= count; ++i) {
        if (!vis[i]) {
            res = max(res, depth(i, grid, vis, dp));
        }
    }
    cout << res << endl;
 
    return 0;
}
