#include<bits/stdc++.h>
using namespace std;
void  merge(int *a,int s,int e)
{
	int mid=(e+s)/2;
	int i=s;
	int k=s;
	int j=mid+1;
	int temp[100];
	while(i<=mid && j<=e)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=e)
		temp[k++]=a[j++];

	for(int i=s;i<e;i++)
		a[i]=temp[i];

}
void mergesort(int a[],int s,int e)
{
	if(s>=e)
		return;
	int mid=(s+e)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	merge(a,s,e);
	
}
int main()
{
	cout<<"enter length=";
	int n;
	cin>>n;
	int a[100];
	int i;
	cout<<"Enter elements-";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
