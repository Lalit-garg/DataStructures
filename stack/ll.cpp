#include<bits/stdc++.h>
using namespace std;
template <typename T>

class node
{
public:
	T data;
	node<T> *next;
	node(T data)
	{
		this->data=data;
		next=NULL;
	}
};
template <typename T>

class Stack
{
int size;
node<T> *head;
	public:
		Stack()
		{
			size=0;
			head=NULL;
		}

		T getsize()
		{
			return size;
		}

		bool isEmpty()
		{
			return head==NULL;
		}

		void push(T element)
		{
			node<T> *temp=new node<T>(element);
			temp->next=head;
			head=temp;
			size++;
		}

		T pop()
		{
			if(head==NULL)
			{
				cout<<"Stack is Empty";
				return ;
			}
			else{
				T x;
				x=head->data;
				node<T> *temp=head;
				head=head->next;
				delete temp;
				size--;
				return x;
			}
		}

		T top()
		{
			return head->data;
		}
};
int main()
{
	Stack<int> s;
	cout<<s.isEmpty()<<endl;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.top();
	return 0;
}
