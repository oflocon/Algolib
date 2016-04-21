/*Simplicity and Fortitude */
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
typedef long long int ll;
typedef vector<int> vi;

const int MAXN=1e5+10;

vi g[MAXN];
int cycle=0,nodes,v[MAXN];

void dfs(int x,int p)
{
    v[x]=1;
    
    fr(i,0,g[x].size())
    {
        int y=g[x][i];
        if(y!=p && v[y]==1){cycle=1;}       //cycle found
        if(y!=p && v[y]==0)dfs(y,x);
    }
  
}

bool istree(){
    cycle=0;
    
    dfs(1,0);
    fr(i,1,nodes+1)if(v[i]!=1)re false;  // even if atleast one vertex remains unvisited then its not a tree
    
    if(cycle==1)re false; // if cycle exists then also it is not a tree
    
    re true;
    
}


int main()
{
  int edges;
  cin>>nodes>>edges;
  
  fr(i,0,edges){
      int u,v;
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
      
  }
  
  cout<<istree();
  
}
