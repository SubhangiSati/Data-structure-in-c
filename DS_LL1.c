//INSERTION AND DELETION IN A SINGLE LINKED LIST
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
void insertAtFront() //FUNCTOIN TO INSERT AT FIRST POSITION
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("ENTER NUMBER TO INSERT= ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = start;//POINTER OF TEMP WILL ASSIGN TO START
	start = temp;
}
void insertAtEnd() //FUNCTION TO INSERT AT END OF LINKED LIST
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));
	printf("ENTER NUMBER TO INSERT= ");
	scanf("%d", &data);
	temp->link = 0; //CHANGING LINKS
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}
void insertAtPosition()//FUNCTON TO INSERT NODE AT ANY POSITION IN LIST
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));
    printf("\nENTER POSITION FOR NEW NODE=");
	scanf("%d %d", &pos, &data);
	temp = start; //CHANGING LINKS 
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
void deleteFirst() //FUNCTION TO DELETE FIRST NODE FROM LIST
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
}
void deleteEnd()//FUNCTION TO DELETE LAST NODE FROM LIST
{
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\nList is Empty\n");
	else {
		temp = start;
		while (temp->link != 0) {
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}
void deletePosition() //FUNCTION TO DELETE ANY NODE FROM GIVEN POSITION 
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL) //IF LIST IS EMPTY
		printf("\nEMPTY LIST!\n");
	else {
		printf("\nENTER INDEX NUMBER=  ");
		scanf("%d", &pos); //POSITION WANT TO DELETE
		position = malloc(sizeof(struct node));
		temp = start;
		while (i < pos - 1) { //TRANSFERSE TILL POSITION
			temp = temp->link;
			i++;
		}
		position = temp->link; //CHANGE LINKS
		temp->link = position->link;
		free(position); //FREE MEMORY
	}
}
int main() //CODE TO MAKE CHOICE
{
	int choice;
	createList();
	while (1) {

		printf("\n\t1 DISPLAY LINKED LIST\n");
		printf("\t2 INSERT ELEMENT AT FIRST POSITION\n");
		printf("\t3 INSERT ELEMENT AT THE END\n");
		printf("\t4 INSERT ELEMENT AT ANY POSITOIN \n");
		printf("\t5 DELETE FIRST ELEMENT\n");
		printf("\t6 DELETE LAST ELEMENT\n");
		printf("\t7 DELETE ELEMENT FROM ANY POSITION\n");
		printf("\nENTER YOUR CHOICE= \n");
		scanf("%d", &choice);

		switch (choice) { //USED SWITCHES FOR EACH CHOICE
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			traverse();
			break;
		case 3:
			insertAtEnd();
			traverse();
			break;
		case 4:
			insertAtPosition();
			traverse();
			break;
		case 5:
			deleteFirst();
			traverse();
			break;
		case 6:
			deleteEnd();
			traverse();
			break;
		case 7:
			deletePosition();
			traverse();
			break;
		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}