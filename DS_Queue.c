//LL IMPLEMENTATION OF QUEUE 
#include <stdio.h> //insertion and deletion in queue
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
		printf("\nEXISTING QUEUE\n");
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
void insert() //FUNCTION TO INSERT AT END OF LINKED LIST
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
void delete() //FUNCTION TO DELETE FIRST NODE FROM LIST
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
int main() //CODE TO MAKE CHOICE
{
	int choice;
	createList();
	while (1) {

		printf("\n\t1 DISPLAY LINKED LIST\n");
		printf("\t2 INSERT ELEMENT IN STACK\n");
		printf("\t3 DELETE ELEMENT FROM STACK\n");
	    printf("\t4 EXIT CODE\n");
		printf("\nENTER YOUR CHOICE= \n");
		scanf("%d", &choice);

		switch (choice) { //USED SWITCHES FOR EACH CHOICE
		case 1:
			traverse();
			break;
		case 2:
			insert();
			traverse();
			break;
	    case 3:
			delete();
			traverse();
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}


