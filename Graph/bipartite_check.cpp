int dfs(int x, int co)
{
	if(c[x] != 0)
	{
			if(c[x] == co)re 1;
			else re 0;
	}
	c[x] = co;

	fr(i,1,n+1)
	{
		if(g[x][i] == 1)
		{
				if(!dfs(i, -co))re 0;
		}
	}
        re 1;
}
