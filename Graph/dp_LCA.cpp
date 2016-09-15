
const int n=100001;
int logn=18;
int P[N+2][logn], L[N+2]; //~use log(n) as second parameter, here L[i] denotes the distance of node i from root 

int lca(int x, int y)
{
	if(h[x] < h[y])swap(x,y);

	for(int j=logn-1; j>=0; j--)              // here keep j= logn -1 and not logn , see array limits
		if((h[x]- (1<<j) )>=h[y])x=P[x][j];

	if(x==y)re x;

	for(int j=logn-1; j>=0; j--)
		if(P[x][j]!=P[y][j]){x=P[x][j], y=P[y][j];}

	return P[x][0];
}

void buildlca()
{
	int i,j;
	// check if zero based indexing or 1 based indexing  here and ....
	for (i = 0; i<n; i++)P[i][0] = par[i];   // if we are building online then  for each given parent , just equate to T[i]=p;

	for (j = 1; (1<<j)<n; j++)
	{
		for (i = 0; i<n; i++)// here 
		{
			if (P[i][j - 1] != -1)P[i][j] = P[P[i][j - 1]][j - 1];  // no need to check this condition actually
		}
	}
}



int dis(int x, int y)
{
	int lca = LCA(x,y);
	return L[x] + L[y] - L[lca] - L[lca];
}





