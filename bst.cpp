#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    node* left = NULL;
    int data;
    node* right = NULL;
    
    node(int val)
    {
        data = val;
    }
};

class bst
{
    public:
    node* root;
    bst()
    {
        root = NULL;
    }
};

node* insertnode(node* &root, int val)
{
    node* newnode = new node(val);
    if(root == NULL)
    {
        root = newnode;
        cout << root -> data << " ";
    }
    node* temp = root;
    if(newnode -> data > root -> data)
    {
        root->right = insertnode(root->right,val);
    }
    else if(newnode -> data < root -> data)
    {
        root -> left = insertnode(root -> left,val);
    }
    return root;
}

void inorder(node* &root)
{   
    if(root!= NULL)
    {
        inorder(root->left);
        cout<<root->data << " ";
        inorder(root->right);
    }
}

// void descendinginorder(node* &root)
// {   
//     if(root!= NULL)
//     {
//         inorder(root->right);
//         cout<<root->data << " ";
//         inorder(root->left);
//     }
// }

void preorder(node* &root)
{   
    if(root!= NULL)
    {
        cout<<root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* &root)
{   
    if(root!= NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data << " ";
    }
}

void bfstrav(node* &root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data;
    bfstrav(root->left);
}

int main()
{
    node* rootnode = NULL;
    // insertnode(rootnode,7);
    insertnode(rootnode,4);
    insertnode(rootnode,2);
    insertnode(rootnode,5);
    insertnode(rootnode,1);
    insertnode(rootnode,3);
    insertnode(rootnode,6);
    // insertnode(rootnode,8);
    // insertnode(rootnode,9);
    cout<<endl<<"Inorder Traversal:"<<endl;
    inorder(rootnode);
    cout<<endl<<"Preorder Traversal:"<<endl;
    preorder(rootnode);
    cout<<endl<<"Postorder Traversal:"<<endl;
    postorder(rootnode);
    // cout<<endl<<"Descending order: "<<endl;
    //descendinginorder(rootnode);
    return 0;
}