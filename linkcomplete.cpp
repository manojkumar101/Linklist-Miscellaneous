#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node *getnode(int val)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
struct node* insert(struct node *head,int n)
{
    int val;
    cout<<"Enther the value to insert"<<endl;
    cin>>val;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(n==1)
    {
        temp->next=head;
        head=temp;
        return head;
    }
    else
    {
        node *flag=head;
        for(int i=0;i<n-2;i++)
        {
            flag=flag->next;
        }
        temp->next=flag->next;
        flag->next=temp;

    }
    return head;
}
struct node *reverse(struct node * head)
{
    struct node * prev,*current,*next;
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
    return prev;

}
int main()
{
    int n;
    cout<<"Enter the number of nodes "<<endl;
    cin>>n;

    struct node *head=NULL,*search;
    int i;
    for(i=0;i<n;i++)
    {   int a;
        cin>>a;
        struct node *ptr=getnode(a);
        if(head==NULL)
            {
                head=ptr;
                search=ptr;
            }
        else
        {
            search->next=ptr;
            search=search->next;
        }
    }









    head=reverse(head);


       search=head;
   while(search!=NULL)
   {
       cout<<search->data<<endl;
       search=search->next;

   }










    /*
   cout<<"Enter the position to be insert a new value";
   cin>>n;
   head=insert(head,n);

   search=head;
   while(search!=NULL)
   {
       cout<<search->data<<endl;
       search=search->next;

   }
    */
}
