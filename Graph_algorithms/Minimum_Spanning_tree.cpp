// https://cses.fi/problemset/task/1676/
// Minimum spanning tree using disjoint sets
#include<bits/stdc++.h>
#define ar array 
#define int long long 
using namespace std ;
const int mxN = 2e5+2 ;
int n,m,p[mxN],a1=0,a2=0;
ar<int,3> e[mxN] ;
int find(int x){
  return x^p[x]?p[x]=find(p[x]):x ;
}
bool join(int x,int y){
  if((x=find(x))==(y=find(y)))
    return 0 ;
  p[x]=y  ;
  return 1  ;
}
signed main(){
  cin >> n >>m  ;
  for(int i=0;i<m;i++){
    cin >> e[i][1] >> e[i][2] >> e[i][0] ;
    --e[i][1],--e[i][2] ;
  }
  sort(e,e+m) ; iota(p,p+n,0) ;
  for(int i=0;i<m;i++){
    if(join(e[i][1],e[i][2]))
      ++a1,a2+=e[i][0] ;
  }
  if(a1<n-1)
    cout << "IMPOSSIBLE";
  else 
    cout << a2;
}
