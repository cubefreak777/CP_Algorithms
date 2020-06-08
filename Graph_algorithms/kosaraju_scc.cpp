int n ;
vi adj[mxN],radj[mxN],order,component;
bool visited[mxN],ans[mxN] ;
void dfs1(int v){
  visited[v]=1 ;
  for(int x:adj[v])
    if(!visited[x])
      dfs1(x) ;
  order.pb(v) ;
}
void dfs2(int v){
  visited[v]=1 ;
  component.pb(v) ;
  for(int x:radj[v])
    if(!visited[x])
      dfs2(x) ;
}
void solve(){
  ...read n and m ....
  mems(visited,0) ;
  For(i,m){
    int u,v ;
    cin >> u >> v ;
    adj[u].pb(v) ;radj[v].pb(u) ;
  }
  Rep(i,n)
    if(!visited[i])
      dfs1(i) ;
  reverse(all(order)) ;
  mems(visited,0) ;
  for(int i:order)
    if(!visited[i]){
      dfs2(i) ;
      if(sz(component)>=k)
        for(int x:component)
          ans[x]=1 ;
      component.clear() ;
    }
  
}
