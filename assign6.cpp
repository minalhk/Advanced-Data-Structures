#include<bits/stdc++.h>
#define max 10
using namespace std;
class phonebook{
	int phno[max];
	string name[max];
	int flag;
	//int visit[max];
	public:
	phonebook(){
		for(int i=0;i<max;i++){
			//visit[i]=-1;
			phno[i]=-1;
			//flag=0;
		}
		cout<<"enter 1 for linear probing with replacement else enter 0 for without replacement linear probing- ";
		cin>>flag;
	}
	
	void insert(int);
	void print();	
	void find(int);
	void Delete(int);
};
void phonebook::insert(int pn){
	/*for(int i=0;i<max;i++){
		if(phno[i]==pn){
			cout<<pn<<" already exist in the phonebook"<<endl;
			return;
		}	
	}*/
	int i,a,x,y,z;
	x=pn%10;
	a=z=x;
	if(phno[x]==pn){
		cout<<pn<<" already exist in the phone book at index "<<x<<endl;
		return;	
	}	
	else{
		x++;
		y=x%10;
		while(phno[y]!=pn){
			x++;
			y=x%10;
			if(phno[y]==pn){
				cout<<pn<<" already exist in the phone book at index "<<y<<endl;
				return;
			}
			if(y==(z+9)%10)
				break;
		}	
	}
	if(phno[z]==-1){
		phno[z]=pn;
		y=z;
	}
	else{
		z++;
		y=z%10;
		while(phno[y]!=-1){
			z++;
			y=z%10;
			if(y==((a+9)%10) && phno[y]!=-1){
				cout<<"Phone book is FULL:("<<endl;
				return;
			}
		}
		phno[y]=pn;
	}	
	
	cout<<"enter name- ";
	string s;
	cin>>s;
	name[y]=s;
		
}
void phonebook::print(){
	cout<<"\nPHONE DIRECTORY- "<<endl;
	for(int i=0;i<max;i++){
		if(phno[i]!=-1)
			cout<<i<<" - "<<phno[i]<<" - "<<name[i]<<endl;
	}
}
void phonebook::find(int pn){
	int i,x,y,z;
	x=pn%10;
	z=x;
	if(phno[x]==pn){
		cout<<"found "<<pn<<" at the index "<<x<<endl;
		//flag=1;
		return;	
	}	
	else{
		x++;
		y=x%10;
		while(phno[y]!=pn){
			x++;
			y=x%10;
			if(phno[y]==pn){
				cout<<"found "<<pn<<" at the index "<<y<<endl;
				//flag=1;
				return;
			}
			if(y==((z+9)%10)){
				cout<<pn<<" not found in the phone book"<<endl;	
				return;
			}	
		}
	
	/*for(i=0;i<max;i++){
		if(phno[i]==pn){
			cout<<"found "<<pn<<" at the index "<<i<<endl;
			return;
		}	
	}
	if(i==max)
		cout<<pn<<" not found in the phone book"<<endl;*/
	
	}
}	
void phonebook::Delete(int pn){
	int i,x,y,z;
	x=pn%10;
	z=x;
	if(phno[x]==pn){
		cout<<pn<<" DELETED Successfully"<<endl;
		phno[x]=-1;
		return;	
	}	
	else{
		x++;
		y=x%10;
		while(phno[y]!=pn){
			x++;
			y=x%10;
			if(phno[y]==pn){
				cout<<pn<<" DELETED Successfully"<<endl;
				phno[x]=-1;
				return;
			}
			if(y==((z+9)%10)){
				cout<<pn<<" not found in the phone book"<<endl;	
				return;
			}	
		}
	}		
}
int main(){
	int pn,ch;
	phonebook pb;
	while(1){
		cout<<"enter phone number or enter -1 to stop- ";
		cin>>pn;
		if(pn<0)
			break;
		else
			pb.insert(pn);	
	}
	pb.print();
	cout<<"enter element to be inserted- ";
	cin>>pn;
	pb.insert(pn);
	pb.print();
	cout<<"enter element to be searched- ";
	cin>>pn;
	pb.find(pn);
	cout<<"enter element to be deleted- ";
	cin>>pn;
	pb.Delete(pn);
	pb.print();
	return 0;
}
