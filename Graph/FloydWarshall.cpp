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

int vis[MAXN],d[MAXN];
map<int,int>mp[MAXN];

int dist[1002][1002];// take care of max limit 
int g[1002][1002];

void FW(int v)               // floyd warshall
{
        fr(i,0,v)
            fr(j,0,v)
              dist[i][j] = g[i][j];  // only if i and j are connected else d[i][j]=inf; put that into code 
 
  
    fr(k,0,v)
    {
        fr(i,0,v)
        {
            fr(j,0,v)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
  
  
}
  
int main(){
    
    int edges,n;
    cin>>n>>edges;
    
    fr(i,0,edges){
        int u,v,x;
        cin>>u>>v>>x;
        g[u][v]=x;
    }
    
    FW(n);
}
