int n,m,p[mxN] ;
vi<int>adj[mxN] ;
bool vis[mxN];
void dfs(int u,int pu=-1){
  p[u]=pu ;
  vis[u]=1 ;
  for(int v:adj[u]){
    if(v==pu)
      continue ;
    if(vis[v]){
    // cycle is present 
      vi<int>ans ;
      int u2=u ;
      while(u^v){
        ans.pb(u);
        u=p[u];
      }
      ans.pb(v) ;ans.pb(u2);
      cout << ans.size() << "\n" ;
      for(int i :ans)
        cout << i << " ";
      exit(0);//stop the programme riight away 
    }
    else
      dfs(v,u) ;
  }
}
