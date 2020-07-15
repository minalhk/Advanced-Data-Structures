#include<iostream>
using namespace std;
#define size1 10
#define size2 10
template<class t>
class SET
{
	t a[size1],b[size2],in[size1+size2],u[size1+size2],diff[size1];
	int i,cnt1,cnt2;
	public:
	
	SET()
	{
		for(i=0;i<size1;i++)
		{
			a[i]=-1;
			b[i]=-1;
		}
		cnt1=0;
		cnt2=0;
	}
	
	void add()
	{
		t ele;
		int choice,rep;
		cout<<"1.Add in first set\t2.Add in second set\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				label:
				cout<<"Enter element";
				cin>>ele;
				i=0;
				while(a[i]!=-1 && a[i]!=ele)
				{
					i++;
				}
				if (a[i]==ele)
				{
					cout<<"already present enter another element"<<endl;
					goto label;
				}
				a[i]=ele;
				cnt1++;
				break;
			}
			
			case 2:
			{
				label2:
				cout<<"Enter element";
				cin>>ele;
				i=0;
				while(b[i]!=-1 && b[i]!=ele)
				{
					i++;
				}
				if (b[i]==ele)
				{
					cout<<"already present enter another element"<<endl;
					goto label2;
				}
				b[i]=ele;
				cnt2++;
				break;
			}
			
		}
	}
	
	void display()
	{
		cout<<"FIRST SET\n";
		cout<<"{";
		for(i=0;i<size1;i++)
		{
			if(a[i]!=-1)
			cout<<a[i]<<" ";
		}
		cout<<"}";
		
		cout<<"\nSECOND SET\n";
		cout<<"{";
		for(i=0;i<size2;i++)
		{
			if(b[i]!=-1)
			cout<<b[i]<<" ";
		}
		cout<<"}";
	}
	void size()
	{
		cout<<"The size of first array is\t"<<cnt1<<"\n";
		cout<<"The size of second array is\t"<<cnt2<<"\n";	
	}
	void contain()
	{
		t ele;
		int flag=0;
		cout<<"Enter the element\n";
		cin>>ele;
		
		for(i=0;i<size1;i++)
		{
			if(a[i]==ele)
			{
				flag=1;
				break;
				
			}
		}
		if(flag==1)
		{
			cout<<"Element found at location "<<i+1;
			
		}
		else
		{
			cout<<"Element not found";
		}
	}
	void remove(t arr[],t ele)
	{
		
		int j;
		for(i=0;i<size1;i++)
		{
			if(arr[i]==ele)
			{
				for(j=i;j<10;j++)
				{
					arr[j]=arr[j+1];
				}
			}
		}
		cout<<"Element deleted ";
	}
	void del()
	{
		t ele;
		cout<<"Enter the element u want to delete";
		cin>>ele;
		
		remove(a,ele);
	}
	void intersection()
	{
		cout<<"The intersection is \n{";
		int j=0;
		i = 0;
                while(i < size1 && j < size2)
                {
                 	if(a[i] < b[j])
      			i++;
    			else if(b[j] < a[i])
     			j++;
    			else 
    			{
      				cout<<b[j++];
     				i++;
    			}
  		}
  		cout<<"}";
		
		
	}
	void uni()
	{
		cout<<"The union is \n{";
		int j=0;
		i = 0;
  		while(i < size1 && j < size2)
  		{
   			 if(a[i] < b[j] && a[i]!=-1)
      			cout<<a[i++]<<" ";
   			 else if(b[j] < a[i] && b[j]!=-1)
      			cout<<b[j++]<<" ";
   			 else
   			 {
   			 	if(b[j]!=-1)
    				  cout<<b[j++]<<" ";
     				 i++;
    			}
  		}

  while(i < size1 && a[i]!=-1)
   cout<<a[i++];
  while(j < size2 && b[j]!=-1)
   cout<<b[j++];
   
   cout<<"}";
	
}
	void difference()
	{
		int j;
		
		int d=0;

for(int i=0; i<size1; i++) {
bool found=false;
for(int j=0; j<size2; j++) {
if (a[i] == b[j]) {
found = true;
break;
}
}
if (!found) {
diff[d] = a[i];
d++;
}
}

cout << "The difference is \n{";
for(int i=0; i<d; i++) {
cout << diff[i] << " ";
}
d = 0;
cout<<"}";

}

	void subset()
	{
		t *sub;
		int j,no,flag=0;
		cout<<"Enter the no of elements in the subset";
		cin>>no;
		if(no>size1)
		{
			cout<<"not a subset";
		}
		else
		{
			sub=new t[no];
		}
		cout<<"Enter the elements of the subset";
		for(i=0;i<no;i++)
		{
			cin>>sub[i];
		}
		
		for(i=0;i<size1;i++)
		{
			for(j=0;j<no;j++)
			{
				if(a[i]==sub[j])
				{
					flag=1;
					break;
				}
			}
		}
		
		if(flag==1)
		{
			cout<<"The given set is a subset";
		}
		else
		{
			cout<<"The given set is not a subset";
		}
	}


};

int main() 
{
	SET<int>s1;
	int choice;
	char m;
	do
	{
		cout<<"Enter choice \n1.Insert element\n2.Display set\n3.Display size\n4.Find element\n5.Delete element\n6.Intersection of sets\n7.Union of sets\n8.Difference of sets\n9.Check subset\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			s1.add();
			break;
		}
		case 2:
		{
			s1.display();
			break;
		}
		case 3:
		{
			s1.size();
			break;
		}
		case 4:
		{
			s1.contain();
			break;
		}
		case 5:
		{
			s1.del();
			break;
		}
		case 6:
		{
			s1.intersection();
			break;
		}
		case 7:
		{
			s1.uni();
			break;
		}
		case 8:
		{
			s1.difference();
			break;
		}
		case 9:
		{
			s1.subset();
			break;
		}
		}
		cout<<"\nContinue?(y/n)\n";
		cin>>m;
	}while(m=='y' || m=='Y');

	return 0;
}

