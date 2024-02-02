//Implement Circular Linked List and its operations.
#include<stdio.h>  
#include<stdlib.h>  
struct node    //STRUCTURE FOR NODES
{  
    int data;  
    struct node *next;   
};  
struct node *head; //STARTING POINTER
void beginsert()  
{  
    struct node *ptr,*temp;   //TEMP VARABLES
    int item;                //VARIABLE FOR DATA
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)             //CASE FOR INSUFFICIENT MEMORY
    {  
        printf("\nOVERFLOW");  
    }  
    else   
    {  
        printf("\nENTER THE NODE DATA~");  //DATA INSERTION 
        scanf("%d",&item);  
        ptr -> data = item;  
        if(head == NULL)       //CASE FOR EMPTY LL
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;               //CHANGING LINKS
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        printf("\nNODE INSERTED\n");  
    }  
}  
void lastinsert()  
{  
    struct node *ptr,*temp;  //TEMP VARABLES  
    int item;               //VARIABLE FOR DATA
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  //INSUFFICIENT MEMORY 
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nENTER DATA~");  //INSERTION OF DATA
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)         //EMPTY LL
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;            //CHANGING LINKS
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
        printf("\nNODE INSERTED\n");  
    }  
}
void begin_delete()  
{  
    struct node *ptr;    //TEMP VARIABLE 
    if(head == NULL)    //EMPTY CLL
    {  
        printf("\nUNDERFLOW");    
    }  
    else if(head->next == head)  //SINGLE NODE CLL
    {  
        head = NULL;  
        free(head);  
        printf("\nNODE DELETED\n");  
    }  
    else                        //DELTETION OF DATA
    {   ptr = head;   
        while(ptr -> next != head)   //CHANGING LINKS
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        printf("\nNODE DELETED\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr, *preptr;  //TEMP VARIABLE
    if(head==NULL)              //EMPTY CLL
    {  
        printf("\nUNDERFLOW");  
    }  
    else if (head ->next == head)  //DELETE ONLY NODE IN LL
    {  
        head = NULL;  
        free(head);  
        printf("\nNODE DELETED\n");  
    }  
    else                        //DELETEION OF DATA
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;         //CHANGING LINKS
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nNODE DELETED\n");  
    }  
}
void display()              
{  
    struct node *ptr;       //TEMP VARIABLE
    ptr=head;  
    if(head == NULL)        //EMPTY CLL
    {  
        printf("\nUNDERFLOWED");  
    }     
    else  
    {  
        printf("\n PRINTING VALUES.. \n");  
          
        while(ptr -> next != head)      //LOOP TO PRINT DATA OF CLL
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
} 
void main ()  
{  
    int choice =0,n,i; 
    printf("CREATE CIRCULAR LINKED LIST\n");
    printf("ENTER SIZE FOR LINKED LIST");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        lastinsert();
    }
    while(choice != 6)   
    {  
        printf("\nMAIN MENU\n");  
        printf("\nCHOOSE ANY OPTION FROM THE LIST\n");  
        printf("\n1.INSERT AT BEGINNING\n2.INSERT AT LAST\n3.DELETE FROM BEGINNING\n4.DELETE FROM LAST\n5.PRINT\n6.EXIT\n");  
        printf("\nPLEASE ENTER YOUR CHOICE~\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            begin_delete();       
            break;  
            case 4:  
            last_delete();        
            break;  
            case 5:  
            display();        
            break;
            case 6:  
            exit(0);  
            break;  
            default:  
            printf("INVALID CHOICE!!");  
        }  
    }  
}  
