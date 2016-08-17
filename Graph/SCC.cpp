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
map<int,int>mp;
vector<int>g[5002],g2[MAXN],sol;

int v[5002],compo[MAXN],soln[MAXN];

void dfs(int x){
    v[x]=1;
    fr(i,0,g[x].size())
    {
       if(!v[g[x][i]])dfs(g[x][i]);
    }
    sol.pb(x);
}
void dfs2(int x,int cn){
    v[x]=0;
    compo[x]=cn;
    fr(i,0,g2[x].size()){
        if(v[g2[x][i]])dfs2(g2[x][i],cn);
    }
}

int main()
{
    int n,e;
    while(1){    
    
        
        cin>>n;
        if(n==0)break;
        sol.clear();
        fr(i,1,n+1){soln[i]=0;g[i].clear();g2[i].clear();compo[i]=0;v[i]=0;}
        
        
        cin>>e;
    
        fr(i,0,e)
        {
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g2[v].pb(u);//reverse graph
        }
    
    int com=0;    
    fr(i,1,n+1)if(!v[i])dfs(i);
    
    rf(i,sol.size()-1,0)
     if(v[sol[i]])
     {
        dfs2(sol[i],com++); // starting from sink and then finding number of components
        soln[com-1]=true;
     } 

    fr(i,1,n+1)
    {
        fr(j,0,g[i].size())
        {
            if(compo[i]!=compo[g[i][j]])
            {
                 soln[compo[i]]=false;    //the components in not valid
                 break;
            }
        }
    }    

    fr(i,1,n+1)if(soln[compo[i]])cout<<i<<" ";   //prints each node in SCC
    cout<<endl;

    } 
}
