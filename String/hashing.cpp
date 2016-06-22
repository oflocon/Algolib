
int h[MAXN],rh[MAXN];

ll powd(ll a,ll b)
{
    ll x=1,y=a;
    
    while(b>0)
    {
        if(b%2==1)x*=y;
        x%=MOD;
        y*=y;
        y%=MOD;
        b/=2;
    }
    re x;
}

ll modinv(ll x){ re powd(x,MOD-1); }

void gethash(string s)
{
    ll temp=0;
    
    fr(i,1,s.length()+1)
    {
        temp+=(s[i-1]*powd(p,i))%MOD;
        temp%=MOD;
        h[i]=temp;
    }
    temp=0;
    string t="";
    
    rf(i,s.length()-1,0)t+=s[i];
    
    fr(i,1,t.length())
    {
        temp+=(t[i-1]*powd(p,i))%MOD;
        temp%=MOD;
        rh[i]=temp;
    }
}
