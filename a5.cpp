#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class graph
{
	
	int** G;
	int** resk;
	int** resp;
	int** tempo; //prims
	int** tempo1; //kruskal
	int n;
	int noe;
	char dir;
	string* city;
	public:
	graph()
	{
		string x;
		int i,j;
		cout<<"Enter whether directed or not(y/n)"<<endl;
		cin>>dir;
		cout<<"Enter the number of cities"<<endl;
		cin>>n;
		G=new int*[n];
		tempo=new int*[n];
		resk=new int*[n];
		resp=new int*[n];
		city=new string[n];
		tempo1=new int*[n];
		
		cout<<"Enter the name of cities"<<endl;
		for(i=0;i<n;i++)
		{
			cin>>x;
			city[i]=x;
			G[i]=new int[n];
			resk[i]=new int[n];
			resp[i]=new int[n];
			tempo[i]=new int[n];
			tempo1[i]=new int[n];
			for(j=0;j<n;j++)
			{
				G[i][j]=0;
				resk[i][j]=0;
				resp[i][j]=0;	
				tempo[i][j]=0;
				tempo1[i][j]=0;	
			}
			
		}
		
		
	}
	int search(string x)
	{
		for(int i=0;i<n;i++)
		{
			if(x==city[i])
			{
				return i;
			}
		}
		return -1;
	}
	void display();
	void create();
	void kruskal();
	void prims(int);
	
};
void graph::prims(int v1)
{
	int min,count=0,count1=0,wt_tree,t,t1,temp,temp1,root_temp,root_temp1,i,j,v2;
	
	int array[10];
	array[count1]=v1;
	count1++;
	int father[10];
	for(i=0;i<10;i++)
	{
		father[i]=-1;
		array[i]=0;
	}
	wt_tree=0;
	
	while(count<n-1)
	{
		min=999;
		for(v1=0;v1<count1;v1++)
		{
			for(v2=0;v2<n;v2++)
			{
				if(tempo[array[v1]][v2]!=0)
				{
					if(tempo[array[v1]][v2]<min)
					{
						min=tempo[array[v1]][v2];
						temp=array[v1];
						temp1=v2;
					}
				}
			}
		}
		
		t=temp;
		t1=temp1;
		tempo[temp][temp1]=tempo[temp1][temp]=0;
		
		while(temp>=0)
		{
			root_temp=temp;
			temp=father[temp];	
		}
		while(temp1>=0)
		{
			root_temp1=temp;
			temp1=father[temp1];
		}
		if(root_temp!=root_temp1)
		{
			resp[t][t1]=resp[t1][t]=min;
			wt_tree=wt_tree + min;
			father[root_temp1]=root_temp;
			count++;
			array[count1]=t1;
			count1++;
		}
		
	}
		
	cout<<"Shortest distance is:"<<wt_tree<<endl;
	cout<<"Resultant array for prims"<<endl;
	for(i=0;i<=n;i++)
	{
		if(i==0)
		cout<<" "<<"\t";
		else
		cout<<city[i-1]<<"\t";
		
		for(j=0;j<=n;j++)
		{
			
				if(i==0 && j!=0)
				cout<<city[j-1]<<"\t";
			
				if(i!=0 && j!=0)
				cout<<resp[i-1][j-1]<<"\t";
		}
		cout<<endl;
		
	}
	
	
	
}
void graph::kruskal()
{
	int min,count,wt_tree,t,t1,temp,temp1,root_t,root_t1,i,j;
	min=999;
	count=0;
	wt_tree=0;
	int father[10];//={-1};
	for(i=0;i<10;i++)
	father[i]=-1;
	
	while(count<n-1)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(tempo1[i][j]<min && tempo1[i][j]!=0)
				{
					min=tempo1[i][j];
					temp=i;
					temp1=j;
				}
			}
		}
		
		t=temp;
		t1=temp1;
		tempo1[temp][temp1]=tempo1[temp1][temp]=0; //reset value to 0;
		
		while(temp>=0)   //check cycle
		{
			root_t=temp;
			temp=father[temp];
		}
		while(temp1>=0)
		{	
			root_t1=temp1;
			temp1=father[temp1];	
		}
		if(root_t!=root_t1)
		{
			resk[t][t1]=resk[t1][t]=min;
			wt_tree=wt_tree+min;
			father[root_t1]=root_t;
			count++;
		}
		
	
	}
	cout<<"Shortest distance is:"<<wt_tree<<endl;
	cout<<"Resultant array for kruskal"<<endl;
	for(i=0;i<=n;i++)
	{
		if(i==0)
		cout<<" "<<"\t";
		else
		cout<<city[i-1]<<"\t";
		
		for(j=0;j<=n;j++)
		{
			
				if(i==0 && j!=0)
				cout<<city[j-1]<<"\t";
			
				if(i!=0 && j!=0)
				cout<<resk[i-1][j-1]<<"\t";
		}
		cout<<endl;
		
	}
	
}
void graph::display()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		if(i==0)
		cout<<" "<<"\t";
		else
		cout<<city[i-1]<<"\t";
		
		for(j=0;j<=n;j++)
		{
			
			if(i==0 && j!=0)
			cout<<city[j-1]<<"\t";
			
			if(i!=0 && j!=0)
			cout<<G[i-1][j-1]<<"\t";
		}
		cout<<endl;
	}
}
	
void graph::create()
{
	string o,d;
	int i,j,u,v,ti;
	cout<<"Enter the number of edges"<<endl;
	cin>>noe;
	for(i=0;i<noe;i++)
	{
		cout<<"Enter source city"<<endl;
		cin>>o;
		u=search(o);
		cout<<"Enter destination city:"<<endl;
		cin>>d;
		v=search(d);
		cout<<"Enter time from source to destination"<<endl;
		cin>>ti;
		G[u][v]=ti;
		tempo[u][v]=ti;
		tempo1[u][v]=ti;
		if(dir=='n' || dir=='N')
		{
			G[v][u]=ti;	// orignal unharmed array
			tempo[v][u]=ti; // for prims
			tempo1[v][u]=ti;// for kruskal
		}
	}
}
int main()
{
	int x;string k;
	graph obj;
	while(1)
	{
		cout<<"MENU"<<endl;
		cout<<"1.Create graph with n nodes"<<endl<<"2.Find shortest path using kruskal"<<endl; 	
		cout<<"3.MSt using prims"<<endl<<"4.Display"<<endl<<"5.exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:obj.create();
				break;
			
			case 2:obj.kruskal();
				break;
			
			case 3:cout<<"Enter starting city"<<endl;
				cin>>k;
				
				int u;
				u=obj.search(k);
				if(u==-1) 
				cout<<"not found"<<endl;
				else
				
				obj.prims(u);
				break;
			
			case 4:obj.display();
				break;
			
			case 5:exit(0);
				break;
			
			default:
				cout<<"Invalid choice,enter again"<<endl;
				continue;
		}
		
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
