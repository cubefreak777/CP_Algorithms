#include<bits/stdc++.h>
#define int long long 
using namespace std ;
const int mxN = 2e5 ;
int n,a[39*mxN+1],ch[mxN*30][2],ct[mxN*30],nodes=1,ans =0;
void insert(int k){
  int u=0 ;
  for(int i=30;~i;--i){
    int bit = ((k>>i)&1);
    if(!ch[u][bit])
      ch[u][bit]=nodes++ ;
    u=ch[u][bit] ;
  }
  ++ct[u] ;
}
void dfs(int u=0){
  for(int i=0;i<2;i++){
    if(ch[u][i])
      dfs(ch[u][i]),ct[u]+=ct[ch[u][i]] ;
  }
}
int dfs1(int u=0){
  if(ct[u])
    return ct[u] ;
  vector<int>v ;
  for(int i=0;i<2;i++){
    if(ch[u][i])
      v.push_back(dfs1(ch[u][i])) ;
    else 
      v.push_back(0) ;
  }
  return max(v[0]+min(1LL,v[1]),v[1]+min(1LL,v[0])) ;
}
signed main(){
  cin >> n; 
  vector<int>a(n) ;
  for(int &x:a){
    cin >> x ;
    insert(x) ;
  }
  
  cout << n-dfs1() ;
}
