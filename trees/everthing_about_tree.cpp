#include<bits/stdc++.h>
using namespace std;
template <typename T>
class treenode
{
	public:
		T data;
		vector<treenode<T>*> children;
		treenode(T data)
		{
			this->data=data;
		}
		~treenode()
		{		
			for(int i=0;i<children.size();i++)
			{
			delete children[i];
			}
		}
};
void printlevel(treenode<int>* root)
{
	queue<treenode<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		treenode<int>* temp=q.front();
		cout<<temp->data<<endl;
		q.pop();	
		for(int i=0;i<temp->children.size();i++)
		{
			q.push(temp->children[i]);
		}
		cout<<endl;
	}
}
void printtree(treenode<int>* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
		cout<<root->children[i]->data<<",";
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
		printtree(root->children[i]);
}
treenode<int>* takeinput()
{
	int rootdata;
	cout<<"Enter Data-";
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	int n;
	cout<<endl<<"Enter num. of children of "<<rootdata<<"-";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		treenode<int>* child=takeinput();
		root->children.push_back(child);
	}
	return root;
}
treenode<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"Enter Data-";
	cin>>rootdata;
	treenode<int>* root=new treenode<int>(rootdata);
	queue<treenode<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		treenode<int>* front=q.front();
		q.pop();
		int n;
		cout<<endl<<"Enter num. of children of "<<front->data<<"-";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int cdata;
			cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
			cin>>cdata;
			treenode<int>* child=new treenode<int>(cdata);
			front->children.push_back(child);
			q.push(child);
		}			
	}
	return root; 	
}
int count(treenode<int>* root)
{
	int ans=1;
	for(int i=0;i<root->children.size();i++)
		ans+=count(root->children[i]);
	return ans;
}
int height(treenode<int>* root)
{
	int x=0;
	if(root->children.size()==0)
		return 1;
	else
	for(int i=0;i<root->children.size();i++)
	{
		int x1=height(root->children[i]);
		x=max(x,x1);
		
	}
	return x+1;
}
void depth(treenode<int>* root,int k)
{
	if(k==0)
	{
		cout<<root->data<<endl;
		return;
	}
	else
	{
		for(int i=0;i<root->children.size();i++)
		{
			depth(root->children[i],k-1);
		}
	}
}
int countleaf(treenode<int>* root)
{
	
	int ans;
	if(root->children.size()==0)
	{
		ans=1;
	}
	else
	{
		ans=0;
	}
	for(int i=0;i<root->children.size();i++)
		ans+=countleaf(root->children[i]);
	return ans;
}

int main()
{
	/*
	treenode<int>* root=new treenode<int>(1);
	treenode<int>* node1=new treenode<int>(2);
	treenode<int>* node2=new treenode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	treenode<int>* root=takeinputlevelwise();
	printtree(root);
	cout<<endl<<endl;
	cout<<"Elements in level order-"<<endl;
	printlevel(root);
	cout<<endl<<"No. of nodes-"<<count(root);
	cout<<endl<<"Height of tree-"<<height(root)<<endl;
	cout<<"Enter Depth till you want to print element-";
	int k;
	cin>>k;
	cout<<"Elements are:"<<endl;
	depth(root,k);
	cout<<"No.of leaf nodes-"<<countleaf(root);	
	delete root;
	return 0;
}
