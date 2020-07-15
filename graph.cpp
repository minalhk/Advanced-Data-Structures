#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class node
{
	node* next;
	int time;
	int data;
	public:
	node(int x,int t)
	{
		data=x;
		time=t;
		next=NULL;
	}
	friend class graph;
};
class graph
{
	node* head[20];
	string city[20];
	char dir;
	int  n,noe;
	public:
	graph()
	{
		int i;string s;
		cout<<"Enter whether graph is directed or not(y/n)?"<<endl;
		cin>>dir;
		cout<<"Enter number of airports"<<endl;
		cin>>n;
		for(i=0;i<20;i++)
		{
			head[i]=NULL;
			city[i]="";
		}
		cout<<"Enter the name of airports:"<<endl;
		for(i=0;i<n;i++)
		{
			cin>>s;
			city[i]=s;
		}
		
	}
	int search(string p)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			if(p==city[i])
			{
				return i;
			}
		}
		cout<<"Airport Not found,adding new airport to record"<<endl;
		city[i]=p;
		n++;
		return i;
	}
	int search1(string p)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			if(p==city[i])
			{
				return i;
			}
		}
	return -1;
	}
	void create();
	void degree();
	void indegree();
	void outdegree();
	void addvertex();
	void deletevertex();
	void addedge();
	void deleteedge();
	void adjlist(int u,int v,int t);
	void display();
	void dfs();
	void bfs();
	void deletenode(int  );
	void dfsrec(int ,int[] );
	void DFS()
	{
		int visited[20]={0};
		string s;
		int u;
		cout<<"Enter the city with which u want to start the traversal:"<<endl;
		cin>>s;
		u=search1(s);
		if(u!=-1)
		dfsrec(u,visited);
		else
		cout<<"not found"<<endl;
	}
	int found(node* t,int x)
	{
		node* p=t;
		while(p!=NULL)
		{
			if(p->data==x)
			return 1;
			 p=p->next;
		}
		return 0;
	}
	
};
void graph::dfsrec(int j,int visited[])
{
	cout<<city[j]<<" visited "<<endl;
	visited[j]=1;
	node* p=head[j];
	while(p!=NULL)
	{
		if(visited[p->data]==0)
		{
			dfsrec(p->data,visited);
		}
		p=p->next;
	}	
}
void graph::deletenode(int u)
{
	int i,j;
	node* p;
	node* q;
	node* r;node* s;
	p=head[u];
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		
		delete q;
		q=NULL;
	}
	head[u]=NULL;
	for(i=0;i<n;i++)
	{
		if(i==u)
		{
			
			continue;
		}
		else if(head[i]==NULL)
		{
			//cout<<"XYZ"<<endl;
			cout<<"list of"<<i<<"empty"<<endl;
			
		}
		else if(head[i]->data==u && head[i]!=NULL)
		{
			//cout<<"ABC"<<endl;
			q=head[i];
			head[i]=head[i]->next;
			delete q;
			q=NULL;
			
		}
		else
		{	
				//cout<<"zzz"<<endl;
				p=head[i];
				if(found(p,u))
				{
					while(p!=NULL && p->data!=u)
					{
						r=p;
						p=p->next;
					}
				
					r->next=p->next;
					delete p;
				}
				//else 
				//cout<<"Not found"<<endl;
		}
	}
}
void graph::display()
{
	node* p;
	int i=0;
	for(i=0;i<n;i++)
	{
		p=head[i];
		cout<<city[i]<<"=>";
		while(p!=NULL)
		{
			if(p->next!=NULL)
			cout<<city[p->data]<<"-"<<p->time<<"->";
			
			else
			cout<<city[p->data]<<"-"<<p->time;
			
			p=p->next;
		}
		cout<<endl;
	}
}
void graph::adjlist(int u,int v,int t)
{
	if(head[u]==NULL)
	{
		head[u]=new node(v,t);
	}
	else
	{
		node* p=head[u];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=new node(v,t);
	}
}
void graph::addedge()
{
		int i,t;
		string s,d;
		int u,v;
		cout<<"Enter source city"<<endl;
		cin>>s;
		u=search(s);
		cout<<"Enter destination city"<<endl;
		cin>>d;
		v=search(d);
		cout<<"Enter time taken from source to destination"<<endl;
		cin>>t;
		adjlist(u,v,t);
		if(dir=='n' || dir=='N')
		{
			adjlist(v,u,t);
		}
}
void graph::deleteedge()
{
	node *p,*r;
	node* q;
	string s,d;
	int u,v;
	cout<<"Enter source city of  edge to be deleted"<<endl;
	cin>>s;
	u=search1(s);
	cout<<"Enter destination city of  edge to be deleted"<<endl;
	cin>>d;
	v=search1(d);
	if(!found(head[u],v))
	{
		cout<<"Edge not present,cant delete"<<endl;
		return;
	}
	if(u==-1 || v==-1 )
	{
		cout<<"Edge not present,can't delete"<<endl;
		return;
	}
	if(head[u]==NULL)
	{
		cout<<"list of"<<u<<"empty"<<endl;
	}
	else if(head[u]->data==v && head[u]!=NULL)
	{
		q=head[u];
		head[u]=head[u]->next;
		delete q;
		q=NULL;
	}
	else
	{	
			p=head[u];
			while(p!=NULL && p->data!=v)
			{
				r=p;
				p=p->next;
			}
			r->next=p->next;
			delete p;
			p=NULL;
	}
	if(dir=='n' || dir=='N')
	{
		if(head[v]==NULL)
		{
			cout<<"list of"<<v<<"empty"<<endl;
		}
		else if(head[v]->data==u && head[v]!=NULL)
		{
			q=head[v];
			head[v]=head[v]->next;
			delete q;
			q=NULL;
		}
		else
		{	
			p=head[v];
			while(p!=NULL && p->data!=u)
			{
				r=p;
				p=p->next;
			}
			r->next=p->next;
			delete p;
			p=NULL;
		}
	}
	
	
}
void graph::addvertex()
{
	int u,nv,ti,v;
	string s,y;
	cout<<"Enter the new airport name"<<endl;
	cin>>s;
	u=search(s);
	cout<<"Enter the number of vertex adjacent to new vertex"<<endl;
	cin>>nv;
	cout<<"Enter airport names and their time from "<<s;
	for(int i=0;i<nv;i++)
	{
		cout<<"City name:";
		cin>>y;
		v=search(y);
		cout<<"Time:"<<endl;
		cin>>ti;
		adjlist(u,v,ti);
		if(dir=='n'|| dir=='N')
		{
			adjlist(v,u,ti);
		}
	}
	
	
}
void graph::deletevertex()
{
	int u,v;
	string s;
	cout<<"Enter the vertex (airport) to be deleted"<<endl;
	cin>>s;
	u=search1(s);
	if(u==-1)
	{
		cout<<"Port not found"<<endl;
		return;
	}
	else
	{	city[u]='\0';
		deletenode(u);
		cout<<"deleted successfully"<<endl;
		
	}
}
void graph::create()
{
	int i,j,t;
	string s,d;
	int u,v;
	cout<<"Enter the number of flights(edges)"<<endl;
	cin>>noe;
	for(i=0;i<noe;i++)
	{
		cout<<"Enter source city"<<endl;
		cin>>s;
		u=search(s);
		cout<<"Enter destination city"<<endl;
		cin>>d;
		v=search(d);
		cout<<"Enter time taken from source to destination"<<endl;
		cin>>t;
		adjlist(u,v,t);
		if(dir=='n' || dir=='N')
		{
			adjlist(v,u,t);
		}
	}
}
void graph::degree()
{
	if(dir=='y'|| dir=='Y')
	{
		indegree();
		outdegree();
	}
	else
	{
		int i,c;
		for(i=0;i<n;i++)
		{
			c=0;
			node* p=head[i];
			while(p!=NULL)
			{
				c++;
				p=p->next;
		}	
		cout<<"degree of"<<city[i]<<"is:"<<c<<endl;
		}	
	}
}
void graph::indegree()
{
	int i,j,c;
	node* p;
	for(i=0;i<n;i++)
	{
		c=0;
		for(j=0;j<n;j++)
		{
			p=head[j];
			while(p!=NULL)
			{
				if(p->data==i)
				{
					c++;
				}
				p=p->next;
			}	
		}
		cout<<"Indegree of "<<city[i]<<"is:"<<c<<endl;
	}
}
void graph::outdegree()
{
	int i,c;
	for(i=0;i<n;i++)
	{
		c=0;
		node* p=head[i];
		while(p!=NULL)
		{
			c++;
			p=p->next;
		}	
		cout<<"Outdegree of"<<city[i]<<"is:"<<c<<endl;
	}
	
}
int main()
{
	graph obj;
	int x;
	while(1)
	{
		cout<<"MENU"<<endl<<"1.Create graph with n edges"<<endl<<"2.add edge"<<endl;
		cout<<"3.add vertex"<<endl<<"4.Delete edge"<<endl<<"5.Delete vertex"<<endl<<"6.Degree of graph"<<endl;
		cout<<"7.Display list"<<endl<<"8.DFS traversal"<<endl;
		cout<<"9.exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
					obj.create();
			 	 	 break;
			case 2:
					obj.addedge();
					cout<<"Added successfully"<<endl;
					 break;
			case 3:
					obj.addvertex();
					break;
			case 4:
					obj.deleteedge();
					break;
			case 5:
					obj.deletevertex();
					break;
			case 6:
					obj.degree();
					break;
			case 7:
					obj.display();
					break;
			case 8:
					obj.DFS();
					break;
			case 9:
					exit(0);
					
			default:
				cout<<"Invalid choice,enter again"<<endl;
				continue;
			
				
					 
		}
	}
}
