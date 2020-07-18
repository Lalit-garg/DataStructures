#include<bits/stdc++.h>
using namespace std;
int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout<<q.size()<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	cout<<q.front()<<endl;
	return 0;
}
