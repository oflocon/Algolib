void dijkstra(int v){
    //v is the source vertex
    fill(d,d+n,inf);
    d[v]=0;//starting vertex distance 0 from itself
        
    set<pi>st;
    st.insert(mpk(d[v],v));
    int f;
    //hear g is graph with ff as edge wt,ss.ff as 1st vertex,ss.ss as 2nd 
    while(!st.empty()){
        f=st.begin()->ss;
        st.erase(st.begin());
        
        fr(i,0,g[v].size()){
            int x=g[v][i];
            if(d[x.ss.ff]>d[f]+x.ff){
                st.erase(mpk(d[x.ss.ff],x.ff));
                d[x.ss.ff]=d[f]+x.ff;
                st.insert(d[x.ss.ff],x.ss.ff);
            }
        }
        
    }
   
}
