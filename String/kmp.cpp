
int lps[MAXN];
int ind[MAXN];
int x=0;


void clps(string s)
{
     lps[0]=0;
     int i=1,l=0;
     int n=s.length();

     while(i<n)
     {
         if(s[i]==s[l])l++,lps[i]=l,i++;
         else
         {
             if(l!=0)l=lps[l-1];
             else lps[i]=0,i++;
         }
     }
}

int kmp(string txt,string pat)
{
int j=0,i=0;
int n=txt.length(),m=pat.length();

while(i<n)
{
    if(pat[j]==txt[i])i++,j++;

    if(j==m)ind[x++]=i- j,j=lps[j-1];
    else if(i<n && pat[j]!=txt[i])
    {
        if(j!=0)j=lps[j-1];
        else i+=1;
    }
}
}








