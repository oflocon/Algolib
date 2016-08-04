// for simple pair
struct compare{
   bool operator()(const pi &a,const pi &b){
       re a.second>b.second;
    }
};

//for pair of int and pair
struct compare{
   bool operator()(const pair<int,pi> &a,const pair<int,pi> &b){
       if(a.ff==b.ff)re a.ss.ff>b.ss.ff;
       else re a.ff>b.ff;
    }
};
// gives ascending order 
