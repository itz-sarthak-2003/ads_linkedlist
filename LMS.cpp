#include<iostream>
using namespace std;

class node{
public:
int bid,price;
string title,author;
node *next;
void accept();
void display();
void del_front();
void del_last();
void del_anynode();
void search();
void update();
}*start;
void node::update(){
    int id,f=0;
    node *temp;
    temp=start;
    cout<<"enter the bid u want to updated :"<<endl;
    cin>>id;
  if(temp==NULL){
    cout<<"record is empty";
  }else{
    while(temp!=NULL){
        if(temp->bid==id){
            cout<<"book data is found"<<endl;
            cout<<"book id"<<endl;
           cin>> temp->bid;
             cout<<"book price"<<endl;
            cin>>temp->price;
             cout<<"book title"<<endl;
            cin>>temp->title;
             cout<<"book author"<<endl;
            cin>>temp->author;
            cout<<"record updated successfully"<<endl;
        } temp=temp->next;
    }
    }
    
};
void node::search(){
    int id,f=0;
    node *temp;
    temp=start;
    cout<<"enter the bid :"<<endl;
    cin>>id;
    while(temp!=NULL){
        if(temp->bid==id){
            f=1;
            cout<<"book data is found"<<endl;
            cout<<"\nBookid\tprice\ttitle\tauthor"<<endl;
           cout<<"\n"<<temp->bid<<" \t"<<temp->price<<"\t "<<temp->title<<"\t "<<temp->author<<endl;
            break;
        }temp=temp->next;
        
    }
}
void node::del_anynode(){
int x;
cout<<"enter the record no.which u want to delete : "<<endl;
cin>>x;
if(x==1){
    node *curr=start;
    start=start->next;
    delete curr;
}else{
node *curr,*prev;
curr=start;
prev=NULL;
x--;
while(x--){
   prev=curr;
   curr=curr->next;    
}
prev->next=curr->next;
delete curr;
cout<<"record deleted successfully"<<endl;
}
}

void node::del_last(){
    if(start==NULL){
        cout<<"library is empty"<<endl;
    }
node *temp,*end;
temp=start;
if(temp->next==NULL){
    delete temp;
}
else{
while(temp->next->next!=NULL){
    temp=temp->next;
}
end=temp->next;
delete end;
temp->next=NULL;
}}

void node::del_front(){
    
    if(start==NULL){
        cout<<"Library is empty"<<endl;
    }
node *temp;
temp=start;
start=start->next;
delete temp;
}

void node::accept(){
node *temp=new node;
cout<<"enter bid, price ,title, author:"<<endl;
cin>>temp->bid>>temp->price>>temp->title>>temp->author;
temp->next=NULL;
temp->next=start;
start=temp;
}


void node::display(){
    if(start==NULL){
        cout<<"Library is empty"<<endl;
    }
int count=0;
 node *temp;
temp=start;
while(temp!=NULL){
cout<<"\n"<<temp->bid<<" \t"<<temp->price<<"\t "<<temp->title<<"\t "<<temp->author<<endl;
temp=temp->next;
count++;
}
cout<<"\nTotal no of books :"<<count;
}


int main(){
node n;
int ch;
do
{
cout<<"\nWELCOME TO LIBRARY ! ";
cout<<"\n1.Accept\n2.Display\n3.Delete from front\n4.Delete from last\n5.Delete any node\n6.search\n7.update\n8.exit";
cout<<"\nENTER YOUR CHOICE = : ";
cin>>ch;
switch(ch)
{
case 1:
n.accept();
break;
case 2:
cout<<"\nBookid\tprice\ttitle\tauthor"<<endl;
n.display();
break;
case 3:
n.del_front();
break;
case 4:
n.del_last();
break;
case 5:
n.del_anynode();
break;
case 6:
n.search();
break;
case 7:
n.update();
break;
case 8:
exit(0);
cout<<"Thanks........";
break;
default:
cout<<"Wrong choice";
}
}while(ch!=10);

return 0;
}