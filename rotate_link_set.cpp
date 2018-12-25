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
node * reversenode(node* head)
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
    return head;
}
void rotate(struct node *head_ref, int k)
{
  // Complete this method
    node *search=head_ref;
    while(--k)
    {
        search=search->next;
    }
    node *temp=search->next;
    search->next=NULL;
    temp=reversenode(temp);
    search=temp;
    while(search!=NULL)
        cout<<search->data<<" ";
        search=head_ref;
    while(search!=NULL)
        cout<<search->data<<" ";
    cout<<endl;
}

int main()
{
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    node *head=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a>>k;
        head=addnode(a,head);
    }
    rotate(head,k);
    }
    return 0;
}
