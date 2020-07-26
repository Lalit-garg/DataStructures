#include<bits/stdc++.h>
using namespace std;
int* insertion(int a[],int n)
{
	int j;
	for(int i=1;i<n;i++)
	{
		j=i;
		while(j>0 && a[j]<a[j-1])
		{
			int temp;
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			j--;
		
		}
	
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
	a=insertion(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}	
	return 0;
}
