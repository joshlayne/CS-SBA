#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMOUNT 10

struct list
{
    float price;
    char name[50];
};

float cost(char product[], struct list item[])
{
    int index; 
    for (index=0;index<AMOUNT;index++) 
       {
	   
			if (strcasecmp(product, item[index].name)==0) 
				return item[index].price; 
	   }
	return 0.0;
}

void range (float amount, struct list item[])
{
    int index; 
    for (index=0;index<AMOUNT;index++) 
         if (item[index].price <= amount) 
                printf("%s $%4.2f\n",item[index].name, item[index].price); 
}

void menu() 
{
    printf("\tQC Soft Stock Management System\n\n"); 
	printf("l. Search on Price Range\n"); 
	printf("2. Search on item name\n");
    printf("3. Add a product\n");
    printf("4. Remove Product\n");
    printf("5. Replace product\n"); 
	printf("6. Exit \n"); 
}

int main()
{
  
}
