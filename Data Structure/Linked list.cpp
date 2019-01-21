#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

};
void push(struct Node** head_ref, int data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;

}
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
int main()
{
    int n,d,i;
    struct Node* head=NULL;
    printf("How many numbers:");
    scanf("%d",&n);
    printf("Enter numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        push(&head,d);
        printf("%d is inserted.\n",d);
        printList(head);
        printf("\n");
    }
    return 0;
}

