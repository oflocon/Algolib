//O(n*m) 

int medit(string s1,string s2,int n,int m)
{
     
     int j=0;
     int dp[n+2][m+2];
     
     fr(i,0,n+1)
     {
        fr(j,0,m+1)
        {
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
                
            else {
                int x=min(dp[i-1][j-1],dp[i][j-1]);
                int y=min(x,dp[i-1][j]);
                dp[i][j]=1+y;
                
            }
        }
         
     }
    re dp[n][m];
}
