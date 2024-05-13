#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dij(vector<vector<pair<int,int>>>&adj,int src){
    int n=adj.size();
    vector<int>dis(n,1e15);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.first>dis[it.second])continue;
        for(auto &i:adj[it.second]){
            if(dis[i.first]>it.first+i.second){
                dis[i.first]=it.first+i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    return dis;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n),adjr(n);
    vector<pair<pair<int,int>,int>>edges;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        adj[x].push_back({y,z});
        adjr[y].push_back({x,z});
        edges.push_back({{x,y},z});
    }
    vector<int>go=dij(adj,0);
    vector<int>come=dij(adjr,n-1);
    int res=go[n-1];
    for(auto &it:edges){
        res=min(res,go[it.first.first]+come[it.first.second]+it.second/2);
    }
    cout<<res<<endl;
}