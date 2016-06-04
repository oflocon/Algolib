//O(n)
finds array of max in subarray of size k 

int maxk(int x,int m,int k)
{
    deque<int>q;
    // k is the length of subarray
    
    fr(i,0,k){
        
        while(!q.empty() && A[i]>=A[q.back()])q.pop_back();//remove useless elements 
        q.push_back(i);//greater found so put it there
    }
    int t=0;
    
    fr(i,k,m){
        
        B[t++]=A[q.front()];
        
        while(!q.empty() && q.front()<=i-k)q.pop_front();
        while(!q.empty() && A[x][i]>=A[x][q.back()])q.pop_back();
        
        q.push_back(i);
    }
    B[t++]=A[q.front()];
    re t; 
}
