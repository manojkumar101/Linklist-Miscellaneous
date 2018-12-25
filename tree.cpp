#include<bits/stdc++.h>
using namespace std;

struct binary
{
    int data;
    binary *left;
    binary *right;
};

binary *getnode(binary *root,int val)
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
        root=getnode(root,val);
    }
    else if(val > root->data)root->right=insert(root->right,val);
    else root->left=insert(root->left,val);
    return root;
}
void preorder(binary *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int max(binary *root)
{
    if(root->right==NULL)
        return root->data;
    max(root->right);
}
binary *minaddress(binary *root)
{
    if(root->left==NULL)
        return root;
    minaddress(root->left);
}
int min(binary *root)
{
    if(root->left==NULL)
        return root->data;
    min(root->left);
}
int nodes(binary *root)
{
    if(root==NULL)
    return 0;
    return (nodes(root->left)+nodes(root->right)+1);
}
int leaf(binary *root)
{   if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return (leaf(root->left)+leaf(root->right));
}
int height(binary *root)
{
    if(root==NULL)
        return -1;
    return (max(height(root->left),height(root->right))+1);
}

binary *deletenode(binary *root,int val)
{
    if(root==NULL)
        {
           // delete root;
            root=NULL;
            return root;
        }
    else if(root->data > val)
    root->left=deletenode(root->left,val);
    else if(root->data < val)
    root->right=deletenode(root->right,val);
    else
    {   binary *temp=root;
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            root=temp->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            root=temp->left;
            delete temp;
        }
        else
        {
            temp=minaddress(root->right);
            root->data=temp->data;
            root->right=deletenode(temp->right,val);
        }
    }
     return root;
}
int main()
{
    int n;
    cin>>n;binary *root=NULL;
    for(int i=0;i<n;i++)
    {
        int val;cin>>val;
        root=insert(root,val);
    }
    preorder(root);
    cout<<endl<<"MAX  "<<max(root)<<endl<<"MIN  "<<min(root)<<endl;
    cout<<"Nodes  present     "<<nodes(root)<<endl;
    cout<<"Leaf Node present  "<<leaf(root)<<endl;
    cout<<"Height of Tree     "<<height(root)<<endl;
    cout<<"Enter node to be delete  ";cin>>n;
    root=deletenode(root,n);
    cout<<"Nodes  present     "<<nodes(root)<<endl;preorder(root);


}
