#include <stdio.h>
int main()
{
    int a[10];
    int n,i,x,size;
    printf("Size of array is=\n"); //size of array
    scanf("%d",&size);
    printf("Enter %d array elements=\n",size);
    for(i=0;i<size;i++)           //entering elements inside array
    {
        scanf("%d",&a[i]);
    }
    printf("Current array= ");   //printing array
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nEnter an element to insert=\n"); //element to insert
    scanf("%d",&n);
    printf("Enter position for element %d=\n",n); //position of new element
    scanf("%d",&x);
    x=x-1;
    for(i=size-1;i>=x;i--)
    {
        a[i+1]=a[i];
    }
    a[x]=n;
    printf("\nNew array= ");
    for(i=0;i<size+1;i++)           //printing new array
    {
        printf("%d ",a[i]);
    }
    return 0;
}

