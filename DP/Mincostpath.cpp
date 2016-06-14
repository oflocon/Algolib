//  O(m*n)
  
  int minc(int x,int y)
       {
           int s=0;
           
           fr(i,0,m)s+=c[0][i],dp[0][m]=s;
           s=0;
           fr(i,0,n)s+=c[i][0],dp[i][0]=s;
           
           dp[0][0]=c[0][0];
           fr(i,1,x)
           fr(j,1,y)
           {
               int temp=min(dp[i-1][j],dp[i][j-1]);
               
               dp[i][j]=min(temp,dp[i-1][j-1])+c[i][j];
           }
           
           re dp[x-1][y-1];
       }
