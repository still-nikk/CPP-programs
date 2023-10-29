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
    if (root == NULL)
    {
        root = newnode;
        cout << root->data << " ";
    }
    node* temp = root;
    if (newnode->data > root->data)
    {
        root->right = insertnode(root->right, val);
    }
    else if (newnode->data < root->data)
    {
        root->left = insertnode(root->left, val);
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

void inorder(node* &root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(node* &root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* &root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void searchkey(node* root, int key)
{
    if (root == NULL)
    {
        cout << "Key element was not found";
        return;
    }

    if (root->data == key)
    {
        cout << "Key element was found";
        return;
    }
    searchkey(root->left, key);
    searchkey(root->right, key);
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
    while (temp->right != NULL)
    {
        temp = temp->right;
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
    int choice;
    int value;

    do {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Search for a key" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. BFS Traversal" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert: ";
                cin >> value;
                rootnode = insertnode(rootnode, value);
                cout << endl;
                break;

            case 2:
                cout << "Enter a value to delete: ";
                cin >> value;
                rootnode = deletenode(rootnode, value);
                cout << "Node with value " << value << " deleted." << endl;
                break;

            case 3:
                cout << "Enter a key to search: ";
                cin >> value;
                searchkey(rootnode, value);
                cout << endl;
                break;

            case 4:
                cout << "Inorder Traversal:" << endl;
                inorder(rootnode);
                cout << endl;
                break;

            case 5:
                cout << "Preorder Traversal:" << endl;
                preorder(rootnode);
                cout << endl;
                break;

            case 6:
                cout << "Postorder Traversal:" << endl;
                postorder(rootnode);
                cout << endl;
                break;

            case 7:
                cout << "BFS Traversal:" << endl;
                bfsTraversal(rootnode);
                cout << endl;
                break;

            case 8:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
