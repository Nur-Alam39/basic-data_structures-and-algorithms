#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left = NULL, *right = NULL;

};
void insertNode(int data, int root)
{
    if(root == -1)
    {
        struct Node *newNode = (struct node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        if()

    }
}
int findHeight(struct node *root)
{
    if(root == NULL)
        return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight)+1;
}
int main()
{
/// insertNode(data, root);
    insertNode(1, -1);
    insertNode(2, 1);
    insertNode(3, 1);
    insertNode(4, 2);
    insertNode(5, 2);
    insertNode(6, 3);
    insertNode(7, 3);
    insertNode(8, 5);
    insertNode(9, 5);
    return 0;
}

