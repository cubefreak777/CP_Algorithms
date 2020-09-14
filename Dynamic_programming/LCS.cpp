#include <bits/stdc++.h> 
using namespace std ;
signed main(){
  string s,t ;
  cin >> s >> t ;
  int n = s.size(),m=t.size() ;
  vector<vector<int>>dp(n+1,vector<int>(m+1)) ;
    
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(s[i-1]==t[j-1])
        dp[i][j]=1+dp[i-1][j-1] ;
      else 
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
    }
  string ans ;
  int i=n,j=m ;
  while(i>0||j>0){
    if(i>0&&dp[i-1][j]==dp[i][j])
      --i ;
    else if(j>0&&dp[i][j-1]==dp[i][j])
      --j ;
    else
      ans+=s[i-1],--i,--j ;
  }
  reverse(ans.begin(),ans.end()) ;
  cout << ans << endl ;
}
