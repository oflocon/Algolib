//<O(n),O(n)>

// the other implementation is far better than this in terms of query 

int LCA(int v,int u)
{
	if(v==u)re v;
	if(h[v]<h[u])swap(u,v);

	re LCA(par[v],u);
}

``````````````````````````````````````````````````````````````

//using sqrt decompostion
//<O(n),O(sqrt(n))>
//sparse table 
//<O(nlog(n)),O(1)>
//dp
//<O(nlogn,logn)>  this is implemented 
//Advance RMQ
//<O(n),O(1)> 
