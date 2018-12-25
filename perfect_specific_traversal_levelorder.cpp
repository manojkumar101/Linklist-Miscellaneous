#include<bits/stdc++.h>
using namespace std;
// logic right tree creation wrong
struct binary
{
    int data;
    binary *left;
    binary *right;
};

binary *getbinary(binary *root,int val)
{
    binary *temp=new binary;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
binary *insert(binary *root,int val)
{
    if(root==NULL)
    {
        root=getbinary(root,val);
    }
    else if(val > root->data)root->right=insert(root->right,val);
    else root->left=insert(root->left,val);
    return root;
}
queue<binary*> queue1;
queue<binary*> queue2;

int main()
{
    int n;
    cin>>n;binary *root=NULL;
    for(int i=0;i<n;i++)
    {
        int val;cin>>val;
        root=insert(root,val);
    }
    cout<<"OUTPUT"<<endl<<root->data<<" ";
    queue1.push(root->left);
    queue2.push(root->right);
    int i=0;
    while(1)
    {
        if(i%2==0)
        {
            if(!queue1.empty())
            {
               binary *temp=queue1.front();
               queue1.pop();
               cout<<temp->data<<" ";
               if(temp->left!=NULL)
               queue1.push(temp->left);
               if(temp->right!=NULL)
               queue1.push(temp->right);
            }
            else
            break;

        }
        else
        {
             if(!queue2.empty())
            {
               binary *temp=queue2.front();
               queue2.pop();
               cout<<temp->data<<" ";
               if(temp->right!=NULL)
                    queue2.push(temp->right);
               if(temp->left!=NULL)
                    queue2.push(temp->left);
            }
            else
            break;
        }
        i++;
    }
}
