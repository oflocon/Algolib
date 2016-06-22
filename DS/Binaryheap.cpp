const int MAXN=2e6+10;
int val[MAXN];

class Binhp{

    
    public:
    int heap[MAXN];
    int size;
    Binhp(){};
    void build();
    void removemin();
    void add(int val);
    void goup(int pos);
    void godown(int pos);
};

void Binhp::build()
{
    fr(i,0,size)heap[i]=val[i];
}

void Binhp::removemin()
{
    heap[0]=heap[--size];
    godown(0);
}

void Binhp::add(int val)
{
    heap[++size]=val;
    goup(size);
}

void Binhp::goup(int pos)
{
    while(pos>0)
    {
        int par=(pos-1)/2;
        if(par<0)break;
        if(heap[pos]>=heap[par])break;
        swap(heap[pos],heap[par]);
        pos=par;
    }
}

void Binhp::godown(int pos)
{
    while(1)
    {
        int ch=2*pos+1;
        if(ch>=size)break;
        if(ch+1<size && heap[ch]<heap[ch+1])ch++;
        if(heap[ch]>=heap[pos])break;
        swap(heap[ch],heap[pos]);
        pos=ch;
    }
}
