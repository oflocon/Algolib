const int MAXN=3e5+10;
vector<int>g[MAXN];
int low[MAXN],disc[MAXN],v[MAXN];
set<int>s;
stack<pi>st;
int ct;

void get_bcc(int x,int u)
{
	pi pa;
	while(st.size())
	{
		pa=st.top();
		if(pa.ff==x && pa.ss==u)
		{
			st.pop();break;
		}
		else {st.pop();}
	}

}

void find_bcc(int x, int p)
{
	v[x]=1;
	ct++;
	low[x]=disc[x]=ct;

	fr(i,0,g[x].size())
	{
		int u=g[x][i];
		if(v[u]==0)
		{
			st.push(mpk(x,u));
			find_bcc(u,x);

			if(low[u]>=disc[x])
			{
				get_bcc(x,u);
			}
			low[x]=min(low[x],low[u]);
		}
		else if( u!=p  && disc[u]<disc[x])
		{
			st.push(mpk(x,u));
			low[x]=min(low[x],disc[u]);
		}
	}
}
