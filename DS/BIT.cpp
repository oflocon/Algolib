int n,a[MAXN];


class FT{

    public:
    vector<int>v;
    FT(){};
    
    void init()
    {
       
        fr(i,0,n){v.pb(0);}
        fr(i,0,v.size())add(i,a[i]);
    }
    void add(int idx,int d){
         while(idx<n)
        {
            v[idx]+=d;
            idx|= idx + 1;
        }
    }
    
    ll getsum(int i)
    {
        ll res=0;
        while(i>=0)
        {
            res+=v[i];
            i = (i & (i + 1)) - 1;
        }
        re res;
    }
    ll sum(int l,int r)
    {
        re (getsum(r)-getsum(l-1));
    }
};
