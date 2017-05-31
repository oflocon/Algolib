#include <bits/stdc++.h>
using namespace std;

void max_heapify(int a[],int i, int n)
{
	int left=2*i;
	int right =2*i+1;
	int largest=i;

	if(left<=n && a[left]>a[i])largest=left;
	else largest =i;

	if(right<=n && a[right]>a[largest])largest=right;

	if(largest!=i)
	{
		swap(a[largest],a[i]);
		max_heapify(a,largest,n);
	}
}	

void build_heap(int a[], int n)
{
	for(int i=n/2;i>=1;i--)
		max_heapify(a,i,n);
}

int getmaxp(int a[])
{
	return a[1];
}

void rep(int a[],int i,int val)
{
	if(a[i]>val)return ;

	a[i]=val;
	
	while(i!=1 && a[i/2]<a[i])
	{
		swap(a[i/2],a[i]);
		i/=2;
	}
}



void heapsort(int a[],int n)
{
	int sz=n;

	build_heap(a,n);

	for(int i=n;i>=2;i--)
	{
		swap(a[i],a[1]);
		sz--;
		max_heapify(a,1,sz);
	}

	for(int i=1;i<=n;i++)cout<<a[i]<<endl;

}

int main()
{
	int a[]={1,5,3, 4, 6, 10,9};
	//heapsort(a,6);
	build_heap(a,6);
	int x=getmaxp(a);
	cout<<x<<endl;

	rep(a,2,11);
	x=getmaxp(a);
	cout<<x<<endl;
}
