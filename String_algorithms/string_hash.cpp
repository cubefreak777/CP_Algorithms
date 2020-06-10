// https://www.codechef.com/COOK118A/problems/CHEFSHIP

// inorder to get hash of a subtring (i,j) do ((ans[j]-ans[i]+M)%M)*p_power[k] , choose k appropriately according to the 2nd string 

long const M=1e9+9;
const int p=31  ;
ll p_power[mxN] ;
void power_boost(){
  p_power[0]=1 ;
  for(int i=1;i<mxN;i++)
    p_power[i]=(p_power[i-1]*p)%M ;
}
vi hc(string s){  
  int n=(int)sz(s) ;vi ans(n+1) ;
  for(int i=0;i<n;i++)
    ans[i+1]=(ans[i]+(s[i]-'a'+1)*p_power[i])%M ;
  return ans ;
}
