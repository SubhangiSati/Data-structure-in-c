#include <stdlib.h> //palindrome string using stack
#include <stdio.h>
#include <string.h>
#define MAX 25
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
void main()
{
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("1-ENTER STRING\n2-EXIT\n");
        printf("ENTER YOUR CHOICE~ \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE STRING~ \n");
            scanf("%s", s);
            for (i = 0;s[i]!='\0';i++)
            {
                b=s[i];
                push(b);
            }
            for (i = 0;i<(strlen(s)/2);i++)
            {
                if (stack[top]==stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("%s IS NOT PALINDROME\n", s);
                    break; 
                }
            }
            if((strlen(s)/2)==front)
                printf("%s IS PALINDROME\n",  s);
            front=0;
            top=-1;
            break;
        case 2:
            exit(0);
        default:
            printf("INVALID CHOICE!!!\n");
        }
    }
}
void push(char a)
{
    top++;
    stack[top]=a;
}
void pop()
{
    top--;
}