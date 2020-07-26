#include<bits/stdc++.h>
using namespace std;
int  partition(int *a,int s,int e)
{
	int x=a[s];
	int i=s;
	int j=e;
	int count=0;
	for(int i=s+1;i<=e;i++)
	{
	if(a[i]<x)
		count++;
	}
	cout<<"count-"<<count<<endl;
	a[s]=a[count+s];
	a[count+s]=x;
	while(i<count+s && j>count+s)
	{
		if(a[i]<=x)
			i++;
		else if(a[j]>x)
			j--;
		else
		{
			int temp=a[i];
			a[i++]=a[j];
			a[j--]=temp;
		}
	}
	return count+s;
}
void quicksort(int a[],int s,int e)
{
	if(s>=e)
		return;
	int c;
	c=partition(a,s,e);
	cout<<"c="<<c<<endl;
	quicksort(a,s,c-1);
	quicksort(a,c+1,e);
	
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
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
