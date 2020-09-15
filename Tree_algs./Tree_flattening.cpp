//https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array 
#define pb push_back 
#define vi vector
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end() 
#define sz(a) (int)a.size() ;
const long mxN =2e5+2 ;
int n,q ,ds[mxN],de[mxN],a[mxN],ft[mxN],t=0;
vi<int>adj[mxN] ;
void upd(int i,int x){
  for(;i<=n;i+=i&-i)
    ft[i]+=x ;
}
int qry(int i){
  int r=0 ;
  for(;i;i-=i&-i)
    r+=ft[i] ;
  return r ;
}
void dfs(int v=1,int p=0){
  ds[v]=++t ;
  for(int x:adj[v])
    if(x^p)
      dfs(x,v);
  de[v]=t ;
}
signed main() {
  cin >>n >> q;
  for(int i=1;i<=n;i++)
    cin >> a[i] ;
  for(int i=1;i<n;i++){
    int u,v ;
    cin >> u >> v ;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs() ;
  for(int i=1;i<=n;i++)
    upd(ds[i],a[i]) ;
  while(q--){
    int qt;
    cin >> qt ;
    if(qt==1){
      int s,x ;
      cin >> s >> x ;
      upd(ds[s],x-a[s]) ;
      a[s]=x ;
    }else{
      int s ;
      cin >> s ;
      cout << qry(de[s])-qry(ds[s]-1) <<'\n' ;
    }
  }
    
}
