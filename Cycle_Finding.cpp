#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>dis(n,1e15),par(n,-1);
    vector<pair<int,pair<int,int>>>edge;
    dis[0]=0;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        edge.push_back({z,{x,y}});
    }
    int cycle;
    for(int i=0;i<n;i++){
        cycle=-1;
        for(auto &it:edge){
            if(dis[it.second.second]>dis[it.second.first]+it.first){
                dis[it.second.second]=dis[it.second.first]+it.first;
                par[it.second.second]=it.second.first;
                cycle=it.second.second;
            }
        }
    }
    if(cycle==-1)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        vector<int>res;
        for(int i=0;i<n;i++)cycle=par[cycle];
        int temp=cycle;
        while(true){
            res.push_back(temp);
            if(temp==cycle&&res.size()>1)break;
            temp=par[temp];
        }
        
        for(int i=res.size()-1;i>=0;i--)cout<<res[i]+1<<" ";
 
    }
    
}