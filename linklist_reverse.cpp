
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node * next;
};
node *head=NULL;
void recursion_reverse(node* root)
{
    if(root->next==NULL)
    {
        head=root;
        return ;
    }
    recursion_reverse(root->next);
    node *temp=root->next;
    temp->next=root;
    root->next=NULL;
}

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
void reversenode()
{
    node* current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    show();
}
void palindrome()
{

     node *first=head,*second=head;
    while(second!=NULL && second->next!=NULL)
    {
        first=first->next;
        second=second->next;
    }

    second=head;
    node* current,*prev,*next;
    current=first;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    first=prev;
    //first=first->next;
    while(first!=NULL)
    {
        if(second->data!=first->data)
            {cout<<"false";return;}
            first=first->next;
            second=second->next;
    }
    cout<<"true"<<endl;
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
    cout<<endl;
    palindrome();
    cout<<endl;
    recursion_reverse(head);
    show();
    cout<<endl;
    reversenode();
    return 0;
}
