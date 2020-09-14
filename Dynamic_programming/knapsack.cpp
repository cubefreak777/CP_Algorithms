#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
  int n,wt ;cin >> n>> wt;
  vector<int>w(n+1),v(n+1) ;
  for(int i=1;i<=n;i++)
    cin >> w[i] >> v[i] ;
  vector<vector<int>>dp(n+1,vector<int>(wt+1));
  for(int i=1;i<=n;i++)
    for(int j=0;j<wt+1;j++)
      dp[i][j] =max(dp[i-1][j],(j>=w[i]?dp[i-1][j-w[i]]+v[i]:-1)) ;
  cout << dp[n][wt] ;
}
