// Reverse a string using stack.
#include<stdio.h>
#include<string.h>
#define size 20
int top = -1;
char stack[size];
char push(char ch)
{
 if(top==(size-1))
  printf("STACK OVERFLOW\n");
 else
  stack[++top]=ch;
}
char pop()
{
 if(top==-1)
  printf("STACK UNDERFLOW\n");
 else
  return stack[top--];
}
int main()
{
 char str[20];
 int i;
 printf("ENTER A STRING=  \n" );
 gets(str);
 for(i=0;i<strlen(str);i++)
  {
   push(str[i]);
  }
 for(i=0;i<strlen(str);i++)
  {
      str[i]=pop(); 
  }
 printf("REVERSED STRING IS=  ");
 puts(str);

}
