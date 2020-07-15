#include<bits/stdc++.h>
#define MAX 25

using namespace std;

class node{
	int data;
	node *l, *r;
	public:
		node(){
			data = 0;
			l=r=NULL;
		}
		friend class bintree;
		//friend class queue;
		
};
/*class queue{
	node *q[MAX];
	int f,r,count;
	public:
		queue(){
			f=r=-1;
			count=0;
		}
		 void push(node *t){
		 	r++;
		 	q[r]=t;
		 	count++;
		 }
		 void pop(){
		 	if(f==-1)
		 	   f=f+2;
		 	else 
		 	    f++;
		     count--;	       
		 }
		 int size(){
		 	return count;
		 }
		 node *front(){
		 	return q[f];
		 }
		 friend class bintree;
};
*/
class bintree{
	node *root, *temp;
	node* stack[MAX];
	int leaf,count;
	public:
		bintree(){
			root=NULL;
			leaf=0;
			count=0;
		}
		void create(int x);
		
		node *insert(node *t,int x);		
		void insertcall(int x){
			root=insert(root,x);
		}
		
		void inorder(node *t);
		void inorderNR(node *t);
		void inordercall(){
			inorder(root);
			cout<<"\nusing non recursive function- "<<endl;
			inorderNR(root);
		}
		
		void preorder(node *t);
		void preorderNR(node *t);
		void preordercall(){
			preorder(root);
			cout<<"\nusing non recursive function- "<<endl;
			preorderNR(root);
		}
		
		void postorder(node *t);
		void postorderNR(node *t);
		void postordercall(){
			postorder(root);
			cout<<"\nusing non recursive function- "<<endl;
			postorderNR(root);
		}
		
		int height(node *t);
		int treeHeight(node *t);
		void maxDepthcall(){
			
			cout<<"height of the tree is- "<<height(root)<<endl;
			cout<<"height of tree using non recursive function= "<<treeHeight(root)<<endl;
		}
		
		void swaptree(node *t);
		void mirrorcall(){
			swaptree(root);
			cout<<"after mirroring the tree- "<<endl;
			inordercall();
		}
		
		int leaves(node *t);
		void leavescall(){
			leaves(root);
			cout<<"number of leaves= "<<leaf;
		}
		
		int internalnodes(node *t);
		int internalnodescall(){
			count=internalnodes(root);
			cout<<"number of internal node= "<<count-1<<endl;
			}
		
		
		void erase(node *t);
		void erasecall(){
			erase(root);
			root=NULL;
			cout<<"deleted all nodes of the tree"<<endl;
			
		}
		void operator =(bintree &obj){
			this->root=obj.root;
		}
		
};
node* bintree::insert(node *t,int x){
	
	if(t==NULL){                  
		node *t=new node;
		t->data=x;

		return t;
	}
	else{
		int c;
		cout<<"\nenter 1 to add left child for "<<t->data<<" else enter 2[1/2]- ";
		cin>>c;
		if(c==1) {   
	
			t->l=insert(t->l,x);			
		}
		else{
		
			t->r=insert(t->r,x);
		}
		
		return t;
	}
}


void bintree::create(int x){
	if(root==NULL){
		root=new node;
		root->data=x;
		
	}
	else
		root=insert(root,x);

}

void bintree::inorder(node *t){
	if(t!=NULL){
		inorder(t->l);
		cout<<t->data<<"  ";
		inorder(t->r);
	}
	else
		cout<<"NULL"<<"  ";
}
void bintree::inorderNR(node *t){
	int i=0;
	while(1){
		while(t!=NULL){
			i++;
			stack[i]=t;
			t=t->l;
		}
		
		if(i==0)
			return;
		
		t=stack[i];
		i--;
		cout<<t->data<<"  ";
		t=t->r;	
	}
}

void bintree::preorder(node *t){
	if(t!=NULL){
		cout<<t->data<<"  ";
		preorder(t->l);
		preorder(t->r);	
	}
	else
		cout<<"NULL"<<"  ";
}
void bintree::preorderNR(node *t){
	int i=0;
	while(1){
		while(t!=NULL){
			cout<<t->data<<"  ";
			if(t->r!=NULL){
				i++;
				stack[i]=t->r;
			}
			t=t->l;
		}
		if(i==0)
			return;
		t=stack[i];
		i--;	
	}
}

void bintree::postorder(node *t){
	if(t!=NULL){
		postorder(t->l);
		postorder(t->r);
		cout<<t->data<<"  ";
	}
	else
		cout<<"NULL"<<"  ";
}
void bintree::postorderNR(node *t){
	int i=0;
	while(1){
		while(t!=NULL){
			i++;
			stack[i]=t;
			if(t->r!=NULL){
				i++;
				stack[i]=t->r;
				i++;
				stack[i]=NULL;
			}
			t=t->l;
		}
		if(i==0)
			return;
		while(stack[i]!=NULL && i!=0){
			t=stack[i];
			cout<<t->data<<"  ";
			i--;
		}
		if(i!=0)
			i--;
		if(i==0)
			return;
		t=stack[i];
		i--;			
	}
}
int bintree::height(node* t)  
{ 
	
	   int x=0, y=0;
	   if(t==NULL)
	   	return -1;
	   if(t!=NULL)
	   	x=height(t->l);
	   y=height(t->r);
	   if(x>y)
	   	return (x+1);
	   else
	   	return (y+1);			
}
/*
int bintree::treeHeight(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
        return 0; 
  
    // Create an empty queue for level order tarversal 
    queue q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
    int height = 0; 
  
    while (1) 
    { 
        // nodeCount (queue size) indicates number of nodes 
        // at current lelvel. 
        int nodeCount = q.size(); 
        if (nodeCount == 0) 
            return height; 
  
        height++; 
  
        // Dequeue all nodes of current level and Enqueue all 
        // nodes of next level 
        while (nodeCount > 0) 
        { 
            node *node = q.front(); 
            q.pop(); 
            if (node->l != NULL) 
                q.push(node->l); 
            if (node->r != NULL) 
                q.push(node->r); 
            nodeCount--; 
        } 
    } 
} 
*/

int bintree::treeHeight(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
        return 0; 
  
    // Create an empty queue for level order tarversal 
    queue<node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
    int height = 0; 
  
    while (1) 
    { 
        // nodeCount (queue size) indicates number of nodes 
        // at current lelvel. 
        int nodeCount = q.size(); 
        
        if (nodeCount == 0) 
            return (height-1); 
  
        height++; 
  
        // Dequeue all nodes of current level and Enqueue all 
        // nodes of next level 
        while (nodeCount > 0) 
        { 
            node *node = q.front(); 
            q.pop(); 
            if (node->l != NULL) 
                q.push(node->l); 
            if (node->r != NULL) 
                q.push(node->r); 
            nodeCount--; 
        } 
    } 
} 

void bintree::swaptree(node* t)  
{ 
  if(t==NULL)
  	return;
  if(t!=NULL)
  	swaptree(t->l);
  swaptree(t->r);
  temp=t->l;
  t->l=t->r;
  t->r=temp;
  		
  
} 

int bintree::leaves(node *t){
	if(t==NULL)
		return 0;
	if(t!=NULL)
		leaves(t->l);
	leaves(t->r);
		
	if(t->r==NULL && t->l==NULL)
		leaf++;		
		
} 

int bintree::internalnodes(node *t){
	if(t==NULL)
		return 0;
	else if(t->l!=NULL || t->r!=NULL)
		return 1+internalnodes(t->l)+internalnodes(t->r);
	else if(t->l==NULL && t->r==NULL)
		return 0;		
}


void bintree::erase(node *t){
	if(t==NULL){
		
		return;
	}
	else{
		t->r=NULL;
		t->l=NULL;
		node *q=t;
		t=NULL;
		delete q;
	}
}

int main(){
	int c;
	int x,ch;
	bintree b,a;
	do{
		cout<<"1.create\n2.insert\n3.display by inorder traversal\n4.display by preorder traversal\n5.display by postorder traversal\n6.height of the tree\n7.mirror of the tree\n8.to count number of leaves\n9.to count number of internal nodes\n10.copy tree\n11.to erase tree"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter element- ";
				cin>>x;
				b.create(x);
				break;
			case 2:
				cout<<"enter element to insert- ";
				cin>>x;
				b.insertcall(x);
				break;
			case 3:
				b.inordercall();
				break;
			case 4:
				b.preordercall();
				break;
			case 5:
				b.postordercall();
				break;		
			case 6:
				b.maxDepthcall();
				break;	
			case 7:
				b.mirrorcall();
				break;
			case 8:
				b.leavescall();
				break;
			case 9:
				b.internalnodescall();
				break;	
			case 10:
				a=b;
				cout<<"after copying the tree new tree is- "<<endl;
				a.inordercall();
				break;	
			case 11:
				b.erasecall();
				break;		
			default:
				cout<<"enter right choice"<<endl;		
						
		}
	cout<<"\nenter 1 to continue else enter 0(1/0)?- ";
	cin>>c;
	}while(c==1);
	return 0;
}
