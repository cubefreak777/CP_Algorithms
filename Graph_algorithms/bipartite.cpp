//biparite graph: if a graph can b divided in 2 sets such that each set shouldn't have any directly connected nodes 
int c[mxN] ;
void dfs(int u,int cu=0){
  if(~c[u]){
    if(c[u]^cu){
      //graph is not bipartite 
      exit(0) ;
    }
    return ;
  }
  c[u]=cu ;
  for(int v:adj[u])
    dfs(v,cu^1);
}
memset(c,-1,sizeof(c)) ;
