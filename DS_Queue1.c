#include<stdio.h>
#include<stdlib.h>
# define N 20 //defining the size of queue
int s[N],top=-1;
int pop()
{
	return s[top--];
}
void push(int x)
{
	if(top == N-1)
		printf("STACK IS FULL");
	else
	{
		top++;
		s[top] = x;	
	}
}
void enqueue(int x)//function to insert element in the queue using recursive stack call
{
	push(x);
}
void print()//function to print elements of a queue
{
	int i;
	for(i=0;i<=top;i++)
		printf("\n%d",s[i]);
}

int dequeue()//function to dequeue element from a queue using recursive stack call
{	
	int data,res;
	if(top == -1)
		printf("QUEUE IS EMPTY");
	else if(top == 0)
		return pop();
	data = pop();
	res = dequeue();
	push(data);
	return res;
 	
}
int main()
{
	int choice,n,i,data,t;
	printf("ENTER YOUR CHOICE:- ");
	
	do{
		printf("\n\n1 TO INSERT DATA IN QUEUE\n2 TO SHOW DATA IN QUEUE \n3 TO DELETE DATA FROM QUEUE\n0 TO EXIT\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nENTER THE NUMBER OF ELEMENTS:- ");
				scanf("%d",&n);
				printf("\nENTER THE DATA:- \n");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				t = dequeue();
				printf("DEQUEUED ELEMENT:- %d",t);
				
				break;
			case 0:
				break;
			default:
				printf("\nINVALID CHOICE!!!!");
			
		}
	}while(choice!=0);
	
}


