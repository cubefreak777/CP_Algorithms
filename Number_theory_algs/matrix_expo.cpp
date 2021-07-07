#include "bits/stdc++.h"
using namespace std ;
struct mat {
  vector<vector<ll>>a ;
  int N;
  mat(int _N):N(_N){
    a=vector<vector<ll>>(N,vector<ll>(N)) ;
  }
  void ide(){
    for(int i=0;i<N;i++)
      a[i][i]=1  ;
  }
  mat operator*(const mat &o) const {
    mat r(N);
    for(int i=0; i<N; ++i)
      for(int k=0; k<N; ++k)
        for(int j=0; j<N; ++j)
          r.a[i][j]=(r.a[i][j]+a[i][k]*o.a[k][j])%M;
    return r;
  }
};
int main(){
  int N  ;
  cin >> N  ;
  mat C(N),R(N) ;
  // intialize C 
  R.ide() ;
  R.ide() ;
  for(;m;C=(C*C),m/=2)
    if(m&1)
      R=(R*C) ;
  //R will be the resultant matrix.
  

}
