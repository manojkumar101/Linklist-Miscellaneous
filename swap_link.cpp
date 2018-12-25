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
node* addressnode(int val)
{
    node* search=head;
    while(search->next->data!=val)
           {
               search=search->next;
           }

           return search;

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
    int a,b;
    cout<<"\nEnter the node\n";cin>>a;
    node *temp1=addressnode(a);
    cout<<"\nEnter the node want\n";cin>>b;
    node *temp2=addressnode(b);
    node *temp5,*temp4,*temp3;
    if(temp1->next!=temp2)
    {
    temp3=temp1->next;
    temp4=temp1->next->next;
    temp5=temp2->next->next;
    temp1->next=temp2->next;
    temp2->next=temp3;;
    temp1->next->next=temp4;
    temp2->next->next=temp5;
    }else
    {
        temp3=temp2->next;
        temp2->next=temp3->next;
        temp4=temp1->next;
        temp1->next=temp3;
        temp3->next=temp4;
    }
    show();
    return 0;
}
