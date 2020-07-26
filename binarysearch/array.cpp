#include<bits/stdc++.h>
using namespace std;
bool binary(int a[],int low,int high,int e)
{
	int mid=low+((high-low)/2);
	if(low>high)
		return 0;
	else if(a[mid]==e)
	{
		return 1;
	}
	else if(a[mid]>e)
	{
		high=mid-1;
		return binary(a,low,high,e);
	}
	else if(a[mid]<e)
	{
		low=mid+1;
		return binary(a,low,high,e);
	}

}
int main()
{
	int *a,n=10;
	a=new int[n];
	cout<<"enter "<<n<<" elements-";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int e,low=0,high=n-1;
	cout<<endl<<"Enter element want to search-";
	cin>>e;
	cout<<binary(a,low,high,e);
	return 0;
}
