#include <iostream>
using namespace std;

class node
{
public:
    int id,mobile;
    string name,address;
    node *next,*prev;
    void add_donor(); // to add info of donor
    void display();
    void remove_donor(); // to remove donor info
    void search();      // for searching donor info
    void update();      // for updating donor info

} *start,*end1;               // pointing to the first node
int count=0;

// //for updating purpose
void node::update()
{
    int _id, f = 0;
    node *temp;
    temp = start;
    cout << "enter the donor id u want to updated :" << endl;
    cin >> _id;
    if (temp == NULL)
    {
        cout << "record is empty";
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->id == _id)
            {
                f=1;
                cout << "charity data is found" << endl;
                cout << " donor id : " << endl;
                cin >> temp->id;
                cout << "donor name : " << endl;
                cin >> temp->name;
                cout << "donor mobile : " << endl;
                cin >> temp->mobile;
                cout << "donor address : " << endl;
                cin >> temp->address;
                cout << "record updated successfully" << endl;
            }
            temp = temp->next;
        }
        if(f==0){
            cout<<"record is not found"<<endl;
        }
    }
};

// //for search purpose
void node::search()
{
    int _id, f = 0;
    node *temp;
    temp = start;
    cout << "enter the donor id which u want to search :" << endl;
    cin >> _id;
    while (temp != NULL)
    {
        if (temp->id == _id)
        {
            f = 1;
            cout << "donor data is found" << endl;
            cout<<"donor information : "<<endl;
            cout << "\nid\tname\tmobile\taddress" << endl;
            cout<<  "\n"<<temp->id <<" \t" << temp->name <<" \t" << temp->mobile <<" \t" << temp->address<<endl;
            break;
        }
        temp = temp->next;
    }
    if(f==0){
        cout<<"record is not found"<<endl;
    }
}

//for del 
void node::remove_donor()
{
    int x,f=0;
    node *temp,*p;
    temp=start;
    cout << "enter the record no.which u want to delete : " << endl;
    cin >> x;
    while(temp !=NULL){
        if(temp->id==x){
            f=1;
            break;
    }
    p=temp;
    temp=temp->next;
    }
    p->next=temp->next;
temp->next->prev=p->next;
delete temp;

}

//for accept
void node::add_donor()
{
    node *temp = new node;
    cout << "enter id, name,mobile,address of donor :" << endl;
    cin >> temp->id >> temp->name >> temp->mobile >> temp->address;
    temp->next = NULL;
    temp->prev=NULL;
    if(start==NULL){
        end1=start=temp;
    }
    else{
        end1->next=temp;
        temp->prev=end1;
        end1=temp;
    }
}

//for display
void node::display()
{   
    if (start == NULL)
    {
        cout << "List is empty" << endl;
    }
    int count = 0;
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        cout << "\n"<< temp->id << " \t" << temp->name << "\t " << temp->mobile << "\t " << temp->address << endl;
        temp = temp->next;
        count++;//for counting records
    }
    cout << "\nTotal no of donors :" << count;
}

int main()
{
    node n;
    int ch;
    do
    {
        cout << "\n1.Add donor information\n2.Display\n3.Remove donor information\n4.search\n5.update\n6.exit";
        cout << "\nENTER YOUR CHOICE = : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            n.add_donor();
            break;
        case 2:
        cout<<"\ndonor information : "<<endl;
            cout << "\nid\tname\tmobile\taddress" << endl;
            n.display();
            break;
        case 3:
            n.remove_donor();
            break;
        case 4:
            n.search();
            break;
        case 5:
            n.update();
            break;

        case 6:
            exit(0);
            cout << "Thanks........";
            break;
        default:
            cout << "Wrong choice";
        }
    } while (ch != 6);

    return 0;
}