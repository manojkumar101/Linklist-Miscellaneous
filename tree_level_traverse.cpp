
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
void inorder(binary *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
            delete root;
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

struct queue1
{
    binary *link;
    queue1 *next;
};

queue1 *front=NULL ,*rear=NULL,*top=NULL;
void push(binary* root)
{
    queue1 *temp=new queue1;
        temp->link=root;
        temp->next=NULL;
     if(front==NULL)
     {
         front=temp;
         rear=front;
     }
     else
     {
         rear->next=temp;
         rear=rear->next;
     }
}
void push_as_stack(binary* root)
{
    queue1 *temp=new queue1;
        temp->link=root;
        temp->next=NULL;
     if(top!=NULL)
     {
         temp->next=top;
     }
     top=temp;
}
binary* pop()
{
    binary* x;
    queue1 *p;
    p=front;
    front=front->next;
    x=p->link;
    delete p;
    return x;
}
binary* pop_stack()
{
    binary* x;
    queue1 *p;
    p=top;
    top=top->next;
    x=p->link;
    delete p;
    return x;
}
int size()
{
    queue1 *count=front;
    int c=0;
    while(count!=NULL)
    {
        c++;count=count->next;
    }
    return c;
}
//tree traversal without stack and recursion

void morrispreordertraversal(binary *root)
{
    while(root)
    {
        if(root->left==NULL)
        {
            cout<<root->data<<" ";
            root=root->right;
        }
        else
        {
            binary *current=root->left;
            while(current->right && current->right!=root)
                current=current->right;

            if(current->right==root)
            {
                current->right=NULL;
                root=root->right;
            }
            else
            {
                cout<<root->data<<" ";
                current->right=root;
                root=root->left;
            }
        }
    }
}
//tree traversal without stack and recursion

void morrisinordertraversal(binary *root)
{
    while(root)
    {
        if(root->left==NULL)
        {
            cout<<root->data<<" ";
            root=root->right;
        }
        else
        {
            binary *current=root->left;
            while(current->right && current->right!=root)
                current=current->right;

            if(current->right==root)
            {
                cout<<root->data<<" ";
                current->right=NULL;
                root=root->right;
            }
            else
            {
                current->right=root;
                root=root->left;
            }
        }
    }
}
void levelwise(binary *root)
{
    binary *temp;
    push(root);
    while(front!=NULL)
        {
                int loop=size();
                while(loop--)
                    {
                        temp=pop();
                        cout<<temp->data<<" ";
                        if(temp->left!=NULL)
                        push(temp->left);
                        if(temp->right!=NULL)
                        push(temp->right);

                    }
                    cout<<endl;
    }
}
void reverselevelwise(binary *root)
{
    binary *temp;
    push(root);
    push_as_stack(root);
    while(front!=NULL)
        {
                        temp=pop();
                        if(temp->right!=NULL)
                        {push(temp->right);push_as_stack(temp->right);}

                        if(temp->left!=NULL)
                        {push(temp->left);push_as_stack(temp->left);}


    }
    while(top!=NULL)
    {
        temp=pop_stack();
        cout<<temp->data<<" ";

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
    cout<<"Preorder Traversal   "<<endl;
    preorder(root);
    cout<<endl<<"MAX  "<<max(root)<<endl<<"MIN  "<<min(root)<<endl;
    cout<<"Nodes  present     "<<nodes(root)<<endl;
    cout<<"Leaf Node present  "<<leaf(root)<<endl;
    cout<<"Height of Tree     "<<height(root)<<endl;



    cout<<endl<<"Press Y if you want deletion mode";char ch;cin>>ch;
    if(ch=='Y')
    {
      cout<<"Enter node to be delete  ";cin>>n;
    root=deletenode(root,n);
    cout<<"Nodes  present     "<<nodes(root)<<endl;preorder(root);
    }


    cout<<"Level wise order "<<endl;
            levelwise(root);

    cout<<"Reverse Level wise order "<<endl;
            reverselevelwise(root);



    cout<<endl<<"Preorder Traversal   "<<endl;
            preorder(root);
    cout<<endl<<"Morris Preorder traversal "<<endl;
            morrispreordertraversal(root);
    cout<<endl<<"Inorder Traversal   "<<endl;
            inorder(root);
    cout<<endl<<"Morris Inorder Traversal   "<<endl;
            morrisinordertraversal(root);


}
