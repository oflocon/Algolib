// O(n*W);
 
 int ks(int W)
       {
            int dp[n+1][W+1];
 
  
             fr(i,0,n+1)
                 fr(j,0,W+1)
                 {
                     if (i==0 || w==0)dp[i][w] = 0;
                     else if (wt[i-1] <= w)
                        dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],dp[i-1][w]);
                     else dp[i][w] = dp[i-1][w];
                }
   
 
            re dp[n][W];
            
       }
