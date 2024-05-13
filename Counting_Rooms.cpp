#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,int n,int m,vector<string>&adj){
    if(i<0||i>=n||j<0||j>=m||adj[i][j]=='#')return;
    adj[i][j]='#';
    dfs(i+1,j,n,m,adj);
    dfs(i-1,j,n,m,adj);
    dfs(i,j-1,n,m,adj);
    dfs(i,j+1,n,m,adj);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>adj(n);
    for(auto &it:adj)cin>>it;
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='.'){
                res++;
                dfs(i,j,n,m,adj);
            }
        }
    }
    cout<<res<<endl;
}
