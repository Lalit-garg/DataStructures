#include<bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
	public:
	T data;
	node<T> *next;
	node(T element)
	{
		this->data=element;
		next=NULL;
	}
};
template <typename T>
class Queue
{
	node<T> *head;
	node<T> *tail;
	int size;
	public:
	Queue()
	{
		size=0;
		head=NULL;
		tail=NULL;
	}
	int getsize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size==0;
	}
	T front()
	{
		return head->data;
	}
	void enqueue(T element)
	{
		node<T> *newnode;
		newnode=new node<T>(element);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else {
		tail->next=newnode;
		tail=newnode;
		}
		size++;
	}
	T dequeue()
	{
		T x=head->data;
		node<T> *temp;
		temp=head;
		head=head->next;
		delete temp;
		size--;
		return x;
	}
};
int main()
{
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getsize()<<endl;
	cout<<q.isEmpty()<<endl;
	return 0;
}
