// LINKED LIST IMPLEMENTATION OF STACK

#include <stdio.h>
#include <stdlib.h>
struct node { //node of linked list
	int info;
	struct node* link;
};
struct node* top = NULL;
void traverse() //FUNCTION TO PRINT LINKED LIST
{
	struct node* temp;
	if (top == NULL) //IF LIST IS EMPTY
		printf("\nEMPTY STACK\n");
	else {            //ELSE PRINT LINKED LIST
		temp = top;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->link;
		}
	}
}
void push() //FUNCTOIN TO INSERT AT FIRST POSITION
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("ENTER VALUE IN STACK= ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = top;//POINTER OF TEMP WILL ASSIGN TO START
	top = temp;
}
void pop() //FUNCTION TO DELETE FIRST NODE FROM LIST
{
	struct node* temp;
	if (top == NULL)
		printf("\nEMPTY STACK\n");
	else {
		temp = top;
		top = top->link;
		free(temp);
	}
}
int main() //CODE TO MAKE CHOICE
{
    int n,i;
    printf("PLEASE ENTER NUMBER OF NODES= ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        push();
    }
    int choice;
	while (1) {
        printf("\n\t1 DISPLAY LINKED LIST\n");
		printf("\t2 PUSH ELEMENT\n");
		printf("\t3 POP ELEMENT\n");
		printf("\t4 EXIT\n");
		printf("\nENTER YOUR CHOICE= \n");
		scanf("%d", &choice);
        switch (choice) { //USED SWITCHES FOR EACH CHOICE
		case 1:
			traverse();
			break;
		case 2:
			push();
			traverse();
			break;
		case 3:
			pop();
			traverse();
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("INVALID CHOICE\n");
		}
	}
	return 0;
}


