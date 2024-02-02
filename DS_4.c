#include <stdio.h>
#define SIZE 3 
int main()
{
    int A[SIZE][SIZE];
    int r, c, sum = 0;
    printf("Enter elements in matrix of size %dx%d=  \n", SIZE, SIZE);
    for(r=0; r<SIZE; r++)         //input matrix
    {
        for(c=0; c<SIZE; c++)
        {
            scanf("%d", &A[r][c]);
        }
    }
    for(r=0; r<SIZE; r++)  //sum of row
    {
        sum = 0;
        for(c=0; c<SIZE; c++)
        {
            sum = sum+A[r][c];
        }

        printf("Sum of elements of Row %d = %d\n", r+1, sum);
    }
    for(r=0; r<SIZE; r++)   //sum of column
    {
        sum = 0;
        for(c=0; c<SIZE; c++)
        {
            sum = sum+A[c][r];
        }

        printf("Sum of elements of Column %d = %d\n", r+1, sum);
    }

    return 0;
}
