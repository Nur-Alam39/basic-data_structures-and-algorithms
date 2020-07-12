#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* Insert(struct Node *root, int data)
{
    if(root == NULL)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
    }
    if(data < root->data)
        root->left = Insert(root->left, data);
    else if(data > root->data)
        root->right = Insert(root->right, data);
    return root;
}

void printLevelOrder(Node *root)
{
    if(root == NULL) return;

    queue<Node *> q;

    q.push(root);

    while(!q.empty())
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
}

int main()
{
    Node* root = NULL;
    root = Insert(root, 1);
    Insert(root, 2);
    Insert(root, 6);
    Insert(root, 4);
    Insert(root, 5);

    printLevelOrder(root);

    return 0;
}
