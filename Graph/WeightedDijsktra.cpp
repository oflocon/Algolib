// check time timit strictness , if less than 1 s don't use this one 

vector<pair<ll,ll> >g[MAXN];
ll d[MAXN];

bool mark[MAXN];
const ll inf=1e18;

void dijkstra(ll v)
{
 	fill(d,d + n+2, inf);
 	fill(mark, mark + n+2, false);
   	d[v] = 0;
	ll u;
	set<pair<int,int> >q;

	q.insert(mpk(0,v));

	while(!q.empty())
	{
			u = q.begin()->ss;
			q.erase(q.begin());
			if(mark[u])
			continue;
			mark[u] = true;
			for( int i=0; i<g[u].size();i++)
			{

				pi p=g[u][i];
				if(d[p.ff] > d[u] + p.ss)
				{
					if(d[p.ff]!=INT_MAX){q.erase(q.find(mpk(d[p.ff],p.ff)));}
					d[p.ff] = d[u] + p.ss;
					q.insert(mpk(d[p.ff],p.ff));
				}
			}
	}
}
