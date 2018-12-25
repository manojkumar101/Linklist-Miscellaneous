#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node * next;
    node * prev;
};
void show(node* head)
{
    node* search=head;
    while(search!=NULL)
           {
               cout<<" "<<search->data;
               search=search->next;
           }
           cout<<endl;

}
node* insertnode(node *head)
{       int i,n,x;char nam[20];
        printf("Enter the node position  :: ");
        scanf("%d",&n);
        printf("\n Data ::");
        scanf("%d",&x);

      node *temp=new node();
      temp->data=x;
      temp->next=NULL;
      temp->prev=NULL;
      if(n==1)
        {
            if(head!=NULL)
            {
             temp->next=head;
            }
            head=temp;

        }
      else{
      node* search=head;
      for(i=0;i<n-2;i++)
        search=search->next;
      temp->next=search->next;
      temp->prev=search;
      search->next=temp;
      }

    return head;
}
node *deletenode(node* head,int n)
{
    if(n==1)
        {
            node *temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
      else{
      node* search=head;
      for(int i=0;i<n-2;i++)
        search=search->next;
        node *temp=search->next;
              search->next=temp->next;
              search=search->next;
              search->prev=temp->prev;
              delete temp;
      }
      return head;
}
void reversenode(node *head)
{   printf("\n!!!!backward direction !!!!\n");
    node* search=head;
    while(search->next!=NULL)
    {search=search->next;}
     while(search!=NULL)
      {
      cout<<search->data<<" ";
      search=search->prev;
     }

}

int main()
{   int x;
    int flag=0,i,ch,n;node *head=NULL,*search;
    while(1)
    {
    printf("\n1.ADD NODE\n2.ADD NODE AT ANY POSITION\n3.DELETE NODE FROM ANY POSITION\n4.DISPLAY LIST\n5.DISPLAY REVERSE\n6.REVERT\nENTER YOUR CHOICE  ::");
    scanf("%d",&ch);
        switch(ch)
            {
                case 1:printf("Enter the number of Inputs\n");
                       scanf("%d",&n);
                        for(int i=0;i<n;i++)
                        {
                            node* temp=new node();
                            temp->next=NULL;
                            temp->prev=NULL;
                            cout<<"Enter the value to be insert";cin>>temp->data;
                            if(head==NULL)
                            {
                                head=temp;
                                search=head;
                            }
                            else
                            {
                                temp->prev=search;
                                search->next=temp;
                                search=search->next;
                            }

                        }
                        break;
                case 2:head=insertnode(head);
                       show(head);
                            break;
                case 3:printf("\nEnter position:: ");
                       scanf("%d",&n);
                       head=deletenode(head,n);
                            show(head);
                            break;
                case 4:printf("\nDISPLAY LIST\n");
                       show(head);
                       break;
                case 5:reversenode(head);


            }
    }
    return 0;
}
