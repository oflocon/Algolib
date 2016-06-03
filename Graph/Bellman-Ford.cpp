//O(n*m)

void Bellman-Ford(int v){

	//v is the source vertex
	fr(i,0,n)d[i]=inf;
	d[v]=0;

	fr(i,1,n)
	{
		fr(j,0,g)
		{
			int u=g[j].ss.ff;
			int x=g[j].ss.ss;
			int w=g[j].ff;

			if(d[u]>d[x]+w){
				if(step==n){re "negative cycle found";}
				d[u]=d[v]+w;
			}
		}
	}

}
