#include <iostream>
using namespace std;

class node
{
public:
    int bid, price;
    string title, author;
    node *next;
    void accept_front(); // insert at first
    void display();
    void del_front();   // delete first
    void del_last();    // del last
    void del_anynode(); // del any
    void search();      // for search
    void update();      // for update
    void add_end();     // add at the end
} *start;               // pointing to the first node
int count=0;
// insert at the end
void node::add_end()
{
    node *newptr = new node;
    node *temp;
    cout << "book id" << endl;
    cin >> newptr->bid;
    cout << "book price" << endl;
    cin >> newptr->price;
    cout << "book title" << endl;
    cin >> newptr->title;
    cout << "book author" << endl;
    cin >> newptr->author;

    newptr->next = NULL;
    if (start == NULL)
    {
        start = newptr;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newptr;
    }
}

//for updating purpose
void node::update()
{
    int id, f = 0;
    node *temp;
    temp = start;
    cout << "enter the bid u want to updated :" << endl;
    cin >> id;
    if (temp == NULL)
    {
        cout << "record is empty";
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->bid == id)
            {
                f=1;
                cout << "book data is found" << endl;
                cout << "book id" << endl;
                cin >> temp->bid;
                cout << "book price" << endl;
                cin >> temp->price;
                cout << "book title" << endl;
                cin >> temp->title;
                cout << "book author" << endl;
                cin >> temp->author;
                cout << "record updated successfully" << endl;
            }
            temp = temp->next;
        }
        if(f==0){
            cout<<"record is not found"<<endl;
        }
    }
};

//for search purpose
void node::search()
{
    int id, f = 0;
    node *temp;
    temp = start;
    cout << "enter the bid :" << endl;
    cin >> id;
    while (temp != NULL)
    {
        if (temp->bid == id)
        {
            f = 1;
            cout << "book data is found" << endl;
            cout << "\nBookid\tprice\ttitle\tauthor" << endl;
            cout << "\n"<< temp->bid << " \t" << temp->price << "\t " << temp->title << "\t " << temp->author << endl;
            break;
        }
        temp = temp->next;
    }
    if(f==0){
        cout<<"record is not found"<<endl;
    }
}

//for del any node
void node::del_anynode()
{
    int x;
    cout << "enter the record no.which u want to delete : " << endl;
    cin >> x;
    if (x == 1)
    {
        node *curr = start;
        start = start->next;
        delete curr;
    }
    else
    {
        node *curr, *prev;
        curr = start;
        prev = NULL;
        x--;
        while (x--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        cout << "record deleted successfully" << endl;
    }
}

//for del last node
void node::del_last()
{
    if (start == NULL)
    {
        cout << "library is empty" << endl;
    }
    node *temp, *end;
    temp = start;
    if (temp->next == NULL)
    {
        delete temp;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        end = temp->next;
        delete end;
        temp->next = NULL;
    }
}


//for delete first node
void node::del_front()
{

    if (start == NULL)
    {
        cout << "Library is empty" << endl;
    }
    node *temp;
    temp = start;
    start = start->next;
    delete temp;
}


//for accept at 1st position
void node::accept_front()
{
    node *temp = new node;
    cout << "enter bid, price ,title, author:" << endl;
    cin >> temp->bid >> temp->price >> temp->title >> temp->author;
    temp->next = NULL;
    temp->next = start;
    start = temp;
}

//for display
void node::display()
{
    if (start == NULL)
    {
        cout << "Library is empty" << endl;
    }
    int count = 0;
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        cout << "\n"<< temp->bid << " \t" << temp->price << "\t " << temp->title << "\t " << temp->author << endl;
        temp = temp->next;
        count++;//for counting records
    }
    cout << "\nTotal no of books :" << count;
}

int main()
{
    node n;
    int ch;
    do
    {
        cout << "\nWELCOME TO LIBRARY ! ";
        cout << "\n1.Accept\n2.Display\n3.Delete from front\n4.Delete from last\n5.Delete any node\n6.search\n7.update\n8.at_end\n9.exit";
        cout << "\nENTER YOUR CHOICE = : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            n.accept_front();
            break;
        case 2:
            cout << "\nBookid\tprice\ttitle\tauthor" << endl;
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
            n.add_end();
            break;
        case 9:
            exit(0);
            cout << "Thanks........";
            break;
        default:
            cout << "Wrong choice";
        }
    } while (ch != 10);

    return 0;
}