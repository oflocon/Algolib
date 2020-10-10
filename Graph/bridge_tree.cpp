

vector<int> tree[N]; 			// The bridge edge tree formed from the given graph
vector<int> graph[N];
int U[N],V[N];  				//edge list representation of the graph.
bool isbridge[N]; 				// if i'th edge is a bridge edge or not
int visited[N];int arr[N],T=0; 	//supporting arrays
int cmpno=1;
queue<int> Q[N];

int adj(int u,int e)
{
    return U[e]==u?V[e]:U[e];
}

int dfs0(int u,int edge)    //marks all the bridges
{
	visited[u]=1;
	arr[u]=T++;
	int dbe = arr[u];
	for(int i=0;i<(int)graph[u].size();i++)
	{
		int e = graph[u][i];
		int w = adj(u,e);
		if(!visited[w])
		dbe = min(dbe,dfs0(w,e));
		else if(e!=edge)
		dbe = min(dbe,arr[w]);
	}

	if(dbe == arr[u] && edge!=-1)isbridge[edge]=true;

	return dbe;
}

void dfs1(int v) //Builds the tree with each edge a bridge from original graph
{
	int currcmp = cmpno;    // current component no.
	Q[currcmp].push(v);
	visited[v]=1;

	while(!Q[currcmp].empty())
	{
		int u = Q[currcmp].front();
		Q[currcmp].pop();
	
		//while querying if component numbers are needed uncomment this
		//parent[u]=currcmp;
	
		for(int i=0;i<(int)graph[u].size();i++)
		{
			int e = graph[u][i];
			int w = adj(u,e);
			if(visited[w])continue;

			if(isbridge[e])
			{
				cmpno++;
				tree[currcmp].push_back(cmpno);
				tree[cmpno].push_back(currcmp);
				dfs1(w);
			}
			else
			{
				Q[currcmp].push(w);
				visited[w]=1;
			}
		}
	}
}

//bridge graph ends here //
