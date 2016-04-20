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

const int MAXN=2e5+10;

vi g[MAXN];
int v[MAXN],d[MAXN];
map<int,int>mp[MAXN];

void bfs()
{
    v[1]=1;     // visited 1 which is also the starting node 
    d[1]=0;     // distance of 1 is 0 since it is the starting point 
    deque<int>q;
    q.pb(1);

    while(!q.empty())
    {
         int x=*q.begin();
         q.pop_front();
         couts(x);
        
         fr(i,0,g[x].size())
         {
            int w=g[x][i];
            if(v[w]!=1)        //mp[x][w] is the current distance from u to w 
            {
               q.pb(w);v[w]=1;
            }
         }
    }
}


int main()
{
    g[1].pb(2);g[2].pb(1);
    g[1].pb(3);g[3].pb(1);
    g[2].pb(4);g[4].pb(2);
    g[3].pb(5);g[5].pb(3);
    
    bfs();
}
