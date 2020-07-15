#include<iostream>
#include<fstream>
using namespace std;
#define MAX 55
class node{
public:
    string key,value;
    int index;
    node(){
        key=value="";
        index=-1;
    }
    void operator =(node &b){
        this->key=b.key;
        this->value=b.value;
        this->index=b.index;
    }
};
class Hash{
    node arr[26];
    int size;
protected:
    int f(string key){
        if(key[0]<97 || key[0]>122){
            cout<<"Invalid\n";
            return -1;
        }
        return key[0]-97;
    }

    node insert(node temp){
        int index=f(temp.key);
        int i;
        if(index==-1)return temp;
        for(i=index;true;i=(i+1)%26){
            if(arr[i].key==""){
                temp.index=i;
                arr[i]=temp;
                size++;
                return arr[i];
            }
        }

    }
    void replaceInsert(string name,string num){
        int index=f(name);
        int i;
        if(index==-1)return;
        for(i=index;true;){
            if(arr[i].key==""){
                arr[i].key=name;
                arr[i].value=num;
                arr[i].index=i;
                size++;
                return;
            }
           /* if(arr[i].key[0]!=name[0]){
                string tempKey=arr[i].key;
                string tempVal=arr[i].value;
                arr[i].key=name;
                arr[i].value=num;
                name=tempKey;
                num=tempVal;

            }*/
            i=(i+1)%26;

        }

    }

public:
    Hash(){
        size=0;
        for(int i=0;i<26;i++){
            arr[i].value=arr[i].key="";
        }
    }

    node insert(){
        node temp;
        if(size>=26)
        {
            cout<<"Full\n";
            return temp;
        }
        cout<<"Enter name\n";
        cin>>temp.key;
        string name=temp.key;
        string num;
        if(name[0]<97 || name[0]>122)
            return temp;
        cout<<"Enter number\n";
        cin>>num;
        temp.value=num;

        return insert(temp);
        //replaceInsert(name,num);
    }
    int find(){
        string name;
        cout<<"Enter name\n";
        cin>>name;
        int index=f(name);
        if(index==-1)
            return -1;
        int i=index;
        do{
            if(arr[i].key==name){
                cout<<"Present\n";
                return i;
            }

            i=(i+1)%26;
        }while(i!=index);


        cout<<"Not Present\n";

        return -1;


    }
    int del(){
        string name;
        cout<<"Enter name\n";
        cin>>name;
        int index=f(name);
        int i=index;
        do{
            if(arr[i].key==name){
                arr[i].key="";
                arr[i].value="";
                return i;
            }
            i=(i+1)%26;
        }while(i!=index);
        cout<<"Not Present\n";
        return -1;

    }

    void print(){
    	//cout<<"in print"<<endl;
        int i;
        for(i=0;i<26;i++){
            if(arr[i].key!=""){
                cout<<i<<"\t"<<arr[i].key<<"\t"<<arr[i].value<<endl;
            }
        }
    }

};
class Operations{
    Hash h;
    ifstream in;
    ofstream out;
public:
    Operations(){
    }
    void openFileWrite(){
        out.open("i.txt",ios::binary | ios::ate);
        //       if(out)
        //           cout<<"YEAH";
        //       else
        //           cout<<"NO";
    }
    void openFileRead(){
        in.open("i.txt",ios::in | ios::binary);
    }

    void closeFileWrite(){
        if(out)
            out.close();
    }

    void closeFileRead(){
        if(in)
            in.close();
    }
    void readFile(int index){
        openFileRead();
        node ob;
        in.seekg(sizeof(ob)*index);
        in.read((char*)&ob,sizeof(ob));
        cout<<ob.key;
        //closeFileRead();
    }

    void writeToFile(node ob,int index){
        openFileWrite();
        if(out){
            out.seekp(sizeof(ob)*index);
            out.write((char*)&ob,sizeof(ob));
        }
        closeFileWrite();
        //readFile(index);
    }
    void insert(){
        node ob=h.insert();
        if(ob.index==-1){
            return;
        }
        writeToFile(ob,ob.index);
    }
    void find(){
        int index=h.find();
        cout<<index<<endl;
        if(index==-1)
            return;
        readFile(index);
    }
    void del(){
        int index=h.del();
        if(index==-1)return;
        node blank;
        writeToFile(blank,index);
    }
    void print(){
	h.print();
    }
};

int main(){
    Operations h; //Hash h1;
    int choice;
    while(1){
        cout<<"1.Insert\n";
        cout<<"2.Find\n";
        cout<<"3.Delete\n";
       	cout<<"4.Print\n";
        cin>>choice;
        switch (choice) {
        case 1:
            h.insert();
            break;
        case 2:
            h.find();
            break;
        case 3:
            h.del();
            break;
        case 4:
            h.print();
            break;
        default:
            //return 0;
            cout<<"Enter valid choice\n";
        }
    }

    return 0;
}
