//O(n*n)

int LIS(int a[],int n)
{
    fr(i,0,n)l[i]=1;
    
    fr(i,0,n){
        fr(j,0,i)
        {
            if(a[i]>a[j] && l[i]<l[j]+1)l[i]=l[j]+1;
        }
    }
    int ma=1;
    fr(i,0,n)ma=max(ma,l[i]);
    
    re ma;
}

//O(nlog(n))


int LIS(int a[],int n)
{
    lis.pb(a[0]);
    int len=1;
    
    fr(i,0,n){
        
        if(a[i]<lis[0])lis[0]=a[i];
        if(a[i]>lis[len-1]){lis.pb(a[i]),len++;}
        
         x=lower_bound(lis.begin(),lis.end(),a[i]);
        *x=a[i];
    }
    re len;
}
