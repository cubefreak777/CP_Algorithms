const long INF =1e7 ;
vector<int>d ;
vector<pii>adj[mxN] ;
void dijkstra(int s){
  d.clear() ;
  d.assign(n+1,INF) ;
  vector<bool>u(n+1,0) ;
  d[s]=0 ;
  for(int i=1;i<n+1;i++){
    int v =-1 ;
    for(int j=1;j<n+1;j++)
      if(!u[j]&&(v==-1||d[j]<d[v]))
        v=j ;
    if(d[v]==INF)
      break ;
    u[v]=1 ;
    for(pii x:adj[v])
      d[x.F]=min(d[x.F],d[v]+x.S) ;
    
  }
  
}
