
int trie[27][MAXN],ed[MAXN],vis[MAXN];
int sz=0;

void add(string s)
{
	int v=0;
	fr(i,0,s.size())
	{
		int c=s[i]-'a';
		if(!vis[trie[c][v]])
		{
			trie[c][v]=++sz;
			vis[trie[c][v]]=1;
		}
		v=trie[c][v];
	}
	ed[v]++;
}
int search(string s)
{
	int v=0;
	fr(i,0,s.size())
	{
		int c=s[i]-'a';
		if(!vis[trie[c][v]])re 0;
		v=trie[c][v];
	}
	re ed[v]>0;
}
