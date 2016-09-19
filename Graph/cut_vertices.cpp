//set time 0, initialize all AP[i]=low[i]=disc[i]=0
int vis[MAXN],disc[MAXN],low[MAXN],parent[MAXN];
int tim,AP[MAXN];

void Find_AP(int u)
{
	vis[u]=1;
	int  i;
	low[u]=disc[u]=(++tim);
	int child=0;

	for(i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(vis[v]==0)
		{
			child++;
			parent[v]=u;
			Find_AP(v);

			low[u]=min(low[u],low[v]);
			if( (parent[u]!=-1) && ( low[v]>=disc[u] ) )AP[u]=1;
			if( (parent[u]==-1) && (child>1))AP[u]=1;
		}
		else if(v!=parent[u])
		{
			low[u]=min(low[u],disc[v]);
		}
	}

}
