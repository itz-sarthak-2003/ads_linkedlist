#include<iostream>
using namespace std;
int n,i;
class LMS{
    int bid,price;
    char *title,*author,*publisher;
    public:
    void accept();
    void display();
    void search();
    void update();
    void Delete();
}b[100];
void LMS::accept(){
    title=new char;
    author=new char;
    publisher=new char;
    cout<<"enter the bid,price,title, author, publisher"<<endl;
    cin>>bid>>price>>title>>author>>publisher;
};
void LMS::display(){ 
        cout<<"\n"<<bid<<"\t"<<price<<"\t"<<title<<"\t"<<author<<"\t"<<publisher<<endl;
};
void LMS::search(){
    int bookid,f=0;
    cout<<"enter the book id which u want to search :"<<endl;
    cin>>bookid;
    for( i=0;i<n;i++){
        if(b[i].bid==bookid){
            f=1;
            cout<<"book is found at location "<<i+1<<endl;
            cout<<"\nID\tPRICE\tTITLE\tAUTHOR\tPUBLISHER";
            b[i].display();
            break;
        }
    }
    if(f==0)
    cout<<"Book is not found"<<endl;
};
void LMS::update(){
    int bookid,f=0;
    cout<<"enter book id which u want to update"<<endl;
    cin>>bookid;
    for( i=0;i<n;i++){
        if(bookid==b[i].bid){
            f=1;
            cout<<"record is found at location "<<i+1<<endl;
            b[i].accept();
            cout<<"\nID\tPRICE\tTITLE\tAUTHOR\tPUBLISHER";
            b[i].display();
            cout<<"record has been updated at location "<<i+1<<endl;
            break;
        }
    }
    if(f==0){
        cout<<"Record is not found"<<endl;
    }
};
void LMS::Delete(){
    int bookid,f=0;
    cout<<"enter book id which u want to delete :"<<endl;
    cin>>bookid;
    for(i=0;i<n;i++){
        if(bookid==b[i].bid){
            f=1;
            cout<<"record deleted successfully at location "<<i+1<<endl;
                b[i]=b[i+1];
            n--;
            break;
            
        }
    }
     if(f==0){
        cout<<"Record is not found"<<endl;
    }
}
int main()
{
    int ch;
    cout<<"enter total no. of books :"<<endl;
    cin>>n;
    do{
    cout<<"\n*****MENU*****\nEnter ur choice\n1.Accept book\n2.Display book\n3.search\n4.update\n5.delete\n6.exit"<<endl;
    cout<<"enter ur choice : "<<endl;
    cin>>ch;
    switch(ch){
        case 1:
        for(i=0;i<n;i++){
            b[i].accept();
        }
        cout<<"Record accepted !"<<endl;
        break;
        case 2:
        cout<<"Available Records : "<<endl;
        cout<<"\nID\tPRICE\tTITLE\tAUTHOR\tPUBLISHER";
        for(i=0;i<n;i++){
            b[i].display();
        }
        break;
        case 3:
        b[i].search();
        break;
        case 4:
        b[i].update();
        break;
        case 5:
        b[i].Delete();
        break;
        case 6:
        exit(0);
        break;
        default:
        cout<<"wrong choice!";
    }}
    while(ch!=6);
return 0;
}
