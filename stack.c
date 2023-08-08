#include <stdio.h>
#define MAXSIZE 5
int top = -1, stack[MAXSIZE];

void push()
{
    int n;
    if (top == MAXSIZE - 1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        printf("Enter the elements: \n");
        scanf("%d", &n);
        top = top + 1;
        stack[top] = n;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Elements in stack are: \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void pop()
{
    int n;
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        n = stack[top];
        top = top - 1;
        printf("Poped element is %d ", n);
    }
}


// For showing in stack using array elements are not deleted permanently only overwritten.
void temp()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        printf("%d", stack[i]);
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n----------------STACK------------------------\n");
        printf("1.PUSH\n2.POP \n3.DISPLAY\n4.EXIT\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        printf("____________________________________________________________________\n");
        printf("\n");
        printf("\n");
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 5:
        temp();break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);
}
