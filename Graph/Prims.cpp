
void Prim(vector<int> g[],int n)
{
    fill(d,d+n,inf);
    set<pair<int,int> >st; //can use priority queue here similarly, set keeps them sorted 
    int v;
    
    while(!st.empty())
    {
        v=st.begin()->second;
        st.erase(st.begin());
        
        fr(i,0,g[v].size()){
            int u=g[v][i];
            int wt=mp[v][u];
            if(d[u]>wt){
                st.erase(mpk(d[u],u));
                d[u]=wt;
                st.insert(mpk(d[u],u));
            }
        }
    }
    
}
