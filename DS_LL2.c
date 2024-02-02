//DOUBLY LINKED LIST
//OPERATIONS IN DOUBLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node { //NODE STRUCTURE OF LINKED LIST
    int data;
    struct node *prev, *next;
};
struct node* start = NULL;
void traverse(){ //FUNCTION TO PRINT DOUBLY LINKED LIST
    if (start == NULL) { //IF LIST IS EMPTY
        printf("\nEMPTY LIST\n");
        return;
    }
    struct node* temp; //PRINTS DATA OF NODE
    temp = start;
    while (temp != NULL) {
        printf("DATA=  %d\n", temp->data);
        temp = temp->next;
    }
}
void insertAtFront(){ //FUNCTION TO INSERT AT FRONT 
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nENTER NUMBER TO BE INSERTED=  ");
    scanf("%d", &data);
    temp->data = data;
    temp->prev = NULL;
    temp->next = start;//POINTER OF TEMP WILL BE ASSIGNED TO START
    start = temp;
}
void insertAtEnd(){ //FUNCTION TO INSERT AT THE END
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nENTER NUMBER TO BE INSERTED= ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    trav = start;
    if (start == NULL) { //IF START IS NULL
        start = temp;
    }
    else {               //CHANGES LINK
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}
void insertAtPosition(){ //FUNCTION TO INSERT AT GIVEN POSITION
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nENTER POSITION=  "); //ENTER POSITION AND DATA
    scanf("%d", &pos);
    printf("\nENTER THE NUMBER=  ");
    scanf("%d", &data);
    newnode->data = data;
    temp = start;
    if (start == NULL) { //IF START IS NULL
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else if (pos == 1) { //IF POSITION IS 1
        newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
    }
    else {             //CHANGE LINKS
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}
void deleteFirst(){  //FUNCTION TO DELETE FROM FRONT
    struct node* temp;
    if (start == NULL)
        printf("\nEMPTY LIST\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}
void deleteEnd(){ //FUNCTION TO DELETE FROM END
    struct node* temp;
    if (start == NULL)
        printf("\nEMPTY LIST\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
}
void deletePosition(){ //FUNCTION TO DELETE FROM GIVEN POSITION
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;
    if (start == NULL) //IF DLL IS EMPTY
        printf("\nEMPTY LIST\n");
    else {
        printf("\nENTER POSITION=  "); //POSITION 
        scanf("%d", &pos);
        if (pos == 1) { //IF POSITION IS FIRST NODE
            position = start;
            start = start->next;
            if (start != NULL) {
                start->prev = NULL;
            }
            free(position);
            return;
        }
        while (i < pos - 1) { //TRAVERSE TILL POSITION
            temp = temp->next;
            i++;
        }
        position = temp->next; //CHANGE LINKS
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;
        free(position);  //FREE MEMORY
    }
}
int main(){
    int x,y;
    printf("ENTER THE SIZE OF DOUBLY LINKED LIST= ");
    scanf("%d",&y);
    for(x=0;x<y;x++){
       insertAtEnd();
    }
    int choice;
    while (1) {
 
        printf("\n\t1- TO PRINT DOUBLY LINKED LIST\n");
        printf("\t2- TO INSERT AT FRONT\n");
        printf("\t3- TO INSERT AT END\n");
        printf("\t4- TO INSERT AT ANY POSITION\n");
        printf("\t5- TO DELETE FIRST ELEMENT\n");
        printf("\t6- TO DELETE FROM END\n");
        printf("\t7- TO DELETE FROM ANY POSITION\n");
        printf("\t8- TO EXIT\n");
        printf("\nENTER YOUR CHOICE= \n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
 
        case 8:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE !! PLEASE TRY AGAIN \n");
            continue;
        }
    }
    return 0;
}
