#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<setprecision(6)<<fixed;
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<double>>dp(601,vector<double>(n+1,0));
    dp[0][0]=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=600;i++){
            for(int k=1;k<=6;k++){
                if(i-k>=0){
                    dp[i][j]+=dp[i-k][j-1]*(1.0/6);
                }
            }
        }
    }
    double res=0;
    for(int i=a;i<=b;i++)res+=dp[i][n];
    cout<<res;
}
