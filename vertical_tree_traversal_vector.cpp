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
vector< pair<int,int> > mp;
void traversal(binary *root,int level)
{
    if(root==NULL)
        return;
     mp.push_back(make_pair(level,root->data));
     traversal(root->left,level-1);
     traversal(root->right,level+1);
}
void verticalOrder(binary *root)
{

    int level=0,next;
    traversal(root,level);
    sort(mp.begin(),mp.end());
    next=mp[0].first

    for( ; it!=mp.end() ; it++){
        if(it->first != next){
            cout<<endl;
            next=it->first;
        }
        cout<< it->second->data <<" ";
    }

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
