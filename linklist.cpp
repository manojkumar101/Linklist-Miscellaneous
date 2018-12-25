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
    return 0;
}
