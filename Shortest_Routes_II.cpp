#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>dis(n,vector<int>(n,1e15));
    for(int i=0;i<n;i++)dis[i][i]=0;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        dis[x][y]=min(dis[x][y],z);
        dis[y][x]=min(dis[y][x],z);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<((dis[x][y]==1e15)?-1:dis[x][y])<<endl;
    }
}
