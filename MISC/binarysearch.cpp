ll bs(ll k)
{
    ll l=0,r=n-1;
    
    while(l<r)
    {
       
        ll mid=l+(r-l)/2;      //this avoids any possible overflow
        
        if(k==a[mid])re l;
        if(k<a[mid])
            r=mid;
        else
            l=mid+1;
            
    }
    re l;
}
    
  
