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
			node<T> *temp(element);
			temp->next=head;
			head=temp;
			size++;
		}

		T pop()
		{
			T x;
			if(head==NULL)
			{
				cout<<"Stack is Empty";
			}
			else{
				x=head->data;
				head=head->next;
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
	cout<<s.isEmpty();
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.top();
	return 0;
}
