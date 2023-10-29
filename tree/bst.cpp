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

node* insertNodeIterative(node* &root, int val)
{
    node* newnode = new node(val);
    if (root == NULL)
    {
        root = newnode;
        cout << newnode->data << " ";
        return root;
    }

    node* current = root;
    node* parent = nullptr;

    while (current != nullptr)
    {
        parent = current;

        if (val > current->data)
        {
            current = current->right;
        }
        else if (val < current->data)
        {
            current = current->left;
        }
        else
        {
            // Value already exists, you can decide what to do here.
            return root;
        }
    }

    if (val > parent->data)
    {
        parent->right = newnode;
    }
    else
    {
        parent->left = newnode;
    }

    cout << newnode->data << " ";
    return root;
}


// node* insertnodeiterative(node* &root, int val)
// {
//     node* newnode = new node(val);
//     if(root == NULL)
//     {
//         root = newnode;
//         cout << root -> data << " ";
//         return root;
//     }
//     node* temp = root;
//     while(temp != NULL)
//     {
//         if(newnode -> data < root -> data)
//         {
//             temp = temp -> left;
//         }
//         else if(newnode -> data > root -> data)
//         {
//             temp = temp -> right;
//         }
//         else
//         {
//             return root;
//         }


//     }
// }

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

void bfsTraversal(node* root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != nullptr)
        {
            q.push(current->left);
        }

        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

// void bfstrav(node* &root)
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     cout<<root->data << " ";
//     bfstrav(root->left);
//     bfstrav(root->right);
// }

node* minimumval(node* root)
{
    node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* maximumval(node* root)
{
    node* temp = root;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}

node* deletenode(node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }

    else
    {
        if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = minimumval(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{
    node* rootnode = NULL;
    insertnode(rootnode,4);
    insertnode(rootnode,2);
    insertnode(rootnode,5);
    insertnode(rootnode,1);
    insertnode(rootnode,3);
    insertnode(rootnode,6);

    cout<<endl<<"Inorder Traversal:"<<endl;
    inorder(rootnode);
    cout<<endl<<"Preorder Traversal:"<<endl;
    preorder(rootnode);
    cout<<endl<<"Postorder Traversal:"<<endl;
    postorder(rootnode);
    cout<<endl<<"BFS Traversal:"<<endl;
    bfsTraversal(rootnode);

    //to delete the root node
    deletenode(rootnode,6);
    cout<<endl<<"Inorder Traversal:"<<endl;
    inorder(rootnode);

    deletenode(rootnode,5);
    cout<<endl<<"Inorder Traversal:"<<endl;
    inorder(rootnode);

    deletenode(rootnode,2);
    cout<<endl<<"Inorder Traversal:"<<endl;
    inorder(rootnode);

    // cout<<endl<<"Descending order: "<<endl;
    // //descendinginorder(rootnode);
    // cout <<endl<< "BFS traversal: "<<endl;
    cout << endl;
    searchkey(rootnode,5);
    return 0;
}