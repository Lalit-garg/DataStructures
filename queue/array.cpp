#include<bits/stdc++.h>
using namespace std;                        
template <typename T>
class Queue
{
	int size;
	T *a;
	int next;
	int capacity;
	int first;
	public:
		Queue(int n)
		{
			size=0;
			a=new T[n];
			next=0;
			first=-1;
			capacity=n;			
		}
		void enqueue(T element)
		{
			if(size==capacity)
			{
				cout<<"queue is full";
				return;
			}
			a[next]=element; 
                        next=(next+1)%capacity;
			if(first==-1)
				first=0;
			size++; 
                } 
		T dequeue()
		{	
			if(first==-1)
			{
				cout<<"Queue is empty";
				return -1;
			}			

			if(first!=-1)
			{
				int x=first;
				first=(first+1)%capacity;
				size--;
				if(size==0)
				{
					first=-1;
					next=0;
				}
				return a[x];
			}
		}
		T front()
		{
			if(first==-1)
			{
				cout<<"Queue is empty";
				return -1;
			}
			return a[first];
					
		}
                int getsize() 
                { 
                        return size; 
                } 
                bool isEmpty() 
                { 
                        return size==0; 
                } 
 
}; 
int main() 
{ 
	Queue<int> q(5);
	cout<<q.isEmpty()<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getsize()<<endl;
        return 0; 
}
