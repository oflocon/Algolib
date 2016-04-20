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
#define inf (1<<20)

const int MAXN=2e5+10;

vector<pi> g[MAXN];
int vis[MAXN],d[MAXN];
map<int,int>mp[MAXN];



struct compare{
    
    bool operator()(const pi &a,const pi &b){
        re a.second>b.second;
    }
};

priority_queue<pi,vector<pi>,compare>q;

void solve()
{
   int u,v,w,sz,nodes,st,edges;
   
   cin>>nodes>>edges;  // input the number of nodes and edges
   
   fr(i,0,edges)
   {
       cin>>u>>v>>w;
       g[u].pb(pi(v,w));
       g[v].pb(pi(u,w));   // do only undirected graph
   }
   
   cin>>st;  // the vertex form which shortest path is to be calculated 
   
   fr(i,1,nodes+1)d[i]=inf;
   
   d[st]=0; // distance from itself is 0
   q.push(pi(st,0));
   
   // find the shortest distance to each vertex using bfs
   
   while(!q.empty()){
       
       u=q.top().ff;
       q.pop();
       
       if(vis[u])continue;
       sz=g[u].size();
       
       fr(i,0,sz)
       {
            v=g[u][i].ff;  //node
            w=g[u][i].ss;  //weight
            
            if(!vis[v] && d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push(pi(v,d[v]));
            }
       }
       vis[u]=1;
   }
   
   fr(i,1,nodes+1){          //take care of indexing here 
       coutd(i,d[i]);
   }
 
}

int main(){
    
    solve();
    
}
