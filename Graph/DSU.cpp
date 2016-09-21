vector<int>g[MAXN];
int sz[MAXN],big[MAXN],depth[MAXN];
// check->keep starts with one , indexing matches the constraints 

void dfs0(int x, int p,int d)
{
	sz[x]=1;
	depth[x]=d;
	fr(i,0,g[x].size())
	{
		int u=g[x][i];
		if(u==p)continue;
		dfs0(u,x,d+1);
		sz[x]+=sz[u];
	}
}

void add(int x, int p,int z)
{
  //do the adding procedure 

	fr(i,0,g[x].size())
	{
		int u=g[x][i];
		if(u!=p && big[u]!=1)add(u,x,z);
	}
}


void dfs(int x, int p, int keep)
{
	int mx=0,bigc=0;

	fr(i,0,g[x].size())
	{
		int u=g[x][i];
		if(u!=p && sz[u]>mx)mx=sz[u],bigc=u;
	}

	fr(i,0,g[x].size())
	{
		int u=g[x][i];
		if(u!=p && bigc!=u)dfs(u,x,0);
	}
	if(mx!=0)big[bigc]=1,dfs(bigc,x,1);

	add(x,p,1);

  // answer queries here , they must be offline 

	if(mx!=0)big[bigc]=0;
	if(keep==0)add(x,p,-1);
}
