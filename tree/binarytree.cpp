#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* Left;
    node* Right;

    node(int val)
    {
        data = val;
        Left = NULL;
        Right = NULL;
    } 
};

void inorder(node* rootnode)
{
    if(rootnode == NULL)
    {
        return;
    }

    cout << rootnode -> data;
    inorder(rootnode -> Left);
    inorder(rootnode -> Right);
}

void preorder(node* rootnode)
{
    if(rootnode == NULL)
    {
        return;
    }

    preorder(rootnode -> Left);
    cout << rootnode -> data;
    preorder(rootnode -> Right);
}

void postorder(node* rootnode)
{
    if(rootnode == NULL)
    {
        return;
    }

    postorder(rootnode -> Left);
    postorder(rootnode -> Right);
    cout << rootnode -> data;
}

void bfs(node* rootnode)
{
    if(rootnode == NULL)
    {
        return;
    }

    bfs(rootnode -> Left);
    cout << rootnode -> data;
}



int main()
{
    node* rootnode = new node(1);
    rootnode -> Left = new node(2);
    rootnode -> Right = new node(3);
    rootnode -> Left -> Left = new node(4);
    rootnode -> Left -> Right = new node(5);
    rootnode -> Right -> Left = new node(6);
    rootnode -> Right -> Right = new node(7);
    inorder(rootnode);
    cout << endl;
    preorder(rootnode);
    cout << endl;
    postorder(rootnode);
    cout << endl;
    return 0;
}