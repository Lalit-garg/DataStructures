#include<bits/stdc++.h>
using namespace std;
vector<int> in;
vector<int> pre;
template <typename T>
class binarynode
{
	public:
		T data;
			binarynode* left;
			binarynode* right;
		binarynode(T data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~binarynode()
		{
			delete left;
			delete right;
		}
};
binarynode<int>* takeinputlevel()
{
	cout<<"Enter Data-";
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1)
		return NULL;
	binarynode<int>* root=new binarynode<int>(rootdata);
	queue<binarynode<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarynode<int>* front=q.front();
		q.pop();
		cout<<"Enter left child of "<<front->data<<"=";
		int leftdata;
		cin>>leftdata;
		cout<<endl;
		if(leftdata!=-1)
		{
			binarynode<int>* leftchild=new binarynode<int>(leftdata);
			front->left=leftchild;
			q.push(leftchild);
		}
		cout<<"Enter right child of "<<front->data<<"=";
		int rightdata;
		cin>>rightdata;
		cout<<endl;
		if(rightdata!=-1)
		{
			binarynode<int>* rightchild=new binarynode<int>(rightdata);
			front->right=rightchild;
			q.push(rightchild);
		}
	}
	return root;
}
void printtree(binarynode<int>* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<":";
	if(root->left!=NULL)
		cout<<"  L="<<root->left->data<<",";
	if(root->right!=NULL)	
		cout<<"  R="<<root->right->data;
	cout<<endl;
	printtree(root->left);
	printtree(root->right);
}
void printlevel(binarynode<int>* root)
{
	if(root==NULL)
		return;
	queue<binarynode<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarynode<int>* front=q.front();
		cout<<front->data<<",";
		q.pop();
		if(front->left!=NULL)
			q.push(front->left);
		if(front->right!=NULL)
			q.push(front->right);
	}
}
void printpre(binarynode<int>* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<",";
	pre.push_back(root->data);
	printpre(root->left);
	printpre(root->right);
}
void printpost(binarynode<int>* root)
{
	if(root==NULL)
		return;
	printpost(root->left);
	printpost(root->right);
	cout<<root->data<<",";
}
void printin(binarynode<int>* root)
{
	if(root==NULL)
		return;
	printin(root->left);
	cout<<root->data<<",";	
	in.push_back(root->data);
	printin(root->right);
	
}
binarynode<int>* constructinpre(vector<int> in,vector<int> pre,int is,int ie,int ps,int pe)
{
	if((is>ie) || (ps>pe))
		return NULL;
	int rootdata=pre[ps];
	binarynode<int>* root=new binarynode<int>(rootdata);
	int i=-1;
	for(int j=is;j<=ie;j++)
	{
		if(in[j]==pre[ps])
		{
			i=j;
			break;
		}
	}
	int lins=is;
	int line=i-1;
	int lpres=ps+1;
	int lpree=lpres-lins+line;
	int rins=i+1;
	int rine=ie;
	int rpres=lpree+1;
	int rpree=pe;
	root->left=constructinpre(in,pre,lins,line,lpres,lpree);
	root->right=constructinpre(in,pre,rins,rine,rpres,rpree);
	return root;
}
int height(binarynode<int>* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return 1+height(root->left)+height(root->right);
}
int diameter(binarynode<int>* root)
{
	if(root==NULL)
		return 0;
	int hl=height(root->left)+height(root->right);;
	int dl=diameter(root->left);
	int dr=diameter(root->right);
	return max(hl,max(dl,dr));
}
int main()
{
	/*binarynode<int>* root=new binarynode<int>(1);
	binarynode<int>* node1=new binarynode<int>(2);
	binarynode<int>* node2=new binarynode<int>(3);
	root->left=node1;
	root->right=node2;
	*/
	binarynode<int>* root=takeinputlevel();	
	printtree(root);
	cout<<"Elemnts in level order- ";
	printlevel(root);
	cout<<endl;
	cout<<"Elemnts in preorder- ";
	printpre(root);
	cout<<endl;
	cout<<"Elemnts in postorder- ";
	printpost(root);
	cout<<endl;
	cout<<"Elemnts in inorder- ";
	printin(root);
	cout<<endl;
	int insize=in.size()-1;
	int presize=pre.size()-1;
	root=constructinpre(in,pre,0,insize,0,presize);
	cout<<"levelorder- ";
	printlevel(root);
	cout<<endl;
	cout<<"Height of the tree = "<<height(root)<<endl;
	cout<<"Diameter of the tree = "<<diameter(root)<<endl;
	delete root;
	return 0;
}
