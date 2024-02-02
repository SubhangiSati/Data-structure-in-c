// Using array and functions implement Stack and its operations like insert, delete, and display
#include<stdio.h>
#define max 30
int stack[max],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top=-1;
    printf("\nENTER SIZE OF ARRAY= ");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n PLEASE ENTER YOUR CHOICE= ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t PLEASE ENTER VALID CHOICE (1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\t EMPTY OVERFLOW ");
        
    }
    else
    {
        printf(" ENTER ELEMENT TO PUSH= ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t EMPTY STACK");
    }
    else
    {
        printf("\n\t THE POPPED ELEMENT IS %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n ENTER ELEMENT IN STACKS= \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n PLEASE ENTER CHOICE");
    }
    else
    {
        printf("\n THE STACK IS EMPTY");
    }
   
}

