    // Implementation of Andrew's monotone chain 2D convex hull algorithm.
    // Asymptotic complexity: O(n log n).
    
    struct point{
        int x,y;// can be changed to double
    
        bool operator< (const point &p) const{
            re x<p.x || (x==p.x && y<p.y);
        }
    };
    vector<point>H; 
    int orient( point p1, point p2, point p3)
    {
        re (p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p1.x);
    }
    
    vector<point>hull(vector<point> p)
    {
        int n=p.size();
        int k=0;
        vector<point>h(2*n);
        
        sort(p.begin(),p.end());
        
        fr(i,0,n)//builds the lower hull
        {
            while(k>=2 && orient(H[k-2],H[k-1],p[i])>=0)k--;
            H[k++]=p[i];
        }
        
        for(int i=n-2,t=k+1;i>=0;i--)//builds the upper hull
        {
            while(k>=t && orient(H[k-2],H[k-1],p[i])>=0)k--;
            H[k++]=p[i];
        }
        H.resize(k-1);
        re H;
        
    }
    
