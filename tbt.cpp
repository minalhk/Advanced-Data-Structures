#include<bits/stdc++.h>
using namespace std;

class node{
	int data;
	int lbit, rbit;
	node* lchild;
	node* rchild;
	public:
		node(){
			lbit=rbit=0;
			lchild=rchild=NULL;
		}
		friend class tbt;
};

class tbt{
	node *head,*temp,*x,*s;
	queue<node*> q;
	public:
		tbt(){
			head=new node;
		}
		void create();
		void Linsert(node*, node*);
		void Rinsert(node*, node*);
		void inorder(node*);
		node* insuc(node*);
		node* gethead(){
			return head;
		}
		int headlbit(){
			return head->lbit;
		}
		int headrbit(){
			return head->rbit;
		}
};

void tbt::create(){
	int y;
	//head=new node;
	head->data=0;
	head->rbit=1;
	head->lbit=0;
	head->lchild=head->rchild=head;
	q.push(head);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		cout<<"enter left child for "<<temp->data<<" - ";
		cin>>y;
		if(y!=0){
			x=new node;
			x->data=y;
			Linsert(temp,x);
			q.push(x);
		}
		if(temp!=head){
			cout<<"enter right child for "<<temp->data<<" - ";
			cin>>y;
			if(y!=0){
				x=new node;
				x->data=y;
				Rinsert(temp,x);
				q.push(x);
			}
		}
	}
}

void tbt::Linsert(node *s, node *t){
	t->lchild=s->lchild;
	t->lbit=s->lbit;
	t->rchild=s;
	t->rbit=0;
	s->lchild=t;
	s->lbit=1;
}

void tbt::Rinsert(node *s, node *t){
	t->rchild=s->rchild;
	t->rbit=s->rbit;
	t->lchild=s;
	t->lbit=0;
	s->rchild=t;
	s->rbit=1;
}

void tbt::inorder(node *t){
	
	//head=t;
	while(1){
		//cout<<i++<<endl;
		t=insuc(t);
		if(t==head)
			return;
		cout<<t->data<<"  ";	
	}
}

node* tbt::insuc(node* t){
	s=t->rchild;
	if(t->rbit==1){
		while(s->lbit==1){
			s=s->lchild;
		}
	}
	return s;
}

int main(){
	tbt t;
	int x,y;
	do{
	cout<<"1.create threaded binary tree\n2.inorder traversal for threaded binary tree"<<endl;
	cout<<"enter choice- ";
	cin>>x;
	switch(x){
		case 1:
			t.create();
			break;
		case 2:
			if(t.headlbit()==0 && t.headrbit()==0){
				cout<<"first create tree:)"<<endl;
			}
			else{
			cout<<"inorder travesal of the threaded binary tree- "<<endl;
			t.inorder(t.gethead());
			cout<<endl;
			}
			break;
		default:
			cout<<"Enter right choice"<<endl;		
	}
	cout<<"enter 1 to continue else enter 0(1/0)- ";
	cin>>y;
	}while(y);
	return 0;
}
