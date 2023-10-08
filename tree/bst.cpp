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

    node()
    {
        int data;
        node* left;
        node* right;
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

void searchkey(node* root,int key)
{
    if(root == NULL)
    {
        return;
    }

    if(root->data == key)
    {
        cout << "Key element was found";
        return;
    }
    searchkey(root->left,key);
    searchkey(root->right,key);
    // // inorder(root);
    // if(key < root -> data)
    // {
    //     if(key == root -> data)
    //     {
    //         return;
    //     }
    //     root = root -> left;
    // }
    // else if (key > root -> data)
    // {
    //     if(key == root -> data)
    //     {
    //         return;
    //     }
    //     root = root -> right;
    // }
}

// void bfstrav(node* &root)
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     cout<<root->data;
//     bfstrav(root->left);
// }

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
    // //descendinginorder(rootnode);
    // cout <<endl<< "BFS traversal: "<<endl;
    cout << endl;
    searchkey(rootnode,5);
    return 0;
}