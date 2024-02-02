//SORTING OF LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node { //node of linked list
	int info;
	struct node* link;
};
struct node* start = NULL;
void createList() //function to crete linked list with n nodes
{
	if (start == NULL) {
		int n;
		printf("\nENTER NUMBER OF NODES=  "); //number of nodes
		scanf("%d", &n);
		if (n != 0) {
			int data;
			struct node* newnode;
			struct node* temp;
			newnode = malloc(sizeof(struct node)); 
			start = newnode;
			temp = start;
			printf("\nENTER NUMBER TO LINKED LIST= ");
			scanf("%d", &data);
			start->info = data;
            for (int i = 2; i <= n; i++) {
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("ENTER NUMBER TO LINKED LIST= ");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nCREATED LINKED LIST\n");
	}
	else
		printf("\nLIST ALREADY CREATED\n");
}
void traverse() //FUNCTION TO PRINT LINKED LIST
{
	struct node* temp;
	if (start == NULL) //IF LIST IS EMPTY
		printf("\nEMPTY LIST\n");
	else {            //ELSE PRINT LINKED LIST
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->link;
		}
	}
}
void sort(){
    printf("WELCOME TO SORT");
    struct node *i,*j,*temp;
    int temp1;
    for(i=start;i->link!=NULL;i=i->link){
        for(j=i->link;j!=NULL;j=j->link){
            if(i->info>j->info){
                temp1=i->info;
                i->info=j->info;
                j->info=temp1;
            }
        }
    }
}
int main(){
    int choice;
    while (1){
        printf("\nMAIN MENU\n");  
        printf("\nCHOOSE ANY OPTION FROM THE LIST\n");  
        printf("\n1.DISPLAY\n2.CREATE LL\n3.SORT\n4.EXIT\n");  
        printf("\nPLEASE ENTER YOUR CHOICE~\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            traverse();      
            break;  
            case 2:  
            createList();         
            break;  
            case 3: 
            sort(); 
            traverse();
            break; 
            case 4:  
            exit(0);  
            break;  
            default:  
            printf("INVALID CHOICE!!");
            break;
        }
    }
    
}


