
#include<bits/stdc++.h>
using namespace std;

struct binary
{
    int data;
    int count;
    binary *left;
    binary *right;
};

binary *getnode(binary *root,int val,int count)
{
    binary *temp=new binary;
    temp->count=count;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
binary *insert(binary *root,int val,int count)
{
    if(root==NULL)
    {
        root=getnode(root,val,count);
    }
    else if(val > root->data){count++;root->right=insert(root->right,val,count);}
    else {count--;root->left=insert(root->left,val,count);}
    return root;
}
void preorder(binary *root,int i)
{
    if(root==NULL)
        return;
    if(root->count==i)
        cout<<root->data<<" ";
    preorder(root->left,i);
    preorder(root->right,i);
}
int max1(binary *root)
{
    if(root->right==NULL)
        return root->count;
    max1(root->right);
}

int min1(binary *root)
{
    if(root->left==NULL)
        return root->count;
    min1(root->left);
}




int main()
{
    int n;
    cin>>n;binary *root=NULL;
    for(int i=0;i<n;i++)
    {
        int val;cin>>val;
        root=insert(root,val,0);
    }
    int i=min1(root),j=max1(root);
    for(;i<=j;i++)
    {
        preorder(root,i);
        cout<<endl;
    }

}
