ll powd(ll a,ll b)
{
	ll c = 1, d = a;
	while (b)
	{
		if (b & 1) c = (c*d) % MOD;
		d = (d*d) % MOD;
		b >>= 1;
	}
	return c;
}
