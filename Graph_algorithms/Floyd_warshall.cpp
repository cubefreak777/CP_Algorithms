int n,m,q ;
ll d[mxN][mxN] ;
int main() {
  cin >> n >> m>> q ;
  memset(d,0x3f,sizeof(d)) ;
  for(int i=0;i<m;i++){
    ll a,b,c;cin >> a >>  b >>  c;
    d[a][b]=min(d[a][b],(ll)c) ;
    d[b][a]=min(d[b][a],(ll)c) ;
  }
  for(int i=1;i<=n;i++)
    d[i][i]=0 ;
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]) ;
 }
