#include <bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node* next;
};
node* top;
void addnode(char x)
{
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    if(top!=NULL)
    {
        temp->next=top;
    }
    top=temp;
}
int isempty()
{
    if(top==NULL)
        return 1;
    else return 0;
}
char pip()
{
    return top->data;
}
void pop()
{
    top=top->next;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{   top=NULL;
	    string str;
	    int flag=0;
	    cin>>str;
	    for(int i=0;str[i]!='\0';i++)
	    {
	        if(str[i]=='{' ||str[i]=='(' ||str[i]=='[')
                addnode(str[i]);
	        else
	        {
	            if(pip()!=str[i])
	             {flag=1,cout<<"not balanced"<<endl;break;}
	             else
	             pop();
	        }
	    }
	    if(isempty())
	    cout<<"balanced"<<endl;
	    else if(flag!=1)
	    cout<<"not balanced"<<endl;

	}
	return 0;
}
