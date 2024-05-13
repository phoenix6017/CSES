#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>in(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        in[y]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++)if(in[i]==0)q.push(i);
    vector<int>par(n,-1),dis(n,LLONG_MIN);
    dis[0]=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto &it:adj[temp]){
            if(dis[it]<dis[temp]+1){
                dis[it]=dis[temp]+1;
                par[it]=temp;
            }
            in[it]--;
            if(in[it]==0)q.push(it);
        }
    }
    if(dis[n-1]<0)cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int>res;
        int check=n-1;
        res.push_back(n);
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
