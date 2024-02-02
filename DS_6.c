//store n numbers and apply linear search for
#include<stdio.h>
int main()
{
    int a[25],i,x,e;
    printf("Enter size of matrix~ ");
    scanf("%d",&e);
     
    printf("Enter array elements~ \n");
    for(i=0;i<e;++i)
        scanf("%d",&a[i]);
     
    printf("\nEnter element to search~ ");
    scanf("%d",&x);
     
    for(i=0;i<e;++i){
        if(a[i]==x)
        break;
    }
    if(i<e)
        printf("Yes element found at index position %d",i);
    else
        printf("Element not found");
}
