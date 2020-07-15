#include<bits/stdc++.h>
using namespace std;
class node
{
	
	node* left;
	node* right;
	string keyword;
	string meaning;
	public:
	node(string k,string m)
	{
		left=NULL;
		right=NULL;
		keyword=k;
		meaning=m;
	}
	friend class bst;
};
class bst
{
	node* root;
	public:
	bst()
	{
		root=NULL;
	}
	void create();
	node* insert(node*,string);
	node* getroot()
	{
		return root;
	}
	void inorder(node*);
	void postorder(node*);
	node* findmin(node*);
	void Delete()
	{
		string key;
		cout<<"Enter keyword to be deleted"<<endl;
		cin>>key;
		root=Deleterec(root,key);
		
		
		
	}
	node* Deleterec(node* ,string);
	void update()
	{
		string k,m;
		cout<<"Enter the keyword whose meaning to be updated"<<endl;
		cin>>k;
		//cout<<"Enter new meaning"<<endl;
					//cin>>m;
		updaterec(k,root);
		
	}
	void updaterec(string,node*);
	int height(node*);
	void mirror(node* p);
	node* copyrec(node*);
	void operator=(bst& demo)
{
		root=copyrec(demo.root);
}
	
};

node* bst::copyrec(node* t)
{
	if(t!=NULL)
	{
		
		node* p=new node(t->keyword,t->meaning);
		p->left=copyrec(t->left);
		p->right=copyrec(t->right);
		return p;
	}
	return t;
		
}
void bst::mirror(node* t)
{
	node* x;
	if(t!=NULL)
	{
		mirror(t->left);
		mirror(t->right);
		x=t->left;
		t->left=t->right;
		t->right=x;
		
	}
}
int bst::height(node* t)
{
	if(t==NULL)
	{
		return -1;
	}
	int l=height(t->left);
	int r=height(t->right);
	if(l<r)
	return r+1;
	else
	return l+1;
}
void bst::updaterec(string k,node* t)
{	string m;
	if(t!=NULL)
	{
		if(k==t->keyword)
		{	
			cout<<"Enter new meaning"<<endl;
			cin>>m;
			t->meaning=m;
			cout<<"updated successfully"<<endl;
			return ;
		}
		if(k<t->keyword)
		{
			updaterec(k,t->left);
		}
		else if(k>t->keyword)
		{
			updaterec(k,t->right);
		}
	}
	else
	{
		cout<<"Not found"<<endl;
		return ;
	}
}
node* bst::Deleterec(node* p,string key)
{
	node* t;
	if(p==NULL)
	{
		cout<<"Not found"<<endl;
		return NULL;
	}	
	if(key<p->keyword)
	{
		p->left=Deleterec(p->left,key);
		return p;
	}
	else if(key>p->keyword)
	{
		p->right=Deleterec(p->right,key);
		return p;
	}
	
	if(p->left==NULL && p->right==NULL)//no child
	{
		delete p;
		return NULL;
	}
	if(p->left!=NULL && p->right==NULL)//left child
	{	t=p->left;
		delete p;
		return t;
	}
	if(p->left==NULL && p->right!=NULL)//right child
	{
		t=p->right;
		delete p;
		return t;
	}
	
	  t=findmin(p->right);
	 p->keyword=t->keyword;
	p->right =Deleterec(p->right,t->keyword);
	return p;	 
}
node* bst::findmin(node* p)
{
	if(p->left==NULL)
	{
		return p; 
	}
	else
	{
		return findmin(p->left);
	}
	
}
void bst::inorder(node* t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->keyword<<"-"<<t->meaning<<endl;
		inorder(t->right);
	}
}
void bst::postorder(node* t)
{
	if(t!=NULL)
	{
		inorder(t->left);
       	        inorder(t->right);
		cout<<t->keyword<<"-"<<t->meaning<<endl;
	}
}
void bst::create()
{	char x;
	string k,m;
	
	
	
	do
	{
		cout<<"Enter keyword ( should not be repeated)"<<endl;
		cin>>ws;
		getline(cin,k);
		root=insert(root,k);
		cout<<"Want to add another('y' for yes/'n' for no) "<<endl;
		cin>>x;
		
		
	}while(x=='y' || x=='Y');
		
}
node* bst::insert(node* t,string k)
{
	string m;
	if(t==NULL)
	{
		cout<<"Enter corresponding meaning"<<endl;
		cin>>m;
		
		node* p=new node(k,m);
		return p;
	}
	else
	{
		if(k<t->keyword)
		{
				t->left=insert(t->left,k);
		}
		else if(k>t->keyword)
		{
				t->right=insert(t->right,k);
		}
		else if(k==t->keyword)
		{
			cout<<"keyword already exist in the dictionary"<<endl;
			
		}
		return t;
	}	
}
int main()
{
	string k,m;
	bst obj;bst copy;
	int x;
	while(1)
	{
		abc: 
		
		cout<<"MENU"<<endl<<"1.Create bst with n nodes"<<endl<<"2.Insert into bst"<<endl;
		cout<<"3.Delete the given keyword"<<endl;
		cout<<"4.Update the given meaning"<<endl<<"5.assign 1 tree to another"<<endl<<"6.Max comparisons"<<endl;
		cout<<"7.Print in ascending order(inorder)"<<endl<<"8.Print in descending order"<<endl;
		cout<<"9.Postorder traversal"<<endl;
		cout<<"10.exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
					obj.create();
			 	 	 break;
			case 2:
					cout<<"Enter the keyword to be inserted"<<endl;
					cin>>k;
					
					obj.insert(obj.getroot(),k);
					
					
					 break;
			case 3:
					obj.Delete();
					 break;
			case 4:
					obj.update();
					 break;
			case 5:
					cout<<"Successfully copied one tree to another"<<endl;
					copy=obj;
					copy.inorder(copy.getroot());
					
					break;
			case 6:
					cout<<"Maximum number of comparisons"<<obj.height(obj.getroot());
					 break;
			case 7:
					cout<<"Ascending order of the tree"<<endl;
					obj.inorder(obj.getroot());
					 break;
			case 8:
					cout<<"Descending order of the tree"<<endl;
					obj.mirror(obj.getroot());
					obj.inorder(obj.getroot());
					break;
			
			case 9:
					obj.postorder(obj.getroot());
					break;
					
			case 10:
					exit(0);
					
			default:
				cout<<"Invalid choice,enter again"<<endl;
				goto abc;
				
					 
		}
				
				
				
				
	}
}
