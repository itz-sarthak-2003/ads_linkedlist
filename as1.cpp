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
}*start;

void node::del_front(){
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
cout<<"\n        WELCOME TO LIBRARY ! ";
cout<<"\n1.Accept\n2.Display\n3.Delete from front\n4exit";
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
cout<<"Thanks........";
break;
default:
cout<<"Wrong choice";
}
}while(ch!=4);

return 0;
}

