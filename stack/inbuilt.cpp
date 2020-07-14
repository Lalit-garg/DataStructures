#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.empty()<<endl;
	cout<<s.size();
	return 0;
}
