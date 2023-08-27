#include <stdio.h>
#define MaxSize 5
int rear = -1, front = 0;
int queue[MaxSize];

void insert()
{
    if (rear == MaxSize - 1)
    {
        printf("Queue is overflow \n");
    }
    else
    {
        int n;
        printf("Enter the elements: \n");
        scanf("%d", &n);
        rear = rear + 1;
        queue[rear] = n;
    }
}

void delete1()
{
    int n;
    if (front > rear)
    {
        printf("Stack is Empty \n");
    }
    else
    {
        n = queue[front];
        printf("Deleted element is %d \n", n);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front > rear)
    {
        printf("Stack is Empty \n");
    }
    else
    {
        printf("Elements in Queue are \n");
        for (i = rear; i >= front; i--)
        {
            printf("%5d", queue[i]);
        }
    }
}

// For showing in stack using array elements are not deleted permanently only overwritten.
void temp()
{
    for (int i = 0; i < MaxSize; i++)
    {
        printf("%5d", queue[i]);
    }
}

void main()
{
    int choice;
    do
    {
        printf("------------------QUEUE----------------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");

        printf("Enter the choice: ");
        printf("-----------------------------------\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete1();
            break;
        case 3:
            display();
            break;
        case 5:
            temp();
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);
}