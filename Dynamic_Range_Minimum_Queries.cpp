#include <bits/stdc++.h>
using namespace std;
#define int long long
int segtree[800050];
//Building segment tree to calculate minimum in O(logn) time for a subarray
void build(int *arr,int node,int start,int end){
    if(start==end){
        segtree[node]=arr[start];
        return;
    }
    int mid=(start+end)>>1;
    build(arr,2*node,start,mid);
    build(arr,2*node+1,mid+1,end);
    segtree[node]=min(segtree[2*node],segtree[2*node+1]);
}
//To retrieve or return the value of minimum 
int query(int node,int start,int end,int l,int r){
    if(start>end||start>r||end<l)return LLONG_MAX;
    if(start>=l&&end<=r)return segtree[node];
    int mid=(start+end)>>1;
    int q1=query(2*node,start,mid,l,r);
    int q2=query(2*node+1,mid+1,end,l,r);
    return min(q1,q2);
}
//To update the segment tree by manipulating value at one index
void update(int node,int start,int end,int idx,int val){
    if(start==end){
        segtree[node]=val;
        return;
    }
    int mid=(start+end)>>1;
    if(idx<=mid)update(2*node,start,mid,idx,val);
    else update(2*node+1,mid+1,end,idx,val);
    segtree[node]=min(segtree[2*node],segtree[2*node+1]);
    
}
 
signed main(){
    int n,q,t,x,y;
    cin>>n>>q;
    int v[n];
    for(auto &it:v)cin>>it;
    build(v,1,0,n-1);
    while(q--){
        cin>>t>>x>>y;
        if(t==1)update(1,0,n-1,x-1,y);
        else cout<<query(1,0,n-1,x-1,y-1)<<endl;
    }
    return 0;
}