bool sieve[mxN] ;
mems(sieve,1) ;
sieve[0]=sieve[1]=0 ;
for(int i=2;i<mxN;i++)
  if(sieve[i])
    for(int j=i*2;j<mxN;j+=i)
      sieve[j]=0 ;
