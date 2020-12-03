#include<bits/stdc++.h>
using namespace std ;
const int mxN=2e6 ;
int ch[mxN+2][26],nodes =1,ct[mxN+2],n,k;
void insert(string s){
  int u=0 ;
  for(char si:s){
    if(!ch[u][si-'A'])
      ch[u][si-'A']=nodes++ ;
    u=ch[u][si-'A'] ;
  }
  ct[u]++ ;
}
int dfs(int u=0,int lp=0){
  int ans =0 ;
  for(int i=0;i<26;i++)
    if(ch[u][i])
      ans+=dfs(ch[u][i],lp+1),ct[u]+=ct[ch[u][i]];
  while(ct[u]>=k)
    ct[u]-=k,ans+=lp ;
  return ans ;
}
void solve(){
  cin >> n >> k ;
  vector<string>s(n) ;
  for(string &x:s)
    cin >>x; 
  nodes=1 ;
  memset(ch,0,sizeof(ch)) ;
  memset(ct,0,sizeof(ct)) ;
  for(string x:s)
    insert(x) ;
  cout << dfs() << '\n' ;
}
signed main(){
  int t ;
  cin >> t ;
  for(int idx=0;idx<t;idx++){
    cout << "Case #" << idx+1 << ": "  ;
    solve() ;
  }
}
