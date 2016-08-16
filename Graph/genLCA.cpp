
const int N=100000;
int logn=18;
int P[N+2][logn], L[N+2]; //~use log(n) as second parameter, here L[i] denotes the distance of node i from root 


int LCA(int x, int y)
{
	if(L[x] < L[y])swap(x,y);
	
	for(int j=logn-1; j>=0; j--)              // here keep j= logn -1 and not logn , see array limits
		if(L[x]-(1<<j)>=L[y])x=P[x][j];
	
	if(x==y)return x;
	
	for(int j=logn-1; j>=0; j--)
		if(P[x][j]!=P[y][j]){x=P[x][j], y=P[y][j];}
	
	return P[x][0];
}

int dis(int x, int y)
{
	int lca = LCA(x,y);
	return L[x] + L[y] - L[lca] - L[lca];
}

void buildlca()
{
      for (i = 0; i < N; i++)P[i][0] = T[i];   // if we are building online then  for each given parent , just equate to T[i]=p;

      for (j = 1; 1 << j < N; j++)
      {
        for (i = 0; i < N; i++)
        {
            if (P[i][j - 1] != -1)P[i][j] = P[P[i][j - 1]][j - 1];  // no need to check this condition actually 
        }
      }
}






