#include<bits/stdc++.h>
using namespace std;
class Stack
{
	int *a;
	int next;
	int n;
	public:
	Stack(int tn)
	{
		n=tn;
		a=new int[n];
		next=0;
	}
	void push(int i)
	{
		if(next<n)
		{
			a[next]=i;
			next++;
		}
		else cout<<"Stack is full"<<endl;
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
	Stack s(3);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(50);
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.top()<<endl;
	return 0;
}
