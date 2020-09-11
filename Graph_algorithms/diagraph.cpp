struct digraph{
  int n ;
  vector<vector<int>>adj,adj2 ;
  digraph(int _n,vector<ar<int,2>> &e){
    n=_n ;
    adj=vector<vector<int>>(n);
    adj2=vector<vector<int>>(n);
    for(auto a:e){
      adj[a[0]].push_back(a[1]);
      adj2[a[1]].push_back(a[0]);
    }
  }
  vector<int>toposort(){
    queue<int>qu ;
    vector<int>ans ;
    vector<int>d(n) ;
    for(int i=0;i<n;i++){
      d[i]=adj2[i].size() ;
      if(!d[i])
        qu.push(i) ;
    }
    while(qu.size()){
      int u=qu.front() ;
      qu.pop() ;
      for(int x:adj[u]){
        --d[x] ;
        if(!d[x])
          qu.push(x) ;
      }
      ans.push_back(u) ;
    }
    if(ans.size()<n)
      ans.clear() ;
    return ans ;
  }
};
