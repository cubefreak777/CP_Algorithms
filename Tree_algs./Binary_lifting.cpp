//https://codeforces.com/contest/1328/submission/78989984 <- check this for commented code 

vi adj[mxN] ;
int anc[mxN][18],d[mxN],n,m;
void dfs(int v,int p){
  anc[v][0]=p ;d[v]=d[p]+1 ;
  for(int i=1;i<18;i++)
    anc[v][i]=~anc[v][i-1]?anc[anc[v][i-1]][i-1]:-1 ;
  for(int x:adj[v])
    if(x^p)
      dfs(x,v) ;
}
int lca(int u,int v){
  if(d[u]<d[v])
    swap(u,v) ;
  for(int i=17;~i;--i)
    if(d[u]-(1<<i)>=d[v])
      u=anc[u][i] ;
  if(u==v)
    return u ;
  for(int i =17;~i;--i){
    if(anc[u][i]^anc[v][i]){
      u=anc[u][i],v=anc[v][i] ;
    }
  }
  return anc[u][0] ;
}
