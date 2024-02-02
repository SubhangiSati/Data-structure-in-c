//Product of two matrixes using pointers
#include<stdio.h>
void Multiply_m(int matrixA[][20], int rA, int cA, int matrixB[][20], int rB, int cB, int matrixC[][20]) {
    
    //function declaration with parameters
	int i, j, k, sum = 0;

	if (cA != rB) {              //condition for invalid order
		printf("ORDER OF MATRIX IS INVALID AND CANNOT BE MULTIPLIED!!!");
		return;
	}

	for (i = 0; i < rA; ++i) {   //condition for product of matrix
		for (j = 0; j < cB; ++j) {
			sum = 0;
			for (k = 0; k < rA; ++k) {
				sum =sum + *(*(matrixA + i) + k) * *(*(matrixB + k) + j);
			}
			*(*(matrixC + i) + j) = sum;
		}
	}

}

int main() {

	int i, j;                                           //initalise variables
	int rA, cA, rB, cB;
	int matrixA[20][20], matrixB[20][20], matrixC[20][20];
	
	printf("Enter Number of Rows in Matrix A =   ");   //Input rows in Matrix A 
	scanf("%d", &rA);
	printf("Enter Number of columns in Matrix A =   ");//Input columns in Matrix A
	scanf("%d", &cA);
    printf("Enter MatrixA= \n");                    //Enter elements in Matrix A 
	for (i = 0; i < rA; ++i) {
		for (j = 0; j < cA; ++j) {
			scanf("%d", &matrixA[i][j]);
		}
	}
	
	printf("Enter Number of Rows in Matrix B =   ");   //Input row in Matrix B
	scanf("%d", &rB);
	printf("Enter Number of columns in Matrix B =   ");//Input column in Matrix B
	scanf("%d", &cB);
    printf("Enter Matrix B =   \n");                //Enter elements in Matrix B 
	for (i = 0; i < rB; ++i) {
		for (j = 0; j < cB; ++j) {
			scanf("%d", &matrixB[i][j]);
		}
	}
	
	Multiply_m(matrixA, rA, cA, matrixB, rB, cB, matrixC);
	printf("\nThe product of Matrix A and Matrix B = \n");
	for (i = 0; i < rA; ++i) {              //printing Matrix C (Resultant matrix)
		for (j = 0; j < cB; ++j) {
			printf("%d ", matrixC[i][j]);
		}
		printf("\n");
	}

}