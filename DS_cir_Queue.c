//CIRCULAR QUEUE
#include <stdio.h> //CIRCULAR QUEUE USING ARRAY 
# define max 6  
int queue[max];  // array declaration  
int front=-1;  
int rear=-1;  
// function to insert an element in a circular queue  
void insertq(int element)  
{  
    if(front==-1 && rear==-1)   // condition to check queue is empty  
    {  
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }  
    else if((rear+1)%max==front)  // condition to check queue is full  
    {  
        printf("QUEUE OVERFLOWED..");  
    }  
    else  
    {  
        rear=(rear+1)%max;       // rear is incremented  
        queue[rear]=element;     // assigning a value to the queue at the rear position.  
    }  
}  
  
// function to delete the element from the queue  
int delq()  
{  
    if((front==-1) && (rear==-1))  // condition to check queue is empty  
    {  
        printf("\nQUEUE UNDERFLOW..");  
    }  
 else if(front==rear)  
{  
   printf("\nTHE DELETED ELEMENT IS= %d", queue[front]);  
   front=-1;  
   rear=-1;  
}   
else  
{  
    printf("\nTHE DELETED ELEMENT IS= %d", queue[front]);  
   front=(front+1)%max;  
}  
}  
// function to display the elements of a queue  
void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\n EMPTY QUEUE..");  
    }  
    else  
    {  
        printf("\nELEMENT IN QUEUE= ");  
        while(i!=rear)  
        {  
            printf("%d,", queue[i]);  
            i=(i+1)%max;  
        }  
    }  
}
int main()  
{  
    int choice=1,x;   // variables declaration  
    while(choice<4 && choice!=0)   // while loop  
    {  
    printf("\nPRESS 1: INSERT AN ELEMENT");  
    printf("\nPRESS 2: DELETE AN ELEMENT");  
    printf("\nPRESS 3: DISPLAY QUEUE");  
    printf("\nPLEASE ENTER YOUR CHOICE= ");  
    scanf("%d", &choice);  
    switch(choice)  
    {  
        case 1:  
        printf("ENTER ELEMENT TO INSERT= ");  
        scanf("%d", &x);  
        insertq(x);  
        break;  
        case 2:  
        delq();  
        break;  
        case 3:  
        display();  
  
    }
    }
    return 0;  
}  

