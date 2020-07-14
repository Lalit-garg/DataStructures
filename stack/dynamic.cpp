#include<bits/stdc++.h>
using namespace std;
class Stack
{
	int *a;
	int next;
	int capacity=2;
	public:
	Stack()
	{
		
		a=new int[capacity];
		next=0;
		
	}
	void push(int i)
	{
		if(next==capacity)
		{
			int *newa=new int[2*capacity];
			for(int t=0;t<capacity;t++)
				newa[t]=a[t];
			delete [] a;
			a=newa;
		
		capacity=2*capacity;
		}
		a[next]=i;
		next++;
		
	}
	int top()
	{
		if(next>0)
			return a[next-1];
		else cout<<"Stack is empty";
	}
	int pop()
	{
		if(next>0)
		{
			next--;
			return a[next];
		}
		else cout<<"stack is empty";
	}
	int size()
	{
		return next;
	}
	bool isEmpty()
	{
		return next==0;
	}

};
int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(50);
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.top()<<endl;
	return 0;
}
