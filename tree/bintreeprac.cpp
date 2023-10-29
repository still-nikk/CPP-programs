#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int val):data(val),left{NULL}, right(NULL) {}
};

node* buildtree(node* root)
{

    cout << "Enter data: ";
    int data;
    cin >> data;
    cout << endl;
    root = new node(data);

    if(data == -1)
    {
        return NULL; 
    }

    cout <<"Enter data to insert on left of "<< root->data <<", ";
    root -> left = buildtree(root-> left);
    cout <<"Enter data to insert on right of "<< root->data <<", ";
    root -> right = buildtree(root-> right);
    return root;
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

// void bfs(node* root)
// {
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()) {
//         node* temp = q.front();
//         q.pop();

//         if(temp == NULL) { 
//             //purana level complete traverse ho chuka hai
//             cout << endl;
//             if(!q.empty()) { 
//                 //queue still has some child nodes
//                 q.push(NULL);
//             }  
//         }
//         else{
//             cout << temp -> data << " ";
//             if(temp ->left) {
//                 q.push(temp ->left);
//             }

//             if(temp ->right) {
//                 q.push(temp ->right);
//             }
//         }
//     }
// }



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

int main()
{
    node* root = NULL;
    //prompt to create 1 3 5 7 9 11 13 tree is: 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1 
    root = buildtree(root);
    cout <<"BFS traversal: ";
    bfs(root);
    cout << endl;
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout<<"preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout<<"postorder Traversal: ";
    postorder(root);
    return 0;
}