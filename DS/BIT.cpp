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
typedef long long int ll;
typedef vector<int> vi;

const int MAXN=2e4+10;
map<ll,ll>mp;
vector<int> v,ans;
int a[MAXN],

struct FT{
    vector<int>v;
    FT();
    public:
    void init(vector<int>v);
    void add(int idx,int d);
    ll getssum(int r);
    ll sum(int l,int r);
}

void FT::init(vector<int> v)
{
    v.assign(n,0);
    fr(i,0,v.size())add(i,a[i]);
}

void FT::add(int idx,int d)
{
    while(idx<n)
    {
        v[idx]+=d;
        idx+=(idx & -idx);
    }
}
ll FT::getsum(int r)
{
    ll res=0;
    while(r)
    {
        res+=v[r];
        r-=(r&-r);
    }
    re res;
}

ll FT::sum(int l,int r)
{
    re (getsum(r)-getsum(l-1));
}
int main()
{
    FT bit;
    int n;
    cin>>n;
    fr(i,0,n)cin>>a[i];
    bit.init(v);
    


}
