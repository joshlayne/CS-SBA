#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMOUNT 10

struct list
{
    float price;
    char name[50];
    int quantity;
    int id;
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
    printf("\tQC-Soft Stock Management System\n\n"); 
	printf("l. Search on Price Range\n"); 
	printf("2. Search on item name\n");
    printf("3. Search by ID\n");
    printf("4. Add a product\n");
    printf("5. Remove Product\n");
    printf("6. Replace product\n"); 
    printf("7. Order a product\n");
	printf("8. Exit \n"); 
}

int main()
{
    struct list item[50] ={0}; 
    
    int amount = 0, tempamount;
	int tempcounter, option;
	int i, x;
	char deleted[50];

    FILE *file1 = fopen("stock.txt","r"); 
	FILE *file2 = fopen("stock_temp.txt","w");

    if(!file1)
	   {
	    	printf("File Cannot Be Opened"); 
			exit(0);   
	   }

    menu();
    printf("\nPlease choose an option: ");
    scanf(" %d", option);

    switch (option)
    {
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
            /* code */
            break;

        case 6:
            /* code */
            break;

        case 7:
            /* code */
            break;

        case 8:
            printf(" Thank you, Have a great day!!");
       		exit(0);
        
        default:
            printf("Invalid entry");
            break;
    }
}
