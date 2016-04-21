
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



int isprime(int x)                // if a single prime is given use this test ,for multiples use above one.//
{
    fr(i,2,sqrt(x)+1){if(x%i==0)re 0;}
     re 1;
}


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










