//<O(n),O(n)>

//preprocess
void dfs(int v,int p=-1)
{
	if(par+1)h[v]=h[p]+1;
	par[v]=p;

	fr(i,0,g[v].size()){
		if(p!=g[v][i])dfs(g[v][i],v);
	}
}

//query

int LCA(int v,int u){
	if(v==u)re v;

	if(h[v]<h[u])swap(u,v);

	re LCA(par[v],u);
}

``````````````````````````````````````````````````````````````

//using sqrt decompostion
//<O(n),O(sqrt(n))>
//sparse table 
//<O(nlog(n)),O(1)>
//Advance RMQ
//<O(n),O(1)> 
