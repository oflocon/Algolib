
import java.io.BufferedReader;
import java.io.*;
import java.util.*;
import java.math.*;

class TestClass {
    
    int g[][] = new int [1000005][];
    int sz[]= new int[1000005];
    int maxht[]= new int[1000005];
    int ht[]= new int[1000005];
    int vis[]= new int[1000005];
    int u[] = new int[1000007];
    int v[] = new int[1000008];
    int n;    
    Scanner s = new Scanner(System.in);
        
     public void dfs(int v,int par)
    {
        vis[v]=1;
        
        for(int i=0;i<sz[v];i++)
        {
            int u = g[v][i];
            //System.out.println("u = " + u);
            if(vis[u]==0)dfs(u,v);
        }
        
        int temp2=0,temp1=0;
        
        for(int i=0;i<sz[v];i++)
        {
            if(g[v][i]==par)continue;
            maxht[v]= Math.max(maxht[g[v][i]],maxht[v]);    
            ht[v] = Math.max(ht[v],ht[g[v][i]] + 1);
        }
        temp1=0;temp2=0;
        
        for(int i=0;i<sz[v];i++)
        {
            if(g[v][i]==par)continue;
            if(ht[g[v][i]]>=temp1){
                temp2=temp1;
                temp1=ht[g[v][i]]+1;
                
            }   
            else if(ht[g[v][i]]<temp1 && ht[g[v][i]]>=temp2)
            {
                temp2=ht[g[v][i]]+1;
            }
        }
        
        if(temp1==0 || temp2==0)maxht[v]= Math.max(maxht[v],temp1);
        else maxht[v]=Math.max(maxht[v],temp2+temp1);
        
      //  System.out.println("v=" + v + " ht[v] =" + ht[v] + " maxht[v]= " + maxht[v]);
        
    }
    
    public void solve(){
        
        
        n = s.nextInt();
        for(int i=0;i<n-1;i++)
        {
           int xu= s.nextInt();
           int xv= s.nextInt();
            u[i]=xu;v[i]=xv;
            //System.out.println("u[i] = "+ u[i] + " i = " + i );
            sz[u[i]]++;
            sz[v[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            g[i] = new int [sz[i]];
        }
        for(int i=1;i<=n;i++)sz[i]=0;
        
        for(int i=0;i<n-1;i++)
        {
            g[u[i]][sz[u[i]]++]=v[i];
            g[v[i]][sz[v[i]]++]=u[i];
            //System.out.println("u[i] = " + u[i] + "sz =" + sz[u[i]] + " v[i] = " + v[i] );
        }
        
       
    }
    
    public static void main(String args[] ) throws Exception {
            TestClass temp= new TestClass();
            temp.solve();
            temp.dfs(1,0);
            for(int i=1;i<=temp.n;i++)
            {
                System.out.print(temp.maxht[i] + " ");
                
            }
             System.out.println();
    
    }
}
