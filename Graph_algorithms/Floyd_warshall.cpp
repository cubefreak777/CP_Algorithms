int n,m,d1[mxN][mxN],d2[mxN][mxN],b[mxM+1];
memset(d1,0x3f,sizeof(d1)) ;  
// d1's are the path weights of adjacent neighbours 
memcpy(d2,d1,sizeof(d2)) ;
  For(i,n)d2[i][i]=0 ;
  For(k,n)
    For(i,n)
      For(j,n)
        d2[i][j]=min(d2[i][j],d2[i][k]+d2[k][j]) ;
