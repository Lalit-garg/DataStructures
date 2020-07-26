#include<bits/stdc++.h>
using namespace std;
int* bubble(int a[],int n)
{
	int swap=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
			int temp;
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			swap=1;
			}
		}
		if(swap==0)	
			return a;
		swap=0;
	}
	return a;
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
	a=bubble(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}	
	return 0;
}
