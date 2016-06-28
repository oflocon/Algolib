 /*What is dead may never die, but comes back stronger and faster */
#include <bits/stdc++.h>
#define ff first
#define re return
#define ss second
#define pb push_back
#define mpk make_pair
#define MOD 1000000007
#define couts(a) cout<<a<<endl
#define fr(i,a,b) for(ll i=a;i<b;++i)
#define rf(i,a,b) for(ll  i=a;i>=b;--i)
#define coutd(a,b) cout<<a<<" "<<b<<endl
#define ioS ios_base::sync_with_stdio(0);cin.tie(0);
#define coutt(a,b,c)cout<<a<<" "<<b<<" "<<c<<endl;
#define coutar(a,n)  fr(i,0,n)cout<<a[i]<<" ";cout<<endl;
#define coutq(a,b,c,d)cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

# define PI 3.141592653589793238462643383279502

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int>pi;
const int MAXN=2e6+10;

vector<int> g[MAXN];
int par[MAXN],ctrd[MAXN],sz[MAXN],bigt[MAXN];

void dfs(int x, int p)
{
    par[x]=p;
    bigt[x]=0;
    sz[x]=1;
    
    
    fr(i,0,g[x].size())
    {
        int v=g[x][i];
        dfs(v,x);
        sz[x]+=sz[v];
        bigt[x]=max(bigt[x],sz[v]);
    }
    
}
int check(int v, int x)
{
  //  coutq(v,sz[v],x,sz[x]);
    if(2*bigt[x]<=sz[v] && 2*(sz[v]-sz[x])<=sz[v])re 1;
    else re 0;
}

void centroid_find(int v,int p)
{
    if(sz[v]==1)ctrd[v]=v;
    
    
     else
    {
        
        int ct=0;
        
        fr(i,0,g[v].size())
        {
            int u=g[v][i];
            if(u!=p )centroid_find(u,v);
            if(sz[g[v][ct]]<sz[g[v][i]])ct=i;
        }
        int temp=ctrd[g[v][ct]];
        
         while(!(check(v,temp))){temp=par[temp];}
        ctrd[v]=temp;
    }
   
}


int main()
{
    ioS;
    int n,q;
    cin>>n>>q;
    
    fr(i,2,n+1)
    {
        int x;
        cin>>x;
        g[x].pb(i);
        
    }
    dfs(1,1);
    centroid_find(1,1);
    
   // fr(i,1,n+1)cout<<bigt[i]<<" ";cout<<endl;
    
    fr(i,0,q)
    {
        int v;
        cin>>v;
        couts(ctrd[v]);
    }
    
}
