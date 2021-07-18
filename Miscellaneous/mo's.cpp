int ans=0,l=0,r=-1,ans1=0 ;
	int B = sqrt(n) ;
	unordered_map<int,int>c ; // might have to use a freq. array
	vector<int>Q(q) ;
	vector<ar<int,3>>qry  ;
	for(int i=0,l,r;i<q;i++){
		cin>>l>>r,--l,--r  ;
		r+=(r<l?n:0) ;
		qry.push_back({l,r,i}) ;
	}	  
	sort(qry.begin(),qry.end(),[&](const ar<int,3>&i,const ar<int,3>&j){
		return (i[0]/B<j[0]/B||(i[0]/B==j[0]/B&&i[1]<j[1])) ;
	})  ;
	auto add=[&](int x){
		ans-=(c[a[x]]==a[x]) ;
		c[a[x]]++ ;
		ans+=(c[a[x]]==a[x]) ;
	}  ;
	auto del=[&](int x){
		ans-=(c[a[x]]==a[x]) ;
		c[a[x]]-- ;
		ans+=c[a[x]]==a[x] ;
	}  ;
	auto get=[&](){
		return ans  ;
	} ;
	for(ar<int,3>x:qry){
		while(l>x[0])
			l--,add(l) ;
		while(r<x[1])
			r++,add(r) ;
		while(l<x[0])
			del(l),l++ ;
		while(r>x[1])
			del(r),r-- ;
		Q[x[2]]=get() ;
	}
	for(int x:Q)
		cout<<x<<"\n" ;
