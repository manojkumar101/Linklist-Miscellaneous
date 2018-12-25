#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node * next;
};
node *head=NULL;

void addnode(int x)
{
    node* search=head;
    node* temp=new node();
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(search->next!=NULL)
            search=search->next;
            search->next=temp;
    }
}
void show()
{
    node* search=head;
    while(search!=NULL)
           {
               cout<<" "<<search->data;
               search=search->next;
           }

}
void deletenode(int val)
{
    node* search=head;
    if(search->data==val)
        {head=head->next;show();return;}
    while(search->next->data!=val)
           {
               search=search->next;
           }

           node* temp=search->next;
           search->next=temp->next;
           delete(temp);
           show();

}
void position(int pos)
{
    node* search=head;
    if(pos==1)
        {head=head->next;show();return;}
    for(int i=0;i<pos-2;i++)
    {
        search=search->next;
    }
           node* temp=search->next;
           search->next=temp->next;
           delete(temp);
           show();
}
int main()
{
    int n;
    cout<<"Enter the no node wants to add \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cout<<"Enter the value to be insert";cin>>a;
        addnode(a);
    }
    show();
    cout<<"\nEnter the node wants to delete\n";cin>>n;
    deletenode(n);
    cout<<endl;
    show();
    cout<<"\nEnter the position of node wants to delete\n";cin>>n;
    position(n);
    return 0;
}
