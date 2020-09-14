int LIS(vector<int>&a){
  int n =a.size() ;
  vector<int>d(n+1,1e9) ;
  d[0]=-1e9  ;
  for(int i=0;i<n;i++){
    int j=upper_bound(d.begin(),d.end(),a[i])-d.begin() ;
    if(d[j-1]<a[i]&&d[j]>a[i])
      d[j]=a[i] ;
  }
  int ans =1;
  for(int i=0;i<=n;i++)
    if(d[i]<1e9)
      ans=i ;
  return ans;
}
