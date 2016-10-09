//blog link -http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K=2;

// using 1 - based indexing here ,careful !!

matrix mul(matrix A, matrix B)
{
	matrix res(K+1,vector<ll>(K+1));

	fr(i,1,K+1)fr(j,1,K+1)fr(k,1,K+1)
		res[i][j]=(res[i][j]+A[i][k]*B[k][j])%MOD;

	re res;
}

matrix powd(matrix A, int p)
{
	if(p==1)re A;
	if(p%2)re mul(A,powd(A,p-1));

	matrix x=powd(A,p/2);
	re mul(x,x);
}

///////////////////////////////////////////
example of calculating nth fibonacci number n<=10^18

ll fib(ll n)
{
	vector<ll>F1(K+1);
	F1[1]=1;F1[2]=1;   // the original K - term matrix

	matrix T(K+1,vector<ll>(K+1));// initialization

	// defining transformation matrix
	T[1][1]=0;T[1][2]=1;
	T[2][1]=1;T[2][2]=1;

	//T*F(i)=F(i+1)   recurrence relation
	if(n==1)re 1;
	T=powd(T,n-1);

//	fr(i,1,K+1){{fr(j,1,K+1)cout<<T[i][j]<<" ";}cout<<endl;}

	ll res=0;
	fr(i,1,K+1)res+=(T[1][i]*F1[i])%MOD;

	re res;
}
