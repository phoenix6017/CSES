#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        adj[x].push_back({y,z});
    }
    vector<int>dis(n,LLONG_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,0});
    dis[0]=0;
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
    for(auto &it:dis)cout<<it<<" ";
    cout<<endl;
}
