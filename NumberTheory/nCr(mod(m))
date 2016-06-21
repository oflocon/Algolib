
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

ll countfact(ll n,ll p)
{   
    ll ans=0;
    while(n>0)
    {
        ans+=n/p;
        n/=p;
        
    }
    re ans;
}

ll modinv(ll x)
{
    re powd(x,MOD-2);
}

ll nCr(ll n,ll r)
{
    ll res=1;
    vector<bool>isprime(n,1);
    
    fr(i,2,n+1)
    {
        if(isprime[i])
        {
            for(int j=2*i;j<=n;j+=i)isprime[j]=0;
            int p=0;
            p=countfact(n,i)-countfact(r,i)-countfact(n-r,i);
            res*=(powd(i,p));
            res%=MOD;
        }
    }
    re res;
}
