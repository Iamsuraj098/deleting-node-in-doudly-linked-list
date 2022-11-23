#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int data;
    struct nodetype* next;
    struct nodetype* pre;
}node;
node*head = NULL;
node*tail = NULL;
void insertion(int element)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = element;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->pre = NULL;
        head = temp;
        tail = temp;
        return;
    }
    temp->next = NULL;
    temp->pre = tail;
    tail->next = temp;
    tail = temp;
}
void delet(int position)
{
    node* temp = head;
    if (head == NULL)
    {
        return;
    }
    node* temp1 = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
        if (i>1)
        {
            temp1 = temp1->next;
        }
    }
    printf("\t\t%d \n", temp->data);
    if (temp == head)
    {
        head = head->next;
        free(temp);
        return;
    }
    temp1->next = temp->next;
    free(temp);
}
void print()
{
    node* temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n, x;
    printf("enter the number of element: ");
    scanf("%d", &n);
    printf("Enter the element: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertion(x);
    }
    print();
    int position;
    printf("Enter the position of deleting node: ");
    scanf("%d", &position);
    delet(position);
    print();
return 0;
}