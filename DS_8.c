//Design a structure ‘subject’ to store the details of the subject like subject name and subject code. Using structure pointer allocate memory for the structure dynamically so as to obtain details of ‘n’ subjects using for loop.
#include <stdio.h>
#include <stdlib.h>
struct course 
{                           //structure declaration 
  int code;                  //structure variables
  char subject[25];
};

int main() {
  struct course *ptr;     //structure object
  int ns;
  printf("NUMBER OF SUBJECTS: ");
  scanf("%d", &ns);

  //memory allocation for number of subjects

  ptr = (struct course *)malloc(ns * sizeof(struct course));
  for (int i = 0; i < ns; ++i) { 
    printf("ENTER SUBJECT AND SUBJECT CODE:\n");
    scanf("%s %d", (ptr + i)->subject, &(ptr + i)->code); 
  }

  printf("SUBJECT SUBJECT CODE\n");
  for (int i = 0; i < ns; ++i) {
    printf("%s\t%d\n", (ptr + i)->subject, (ptr + i)->code);
  }

  free(ptr);

  return 0;
}