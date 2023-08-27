#include <stdio.h>
#define Maxsize 5
int front = -1, rear = -1, cqueue[Maxsize];

void insert()
{
    if ((rear + 1) % Maxsize == front)
    {
        printf("Queue is overflow\n");
    }
    else
    {
        int n;
        printf("Enter the elements: ");
        scanf("%d", &n);
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = ((rear + 1) % Maxsize);
        }
        cqueue[rear] = n;
    }
}

void delete1()
{
    int n;
    if (front == -1 && rear == -1)
    {
        printf(" Queue is empty");
    }
    else
    {
        n = cqueue[front];
        if (front == rear)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = (front + 1) % Maxsize;
        }
        printf("Deleted element is %d ", n);
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf(" Queue is empty");
    }
    else
    {
        printf("Elements in queue are: \n");
        for (i = front; i != rear; i = ((i + 1) % Maxsize))
        {
            printf("%5d", cqueue[i]);
        }
        printf("%5d", cqueue[i]);
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n------------------Circular QUEUE----------------------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);
        printf("\n-----------------------------------\n");
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
        // case 5:
        //     temp();
        //     break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);
}