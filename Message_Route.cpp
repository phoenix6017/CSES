#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>vis(n,0),par(n,-1);
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto &it:adj[temp]){
            if(!vis[it]){
                par[it]=temp;
                vis[it]=1;
                q.push(it);
            }
        }
    }
    if(vis[n-1]==0)cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int>res;
        res.push_back(n);
        int check=n-1;
        while(check!=0){
            check=par[check];
            res.push_back(check+1);
        }
        cout<<res.size()<<endl;
        reverse(res.begin(),res.end());
        for(auto &it:res)cout<<it<<" ";
        cout<<endl;
    }
}
