

//to check from source to destination this can be used, the temp will store path between the required nodes , but the frist vertex 
//is not stored here, store it before using the ans

bool dfs(int x, int y,int p)
{
	if(x==y)re 1;

	fr(i,0,g[x].size())
	{
		int u=g[x][i];
		if(u!=p  && dfs(u,y,x))
		{
			temp.pb(u);
			re 1;
		}

	}
	re 0;
}

