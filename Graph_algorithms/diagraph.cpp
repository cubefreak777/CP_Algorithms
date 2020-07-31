struct digraph {
	int n;
	vi<vi<int>> adj, adj2;
	digraph(int _n, vi<ar<int, 2>> &e) {
		n=_n;
		adj=vi<vi<int>>(n);
		adj2=vi<vi<int>>(n);
		EACH(a, e) {
			adj[a[0]].pb(a[1]);
			adj2[a[1]].pb(a[0]);
		}
	}
	vi<int> toposort() {
		vi<int> d(n);
		queue<int> qu;
		FOR(n) {
			d[i]=sz(adj2[i]);
			if(!d[i])
				qu.push(i);
		}
		vi<int> ans;
		while(qu.size()) {
			int u=qu.front();
			qu.pop();
			EACH(v, adj[u]) {
				--d[v];
				if(!d[v])
					qu.push(v);
			}
			ans.pb(u);
		}
		if(sz(ans)<n)
			ans.clear();
		return ans;
	}
};
