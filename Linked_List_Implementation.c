#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *newNode(node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value of node to be inserted : \n");
    scanf("%d", &temp->data);
    temp->next = NULL;
    node *femp = head;
    if (femp == NULL)
        return temp;
    while (femp->next != NULL)
    {
        femp = femp->next;
    }
    femp->next = temp;
    return head;
}
node *reverseList(node *head)
{
    node *temp = head;
    if (temp == NULL)
        return temp;
    if (temp->next == NULL)
        return temp;
    node *femp = NULL;
    while (temp != NULL)
    {
        node *ctemp = temp;
        temp = temp->next;
        ctemp->next = femp;
        femp = ctemp;
    }
    return femp;
}
int countOfNodes(node *head)
{
    int ct = 0;
    node *temp = head;
    while (temp != NULL)
    {
        ct++;
        temp = temp->next;
    }
    return ct;
}

// Bubble sort
void sortList(node *head)
{
    node *temp1, *temp2;
    int cval;
    temp1 = head;
    while (temp1->next != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                cval = temp1->data;
                temp1->data = temp2->data;
                temp2->data = cval;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int checkSorted(node *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    node *femp = head;
    while (femp->next != NULL)
    {
        if (femp->data > femp->next->data)
        {
            return 0;
        }
        femp = femp->next;
    }
    return 1;
}

void removeDuplicates(node *head)
{
    if (!checkSorted(head))
        sortList(head);
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->val == temp->next->val)
        {
            node *femp = temp->next->next;
            free(temp->next);
            temp->next = femp;
        }
        else
        {
            temp = temp->next;
        }
    }
}

int getMid(node *head)
{

    // if no mid exists return -1 (when head is NULL)

    if (head == NULL)
        return -1;

    // in  case of even elements it returns the first element
    // for example in case of 1 2 3 4, getMid() returns 3

    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
void display(node *head)
{
    node *temp = head;
    printf("The items of the list are : \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *head1 = NULL;
    int n;
    printf("Enter the number of items you want to insert in the list.\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = newNode(head);
    }
    display(head);
    head = reverseList(head);
    printf("After reversing the list we have : \n");
    display(head);

    sortList(head);
    printf("After sorting the list we have : \n");
    display(head);

    printf("The middle element of the list is %d\n", getMid(head));

    return 0;
}
