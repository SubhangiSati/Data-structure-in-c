// Design a union ‘product’ to store the details of the product purchased like product name, price per unit, number of quantities purchased, and amount spent. Get the name, price per unit, and number of quantities of the product purchased. Calculate the amount spent on the product and then display all the details of the procured product.
#include <stdio.h>
union product {         //union declaration
	int qunt;
	char name[20];      //union variable
	float price;
};
int main()
{
	union product t;      //union member
	int i,n,b;
	float o,a;
    static float total;
	char na[20];
	printf("ENTER NUMBER OF TYPES OF PRODUCT YOU PURCHASED: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){     //loop for entering multiple product
	    printf("ENTER NAME OF PRODUCT %d: ",i+1);
	    scanf("%s",&t.name[20]);  //input name of product
  	    na[20]=t.name[20];  
	    printf("Enter the price of the product: ");
	    scanf("%f",&t.price);    //input price of product
	    o=t.price;
        printf("Enter quantity bought: ");
	    scanf("%d",&t.qunt);    //input quantity of product
	    b=t.qunt;
	    printf("You purched: \n");
        total=total+o*b;               //for calculating total
	};
	printf("Your total amount is %f",total);
    
}
