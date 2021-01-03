#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMOUNT 15

struct list
{
    float price;
    char name[50];
    int quantity;
    int id;
};

struct order
{
	char compName[30], itemName[50];
	int quant;
};
struct order pending[10];

int orderNum = 0;
void ordering(struct order pending[])
{
	printf("What company would you like to order from?: ");
	scanf(" %[^\n]s", pending[orderNum].compName);
	printf("What item would you like to order?: ");
	scanf(" %[^\n]s", pending[orderNum].itemName);
	printf("How much of this item would you like to order?: ");
	scanf(" %d", &pending[orderNum].quant);
	printf("\nOrder succesful!\n");
	system("pause");
	system("cls");
	orderNum++;
}

void seeOrders(struct order pending[])
{
	int i = 0;
	for(i; i < orderNum; i++)
	{
		printf("Order #%d\n", i+1);
		printf("Company: %s\nItem: %s\nQuantity: %d\n\n", pending[i].compName, pending[i].itemName, pending[i].quant);
	}
	system("pause");
	system("cls");
}


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
  //printf("4. Search on Quantity Range\n"); 
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
	int tempcounter;
	int i, x;
	char addname[50];
	float addprice;
	int addquantity, addid;
    float reprice;
    char replace[50], reName[50];
	int reid, requantity;
    char deleted[50];
    int option;

    float money;

    FILE *file1 = fopen("stock.txt","r"); 

    if(!file1)
	   {
	    	printf("File Cannot Be Opened"); 
			exit(0);   
	   }

    for(i = 0; i < 50 && !feof(file1); i++) 
	{
		fscanf(file1, "%d", &item[i].id); 
		fgetc(file1);
		fscanf(file1, "%d", &item[i].quantity); 
		fgetc(file1);
		fscanf(file1, "%f", &item[i].price);
		fgetc(file1);
		fscanf(file1, "%[^\n]s",&item[i].name);
	 
	    if(item[i].price != 0)
			amount++;
	}

    menu();
    printf("\nPlease choose an option: ");
    scanf(" %d", &option);

    switch (option)
    {
        case 1:
            printf(" Please enter your price range: $");
       		scanf(" %f", &money);
       		range(money, item);

            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

       /* case 4:
             code 
            break; */

        case 4:
        {
            FILE *file2 = fopen("stock_temp.txt","w");

            printf("%d Please enter the name of the item you wish to add: ", amount);
            scanf(" %[^\n]s", addname);
        
            printf("Please enter the ID of the item you wish to add: ");
            scanf(" %d", &addid);
            
            printf("Please enter how much of %s do you wish to add: ", addname);
            scanf(" %d", &addquantity);
            
            printf("%d Please enter the price of the item you wish to add: ", amount);
            scanf(" %f", &addprice);
            
            for (x = 0; x < amount; x++)
            {
                fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
            }
            fprintf(file2, "%d %d %.2f %s", addid, addquantity, addprice, addname);
            ++amount;
            
            fclose(file1);
            fclose(file2);
            
            remove("stock.txt");
            rename("stock_temp.txt", "stock.txt");
            break;
        }
        
        case 5:
        {
            FILE *file2 = fopen("stock_temp.txt","w");

            printf("%d Please enter the name of the item you wish to remove: ", amount);
            scanf(" %[^\n]s", deleted);
            
            for (x = 0; x < amount; x++)
            {
                if (strcasecmp(deleted, item[x].name)!=0)
                {
                    fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
                }
            }
            getchar();
            amount--;
            
            fclose(file1);
            fclose(file2);
            
            remove("stock.txt");
            rename("stock_temp.txt", "stock.txt");

            break;
        }

        case 6:
        {
            FILE *file2 = fopen("stock_temp.txt","w");

            printf("%d Please enter the name of the item you wish to replace: ", amount);
            scanf(" %[^\n]s", replace);
            
            printf("What do you want to replace %s with: ", replace);
            scanf(" %[^\n]s", reName);
            
            printf("What is the ID of %s: ", reName);
            scanf(" %d", &reid);
            
            printf("What is the quantity of %s: ", reName);
            scanf(" %d", &requantity);
            
            printf("What is the price for %s: ", reName);
            scanf(" %f", &reprice);
            
            
            for (x = 0; x < amount; x++)
            {
                if (strcasecmp(replace, item[x].name)!=0)
                {	
                    fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
                }
                else
                {
                    strcpy(item[x].name, reName);
                    item[x].price = reprice;
                    item[x].id = reid;
                    item[x].quantity = requantity;
                    
                    fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
                }
            }
            //amount--;
            
            fclose(file1);
            fclose(file2);
            
            remove("stock.txt");
            rename("stock_temp.txt", "stock.txt");

            break;
        }

        case 7:
            int d;
	        for (d = 0; d < 3; d++)
            {
                ordering(pending);
                seeOrders(pending);
            }

            break;

        case 8:
            printf(" Thank you, Have a great day!!");
       		exit(0);
        
        default:
            printf("Invalid entry");
            break;
    }
}
