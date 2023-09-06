#include <stdio.h>
#include <stdlib.h> // Include this header for malloc

struct node
{
    int data;
    struct node *add;
};
struct node *start = NULL, *temp, *new1, *prev, *next, *arr[500];

void create()
{
    int n;
    char choice;
    printf("Enter the first element:");
    scanf("%d", &n);
    start = (struct node *)(malloc(sizeof(struct node)));
    start->data = n;
    start->add = NULL;
    temp = start;
    printf("\n Want to continue? (Y/N): ");
    scanf(" %c", &choice);
    while (choice == 'Y' || choice == 'y')
    {
        printf("\nEnter the next element: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1->data = n;
        new1->add = NULL;
        temp->add = new1;
        temp = temp->add;
        printf("\nWant to continue? (Y/N): ");
        scanf(" %c", &choice);
    }
}

void display()
{
    if (start == NULL)
    {
        printf("List not found.\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("\t %d", temp->data);
            temp = temp->add;
        }
    }
}

void insert_first()
{
    int n;
    if (start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        printf("Enter elements to insert at first position: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1->data = n;
        new1->add = NULL;
        new1->add = start;
        start = new1;
    }
}

void insert_last()
{
    int n;
    if (start == NULL)
    {
        printf("List not Found\n");
    }
    else
    {
        printf("Enter element to insert at last position: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1->data = n;
        new1->add = NULL;
        temp = start;
        while (temp->add != NULL)
        {
            temp = temp->add;
        }
        temp->add = new1;
    }
}

void insert_middle()
{
    int n, position, i = 0;
    if (start == NULL)
    {
        printf("List not Found\n");
    }
    else
    {
        printf("\nEnter the element to insert in middle position: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1->data = n;
        new1->add = NULL;
        printf("Enter the position to insert: ");
        scanf("%d", &position);
        next = start;
        while (i < position)
        {
            prev = next;
            next = next->add;
            i++;
        }
        prev->add = new1;
        new1->add = next;
    }
}

void delete_first()
{
    if (start == NULL)
    {
        printf("List not found.\n");
    }
    else
    {
        temp = start;
        start = start->add;
        printf("Deleted node is %d: ", temp->data);
        free(temp);
    }
}

void delete_last()
{
    if (start == NULL)
    {
        printf("List not found.\n");
    }
    else
    {
        temp = start;
        while (temp->add != NULL)
        {
            prev = temp;
            temp = temp->add;
        }
        prev->add = NULL;
        printf("Deleted node is %d ", temp->data);
        free(temp);
    }
}

void delete_middle()
{
    int position = 1, i = 1;
    if (start == NULL)
    {
        printf("List not found.\n");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &position);
        temp = start;
        while (i < position)
        {
            prev = temp;
            temp = temp->add;
            i++;
        }
        next = temp->add;
        prev->add = next;
        printf("Deleted node is %d ", temp->data);
        free(temp);
    }
}

void search()
{
    int s, flag = 0;
    if (start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        printf("Enter an element to search\n");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                flag = 1;
                break;
            }
            temp = temp->add;
        }
        if (flag == 1)
        {
            printf("Searching Sucess\n");
        }
        else
        {
            printf("Searching Failed\n");
        }
    }
}

void length_linkedList()
{
    int count = 0;
    temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->add;
    }
    printf("Total nodes in linked list are %d", count);
}

void sorting()
{
    int temp1;
    if (start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        prev = start;
        while (prev != NULL)
        {
            next = prev->add;
            while (next != NULL)
            {
                if (next->data < prev->data)
                {
                    temp1 = prev->data;
                    prev->data = next->data;
                    next->data = temp1;
                }
                next = next->add;
            }
            prev = prev->add;
        }
    }
}

void reverse()
{
    int i;
    if (start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        i=0;
        temp = start;
        while (temp != NULL)
        {
            arr[i]=temp;
            i++;
            temp=temp->add;
        }
        i--;
        while(i>=0)
        {
            printf("%5d", arr[i]->data);
            i--;
        }
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n------------------Singly Linked List----------------------------\n");
        printf("1. Create\n2. Display\n3. Insert at First\n4. Insert at Last\n5. Insert in Middle\n6. Delete from First\n7. Delete from Last\n8. Delete from Middle\n9. Searching\n10. Length of Linked List\n11. Sorting\n 12.Reverse\n13. Exit\n");
        printf("\n----------------------------------------------------------");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_first();
            break;
        case 4:
            insert_last();
            break;
        case 5:
            insert_middle();
            break;
        case 6:
            delete_first();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            delete_middle();
            break;
        case 9:
            search();
            break;
        case 10:
            length_linkedList();
            break;
        case 11:
            sorting();
            break;
        case 12:
            reverse();
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 13);
}