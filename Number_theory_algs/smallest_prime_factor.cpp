int spf[mxA] ;
mems(spf,0) ;
spf[1]=1 ;
for(int i=2;i<mxA;i++){
  if(spf[i])
    continue ;
  spf[i]=i ;
  for(int j=2*i;j<mxA;j+=i)
    if(!spf[j])
      spf[j]=i ;
}
