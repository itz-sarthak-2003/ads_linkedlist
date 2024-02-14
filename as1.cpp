#include<iostream>
using namespace std;

class node{
public:
int bid,price;
string title,author;
node *next;
void accept();
void display();
}*start;


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
cout<<"\n....................................... ";
cout<<"\n..........1.Accept\n..........2.Display\n..........3.Exit";
cout<<"\n........................................ ";
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
cout<<"Thanks........";
break;
default:
cout<<"Wrong choice";
}
}while(ch!=3);

return 0;
}

