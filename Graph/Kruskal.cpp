//sort the edges in ascending order of their weight ,then in ordero of sorted array 
//we add each edge if and only if no cyle if detected after adding (using DSU)

void Kruskal(){

 //sort all edges in ascending order of wt
 sort(g,g+m); //here g is pair of int and pair int is wt pair is the 2 vertices
 int ans=0;
 for(i,0,m){
 int wt=g[i].ff;
 int u=g[i].ss.ff;
 int v=g[i].ss.ss;
 if(check(v,u)==0)ans+=wt; //checks if u and v are connected already with dfs not including the yet to add edges
 
}
