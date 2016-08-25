// the add function adds strings by their index in their array 


const int MAXN=100010;
char s[MAXN];
int sz=1;
int ch[MAXN][26],value[MAXN],endno[MAXN],endd[MAXN],fail[MAXN],que[MAXN];


void add(int ind)
{
	int par=0;
	fr(i,0,strlen(s))
	{
		int c=s[i]-'a';
		if(ch[par][c]==0)
		{
			memset(ch[sz],0,sizeof(ch[sz]));
			value[sz]=0;
			endd[sz]=0;
			ch[par][c]=sz++;
			// this is the  goto edge , each vertex is named uniquely , size is the vertex number
		}

		par=ch[par][c];
	}
	value[par]=1;	// the word has finished at  vertex sz
	endd[par]=1;
	endno[ind]=par;

}

void Aho_crack()
{
	int st = 1,ed=1;

	for (int i = 0; i < 26; i++)
		if (ch[0][i])
		{
			fail[ch[0][i]] = 0;
			que[ed++] = ch[0][i];
		}

	while (st != ed)
	{
		int par = que[st++];
		for (int i = 0; i < 26; i++)
		{
			if (ch[par][i])
			{
				int v = ch[par][i];
				que[ed++] = v;
				fail[v] = ch[fail[par]][i];
				value[v] += value[fail[v]];
			}
			else
			{
				ch[par][i] = ch[fail[par]][i];
			}
		}
	}
}

int main()
{
  string s;
  cin>>s;
  
  // build the Trie by adding given strings, this can also be used for online solutions , where from a given string you 
  // have to find the occurences of all strings from the given array 
  
  	int ans = 0;
			int par= 0;
			for (int i = 1; s[i]; i++)        //checks all occurences of strings in the trei
			{
				int c = s[i] - 'a';
				par= ch[par][c];
				int temp = par;
				while (value[temp])
				{
					if (endd[temp])ans++;
					temp= fail[temp];
				}
			}
			couts(ans);
}

