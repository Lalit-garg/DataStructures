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
		Queue()
		{
			size=0;
			a=new T[4];
			next=0;
			first=-1;
			capacity=4;			
		}
		void enqueue(T element)
		{
			if(size==capacity)
			{
				T *data;
				int j=0;
				data=new T[2*capacity];
				for(int i=first;j<size;(i+1)%capacity)
				{
					data[j]=a[i];
					j++;
				}
				delete [] a;
				a=data;
				capacity=2*capacity;
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
	Queue<int> q;
	cout<<q.isEmpty()<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout<<q.getsize()<<endl;
	q.enqueue(50);
	cout<<q.getsize()<<endl;
	q.enqueue(60);
	q.enqueue(70);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getsize()<<endl;
        return 0; 
}
