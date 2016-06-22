const int MAXN=2e5+10;
int ran[MAXN],p[MAXN];


void init(int n)
{
    fill(ran,ran+n,0);
    fr(i,0,n)p[i]=i;
}
int root(int x)
{
    re x==p[x]?x:root(p[x]);
}
void unify(int a,int b)
{
    a=root(a);
    b=root(b);
    if(a==b)re ;
    if(ran[b]>ran[a])swap(a,b);
    if(ran[a]==ran[b])ran[a]++;
    p[b]=a;
}
