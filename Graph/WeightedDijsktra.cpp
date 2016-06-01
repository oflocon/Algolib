bool mark[MAXN];

void dijkstra(int v){
 	fill(d,d + n, inf);
 	fill(mark, mark + n, false);
   	d[v] = 0;
	 int u;
	 priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
	
	 pq.push({d[v], v});
	
	 while(!pq.empty()){
			 u = pq.top().ss;
			pq.pop();
			if(mark[u])
			continue;
			mark[u] = true;
			for(auto p : g[u]){ //g[v][i] = pair(vertex, weight)
				if(d[p.ff] > d[u] + p.ss){
					d[p.ff] = d[u] + p.ss;
					pq.push({d[p.ff], p.ff});
				}
			}
	}
}
