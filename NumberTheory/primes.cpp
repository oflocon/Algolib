
bool isPrim[100010];
int arr[100010];
vector <ll > sol,primes;

void sieveprecal()
{
	ll i,j;
  	for(i=2; i < 100010;i++)
   	 {
		if(arr[i] == 0)               // marks prime numbers using sieve
        	{ 
	   	 primes.pb(i);
            	isPrim[i]=1;
            	j=i;
  	    	while(j <100010){arr[j] = 1;j+=i;}

	 	}
    	
    	}
}
////////////////////////////////////////////////////////////////////////////////////////

void sieveandlcmprefix()             //using sieve for calculation of prefix lcm
{
  	lcm[1]=1;lcm[0]=0;
 	 for(int i=2; i < 300010;i++)
    	{
		if(!arr[i])
        	{
            		int j=i;
			while(j <300010){arr[j] = i;j+=i;}
        	}
        	 int  p=arr[i],j=i;
         	while(j%p==0)j/=p;

        	if(j==1)lcm[i]=(lcm[i-1]*p)%MOD;
         	else lcm[i]=lcm[i-1];

     	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
prime sieve

int sieved[200110];

void sieve(ll a ,ll b)              // sieve from a to b ,where range of a and b can be between int 
{
	ll i,j,k,flag,st=a;

     	memset(sieved,-1,sizeof sieved);

    for(i =0;i < primes.size();i++)
    {
          j = a/primes[i];
          if(j < 2)j = 2;

          while(1)
          {
                int prod = j*primes[i];
		if(prod > b)break;
                if(prod >= a)sieved[prod-a] = 1;
		j++;
          }
    }
		//for(i= 0;i <= b-a;i++)if(sieved[i] == -1)//its a prime //cout << i + a << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
euler sieve for small numbers 

void phi()                 //phi function 
{

  	int phi[MAXN];

  	fr(i,2,n+1)phi[i]=i;

  	fr(i,2,n+1)
  	{
    		if(phi[i]==i)
    		{
        		for(int j=i;j<=n;j+=i)phi[j]=(phi[j]/i)*(i-1);
    		}
  	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
euler sieve

void sieve(ll a ,ll b)              // sieve from a to b ,where range of a and b can be between int
{
	ll j,k,st=a,i;

     	fr(i,0,b-a+1)r[i]=phi[i]=a+i;

	for(i =0;i < primes.size();i++)
	{
		j = a/primes[i];
		if(j < 2)j = 2;

		while(1)
		{
			int prod = j*primes[i];
			if(prod > b)break;
			if(prod >= a)
			{
				phi[prod-a]-=(phi[prod-a]/primes[i]);
				while(r[prod-a]%primes[i]==0)r[prod-a]/=primes[i];
			}
			j++;
		}
	}
	
    for(i= 0;i <= b-a;i++)if(r[i]>1)phi[i]-=phi[i]/r[i];

    for(i=0;i<=b-a;i++)printf("%d\n",phi[i]);

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
mobius function

// calculate mobius for every value upto MAXN,first is for smallest prime fators
ll mob[MAXN];int p[MAXN];

void sieve()
{
	p[1]=1;
	fr(i,2,MAXN)
	{
		if(p[i]==0)
		{
			for(int j=i;j<MAXN;j+=i)if(p[j]==0)p[j]=i;
		}
	}
}

void mobius()
{
	mob[1]=1;
	fr(i,2,MAXN)
	{
		if(p[i/p[i]]==p[i])mob[i]=0;
		else
		{
			mob[i]=-1*mob[i/p[i]];
		}
	}
}









