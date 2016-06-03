//O(n*m)

int LCS(string s1,string s2,int n,int m)
{
    int l[n+1][m+1];
    
    fr(i,0,n+1)
    {
        fr(j,0,m+1)
        {
            if(i==0 || j==0)l[i][j]=0;
            
            else if(s1[i-1]==s2[j-1])l[i][j]=l[i-1][j-1]+1;
            
            else
            {
                l[i][j]=max(l[i][j-1],l[j-1][i]);
            }
        }
    }
    re l[n][m];
}
