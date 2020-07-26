#include<bits/stdc++.h>
using namespace std;
int j=0;
int* selection(int a[],int n)
{
	cout<<a[j];
	if(j==n-1)
		return a;
	int min=j;
	for(int i=j+1;i<n;i++)
	{
		if(a[min]>a[i])
		{
			min=i;
		}
	}
	int temp;
	temp=a[min];
	a[min]=a[j];
	a[j]=temp;
	cout<<a[j];
	j++;

	return selection(a,n);
}
int main()
{
	int *a;
	cout<<"enter length=";
	int n;
	int i;
	cin>>n;
	a=new int[n];
	cout<<"Enter elements-";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a=selection(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}	
	return 0;
}
