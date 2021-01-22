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
//prority_queue nlogn implementation of dijktras algorithm
int n,m;
ll d[mxN];
vector<ar<ll,2>>adj[mxN];
int main() {
  cin >> n >> m ;
  for(int i=0,a,b,c;i<m;i++){
    cin >>a >> b >> c ;
    adj[a].pb({c,b});
  }
  priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>>pq ;
  memset(d,0x3f,sizeof(d)) ;
  d[1]=0 ;pq.push({0,1}) ;
  while(pq.size()){
    ar<ll,2>u=pq.top();
    pq.pop();
    if(u[0]>d[u[1]])
      continue ;
    for(ar<ll,2> v:adj[u[1]]){
      if(d[v[1]]>u[0]+v[0]){
        d[v[1]]=u[0]+v[0] ;
        pq.push({d[v[1]],v[1]}) ;
      }
    }
  }
  For(i,n)
    cout << d[i+1] << " ";
	return 0;
}
// functional implementation of priority_queue implementation without template.
void dijktras(int s,vector<ar<int,2>>adj[mxN],int d[mxN]){
  priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq ;
  pq.push({0,s}) ;
  memset(d,0x3f,sizeof(d1)) ;d[s]=0 ;
  while(pq.size()){
    ar<int,2> u= pq.top() ;
    pq.pop() ;
    if(u[0]>d[u[1]])
      continue ;
    for(ar<int,2> v:adj[u[1]]){
      if(u[0]+v[0]<d[v[1]]){
        d[v[1]]=u[0]+v[0] ;
        pq.push({d[v[1]],v[1]}) ;
      }
    }
  }
}
