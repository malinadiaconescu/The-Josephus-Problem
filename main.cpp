#include <iostream>
using namespace std;
int n;
class Node
{
public:
    int data;
    Node* next;
};

class List
{
private:
    Node* head;
public:
    List();
    void add_node(int val);
    void print_elements();
    void delete_element(int val);
    int josephus(int pas, int val);
};
List::List()
{
    this->head = NULL;
}
void List::add_node(int val)
{
    if(this->head==NULL)
    {
        this->head=new Node();
        this->head->data=val;
        this->head->next=head;
    }
    else
    {
        Node*x;
        x=new Node();
        x->data=val;
        Node*help;
        help=this->head;
        do
        {
            help=help->next;
        }
        while(help->next!=this->head);
        help->next=x;
        x->next=this->head;
    }

}
void List::print_elements()
{
    Node*help;
    help=this->head;
    if(this->head==NULL)
        cout<<"The list is empty!";
    else
        do
        {
            cout<<help->data<<" ";
            help=help->next;
        }
        while(help!=this->head);
    cout<<endl;
}
void List::delete_element(int val)
{
    Node*help;
    help=this->head;
    int minim=help->data;
    if(help->next==help && help->data==val)
    {
        this->head=NULL;
    }
    else
    {
        int ok=0;
        do
        {
            if(help->next->data==val)
            {
                Node* p=help->next->next;
                Node*q=help->next;
                delete q;
                help->next=p;
                ok=1;
                if(val==minim)
                    this->head=help->next;
            }
            help=help->next;
        }
        while(help!=this->head&&!ok);
    }

}
int List::josephus(int pas,int val)
{
    Node* help;
    help=this->head;
    while(help->data!=val)
        help=help->next;
    int contor=n;
    while(help->next!=help)
    {
        for(int i=1; i<pas-1; i++)
            help=help->next;
        Node* p=help->next->next;
        Node*q=help->next;
        cout<<q->data<<",";
        delete q;
        help->next=p;
        help=help->next;
    }
    cout<<help->data;
    return help->data;
}
int main()
{
    List* mylist = new List();
    int a;
    int n;
    cout<<"Welcome to Malina's program!"<<endl;
    cout<<"What would you like to do?"<<endl;
    cout<<"1 - create a list and play with it"<<endl<<"2 - solve the Josephus problem"<<endl<<"Choose one:";
    cin>>a;
    int ok=1;
    switch(a)
    {
    case 1:
        cout<<"How many elements should your list have?"<<endl<<"Enter:";
        cin>>n;
        for(int i=1; i<=n; i++)
            mylist->add_node(i);
        while(ok)
        {
            cout<<endl<<"1 - print all elements"<<endl<<"2 - delete one element"<<endl<<"3 - add one element"<<endl<<"4 - exit"<<endl<<"Choose one:";
            int aa,x;
            cin>>aa;
            switch(aa)
            {
            case 1:
                mylist->print_elements();
                break;
            case 2:
                cout<<"Enter the value you want deleted:";
                cin>>x;
                mylist->delete_element(x);
                break;
            case 3:
                cout<<"Enter the value you want to add:";
                cin>>x;
                mylist->add_node(x);
                break;
            case 4:
                ok=0;
                cout<<"THANK YOU FOR PLAYING WITH MY PROGRAM! :)";
                break;
            }
        }
        break;
    case 2:
        cout<<"Enter the values for the Josephus problem"<<endl;
        cout<<"How many elements should your list have?"<<endl<<"Enter:";
        cin>>n;
        for(int i=1; i<=n; i++)
            mylist->add_node(i);
        cout<<endl;
        cout<<"starting value:";
        int m;
        cin>>m;
        cout<<endl;
        cout<<"number to be skipped:";
        int z;
        cin>>z;
        cout<<"Here are the values that were taken out of the game, in order:";
        int valoare=mylist->josephus(z,m);
        cout<<endl<<"The last element and the winner is:"<<valoare<<endl;
        cout<<"THANK YOU FOR PLAYING WITH MY PROGRAM! :)";
        break;
    }
}
