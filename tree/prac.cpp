#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val):data(val),left(NULL),right(NULL) {}
};

node* insertintobst(node* root , int val)
{
    if(root == NULL)
    {
        root = new node(val);
        return root;
    }
    // node* newnode = new node(val);
    if(val < root -> data)
    {
        root -> left = insertintobst(root -> left , val);
    }
    if(val > root -> data)
    {
        root -> right = insertintobst(root -> right , val);
    }
    return root;
}

void takedata(node* &root)
{
    cout << "Enter values: ";
    int val;
    cin >> val;
    while(val != -1)
    {
        root = insertintobst(root,val);
        cin >> val;
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}

void bfs(node* root) 
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        if(temp -> left != NULL)
        {
            q.push(temp -> left);
        }
        if(temp -> right != NULL)
        {
            q.push(temp -> right);
        }
        cout << q.front() -> data << " ";
        q.pop();
    }
}

bool searchinbst(node* root,int key)
{
    if(root == NULL)
    {
        return 0;
    }
    if(key>root->data)
    {
        return searchinbst(root->right,key);
    }
    if(key < root -> data)
    {
        return searchinbst(root -> left , key);
    }
    if(root -> data == key)
    {
        return 1;
    }
}

node* minvalue(node* root)
{
    node* temp = root;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

node* maxvalue(node* root)
{
    node* temp = root;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}

node* deletenode(node* root,int val)
{
    if(root == NULL)
    {
        return root;
    }

    if(root -> data == val)
    {
        //case 1: 0 child nodes
        if(root -> left == NULL && root -> right == NULL)
        {
            node* temp = root;
            root = NULL;
            free(temp);
            return root;
        }

        //case 2: 1 child node 
        //case 2(a) : only left child
        else if(root -> left != NULL && root -> right == NULL)
        {
            node* temp = root -> left;
            free(root);
            root = temp;
            return root;
        }
        //case 2(b) : only right child
        else if(root -> left == NULL && root -> right != NULL)
        {
            node* temp = root -> right;
            free(root);
            root = temp;
            return root;
        }

        //case 3: 2 child nodes
        else if(root -> left != NULL && root -> right != NULL)
        {
            int min = minvalue(root -> right) -> data;
            root -> data = min;
            root -> right = deletenode(root -> right, min);
            return root;
        }
    }

    else if(val > root -> data)
    {
        root -> right = deletenode(root -> right, val);
        return root;
    }
    else if(val < root -> data)
    {
        root -> left = deletenode(root -> left, val);
        return root;
    }
}

int main()
{
    node* root = NULL;
    cout << "Enter data to insert into BST- ";
    cout << endl;
    takedata(root);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    cout<<"preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout<<"postorder Traversal: ";
    postorder(root);
    cout << endl;
    cout << "BFS traversal: ";
    bfs(root);
    cout << endl;
    cout << "Enter the element you want to search for: ";
    int key;
    cin >> key;
    if(searchinbst(root,key))
    {
        cout << "Element found." << endl;
    }
    else{
        cout << "Element not found." << endl;
    }

    int min = minvalue(root) -> data;
    int max = maxvalue(root) -> data;

    cout << "Minimum value in the BST: " << min << endl;
    cout << "Maximum value in the BST: " << max << endl;

    deletenode(root,56);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}