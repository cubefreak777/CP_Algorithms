vector<ar<int,2>>P[mxN] ; 
P[1].pb({1,1}) ;
for(int i=2;i<mxN;i++){
  int a =i ;
  for(int d=2;d*d<=i;d++){
    if(a%d)
      continue ;
    ar<int,2>x={d,0} ;
    for(;a%d<1;a/=d)
      ++x[1] ;
    P[i].pb(x) ;
  }
  if(a>1)P[i].pb({a,1}) ;
}
