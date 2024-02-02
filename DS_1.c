#include<stdio.h>
#define MAX_SIZE 25
int sum(int arr[], int s, int len);// declaration of function
int main()
{
    int arr[MAX_SIZE];
    int n, i, s;
    printf("Enter size of the array= "); //enter size of array
    scanf("%d", &n);
    printf("Enter elements inside the array= ");
    for(i=0; i<n; i++)                 //enter elements in array
    {
        scanf("%d", &arr[i]);
    }
    s = sum(arr, 0, n);
    printf("Sum of array elements= %d", s);
 
    return 0;
}
int sum(int arr[], int s, int len)// recursive function
{
    if(s >= len)                 //condition
        return 0;
    return (arr[s] + sum(arr, s + 1, len));
}
