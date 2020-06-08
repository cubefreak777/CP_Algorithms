vector <int> factors(int n) {
  vector <int> s ;
  for (int i=1;i*i<=n; i++) {
    if (n%i == 0) {
      if (n/i == i) 
        s.push_back(i) ;
      else {  
          s.push_back(i) ;
          s.push_back(n/i) ;
      }
    } 
  }
  return s ;
} 
