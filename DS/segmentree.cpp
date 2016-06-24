int t[MAXN],n;
void build(int x,int l,int r)
{
    if(l==r)//assignment
    if(l<0 || r>n-1)re ;
    
    int mid=(l+r)>>1;
    build(2*x,l,mid);
    build(2*x+1,mid+1,r);
    
   //do your thing
}
void update(int x,int l,int r,int i,int j,int val)
{
    if(l>j || i>r)re ;
    if(l>=i && r<=j);//do update ;
    

    int mid=(l+r)/2,lt=2*x,rt=lt+1;

        update(lt,l,mid,i,j,val);
        update(rt,mid+1,r,i,j,val);

   // unify the child nodes into parent
}

ll query(int x,int l,int r,int i,int j)
{
    if(l>j || i>r )re 0;
    if(l>=i && r<=j );//re main query
    
    
      int mid=(l+r)/2,lt=2*x,rt=lt+1;
      ll q1=query(lt,l,mid,i,j);
      ll q2=query(rt,mid+1,r,i,j);

      //unify query 
      //re query
}

int main()
{
     build(0,0,n-1);//look for 0 or 1 according to given conditions    
}
