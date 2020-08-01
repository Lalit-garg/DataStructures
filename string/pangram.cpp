#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<bool> v;
	for(int i=0;i<26;i++)
		v.push_back(0);
	string s="The quick brown fox jumps over the dog";
	for(int i=0;i<s.size();i++)
	{
		int x=s[i];
		if(x>96 && x<123)
			v[x-97]=1;
		else if(x>64 && x<91)
			v[x-65]=1;
	}
	for(int i=0;i<26;i++)
	{
		if(v[i]==0)
		{
			cout<<"Not pangram";
			i=26;
			return 0;
		}
	}
	cout<<"Pangram";
	return 0;
}
