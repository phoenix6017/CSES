#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
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
    vector<int>dp(n,0);
    dp[0]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto &it:adj[temp]){
            dp[it]=(dp[it]+dp[temp])%M;
            in[it]--;
            if(in[it]==0)q.push(it);
        }
    }
    cout<<dp[n-1]<<endl;
}
