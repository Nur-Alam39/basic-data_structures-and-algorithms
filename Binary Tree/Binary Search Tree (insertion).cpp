#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
};

void printInorder(Node *root)
{
    if(root != NULL)
    {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* Insert(struct Node *root, int data)
{
    if(root == NULL)
    {
        return root = newNode(data);
    }
    if(data < root->data)
    {
        root->left = Insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    int tc, a;
    root = Insert(root, 50);
    root = Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);

    printInorder(root);

    return 0;
}
