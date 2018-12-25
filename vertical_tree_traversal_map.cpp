#include<bits/stdc++.h>
using namespace std;

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
void traversal(binary *root, multimap< int,binary* > &m,int level)
{
    if(root==NULL)
        return;
     m.insert(make_pair(level,root));
     traversal(root->left,m,level-1);
     traversal(root->right,m,level+1);
}
void verticalOrder(binary *root)
{
    multimap<int,binary*> mp;
    int level=0,next;
    traversal(root,mp,level);
    multimap<int,binary*>::iterator it=mp.begin();
    next=it->first;
    for( ; it!=mp.end() ; it++){
        if(it->first != next){
            cout<<endl;
            next=it->first;
        }
        cout<< it->second->data <<" ";
    }
    cout<<"$";
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
    verticalOrder(root);
}
