
ll powd(ll a, ll b)
{
    ll x=1,y=a;
    
    while(b>0)
    {
        if(b%2==1)x*=y,x%=MOD;
        y*=y;y%=MOD;
        b/=2;
    }
    re x;
}
