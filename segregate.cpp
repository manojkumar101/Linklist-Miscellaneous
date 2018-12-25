#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node * next;
};


node* addnode(int x,node *head)
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
    return head;
}
void show(node * head)
{
    node* search=head;
    while(search!=NULL)
           {
               cout<<search->data<<" ";
               search=search->next;
           }
           cout<<endl;

}
node * segregate(node* head)
{
    node* search=head,*link=NULL,*prev=NULL;
    while(search!=NULL && search->next!=NULL)
    {
        if((search->data)%2!=0)
        {
            link=addnode(search->data,link);
            node *temp=search->next;
            search->data=temp->data;
            search->next=temp->next;
            free(temp);
        }
        else
        {   prev=search;

            search=search->next;
        }
    }
    if(search!=NULL && search->next==NULL && (search->data)%2==0)
        prev=prev->next;
    else if(search!=NULL && search->next==NULL && (search->data)%2!=0)
        link=addnode(search->data,link);

   // show(prev);
    if(search==head)
        head=link;
    else
        prev->next=link;
    return head;


}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    node *head=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        head=addnode(a,head);
    }
    head=segregate(head);
    show(head);
    }
    return 0;
}
