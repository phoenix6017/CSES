#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
vector<int>dij(vector<vector<pair<int,int>>>&adj,int src){
    int n=adj.size();
    vector<int>dis(n,1e15);
    vector<int>num(n,0);
    vector<int>mini(n,0);
    vector<int>maxi(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,src});
    dis[src]=0;
    num[src]=1;
    mini[src]=maxi[src]=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.first>dis[it.second])continue;
        for(auto &i:adj[it.second]){
            if(dis[i.first]==it.first+i.second){
                num[i.first]=(num[i.first]+num[it.second])%M;
                mini[i.first]=min(mini[i.first],mini[it.second]+1);
                maxi[i.first]=max(maxi[i.first],maxi[it.second]+1);
            }
            else if(dis[i.first]>it.first+i.second){
                num[i.first]=num[it.second];
                mini[i.first]=mini[it.second]+1;
                maxi[i.first]=maxi[it.second]+1;
                dis[i.first]=it.first+i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    return {dis.back(),num.back(),mini.back(),maxi.back()};
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
    }
    vector<int>res=dij(adj,0);
    for(auto &it:res)cout<<it<<" ";
    cout<<endl;
}
