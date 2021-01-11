#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int itemAmount = 0;

//This structure stores item information
struct list
{
    float price;
    char name[50];
    int quantity;
    int id;
};
struct list item[50] ={0};


//This function prints all items with a price equal to or lower to an entered price
void range (float amount, struct list item[]) 
{
	int i;
	for (i=0;i<itemAmount;i++)
	if (item[i].price <= amount)
		printf("%s: \nPrice:%.2f \nID:%d \nQuantity: %d\n\n",item[i].name, item[i].price, item[i].id, item[i].quantity); 
}

//This function prints items with an item ID matching with an entered item ID
void ident(int idnum, struct list item[])
{
	int i;
	for ( i = 0; i < itemAmount; i ++)
	{
		if (idnum == item[i].id)
		{
			printf("%s:\nPrice: $%.2f\nID: %d\nQuantity: %d\n",item[i].name,item[i].price,item[i].id,item[i].quantity);
		}
	}
}

//This function prints items with a quantity equal to or lower to an entered quantity
void searchQuant (int sQuant, struct list item[])
{
	int x;
	printf("All items with a quantity of %d or less: \n", sQuant); 
    for (x = 0 ; x < itemAmount; x++) 
    {
		if(item[x].quantity <= sQuant)
			printf("Item: %s\nQuantity: %d\n\n", item[x].name, item[x].quantity);
	}
}    

//This function prints item information of an entered item
void searchName(char product[], struct list item[])
{
	int index;
	for (index=0;index < itemAmount;index++)
	{
		if (strcasecmp(product, item[index].name)==0)
			printf("%s:\nID: %d\nQuantity: %d\nPrice: $%.2f\n", item[index].name, item[index].id, item[index].quantity, item[index].price);
	}
}

//This structure stores information on current orders
struct order
{
	char compName[30], itemName[50];
	int quant;
};
struct order pending[10];

int orderNum = 0;//This keeps track of how many orders have been made

//This function takes information on orders
void ordering(struct order pending[])
{
	printf("What company would you like to order from?: ");
	scanf(" %[^\n]s", pending[orderNum].compName);
	printf("What item would you like to order?: ");
	scanf(" %[^\n]s", pending[orderNum].itemName);
	printf("How much of this item would you like to order?: ");
	scanf(" %d", &pending[orderNum].quant);
	printf("\nOrder succesful!\n");
	orderNum++;
}


//This function displays pending orders
void seeOrders(struct order pending[])
{
	int i = 0;
	for(i; i < orderNum; i++)
	{
		printf("Order #%d\n", i+1);
		printf("Company: %s\nItem: %s\nQuantity: %d\n\n", pending[i].compName, pending[i].itemName, pending[i].quant);
	}
}
                                                        
//This function displays the menu
void menu ()
{
	printf("\tManagement Software Menu\n");
	printf("1/Search by price\n");
	printf("2/Search by ID\n");
	printf("3/Search by quantity\n");
	printf("4/Search by name\n");
	printf("5/Order stock\n");
	printf("6/See pending orders\n");
	printf("7/Add product\n");
	printf("8/Remove product\n");
	printf("9/Replace product\n");
	printf("10/Exit\n");
}

int main()
{
	int i, x;
	int option;
	char searchedName[50];
	int searchedId , searchedQuant;
	float searchedPrice;
	int stop = 0;
	
	char addName[50], removeName[50];
	int addQuantity, addId;
	float addPrice;
	int tempID;
	char replace[50], reName[50];
	int reId, reQuantity;
	float rePrice;
	
	
	FILE *file1 = fopen("items.txt","r");
	for(i = 0; i < 50 && !feof(file1); i++) 
	{
		fscanf(file1, "%d", &item[i].id); 
		fgetc(file1);
		fscanf(file1, "%d", &item[i].quantity); 
		fgetc(file1);
		fscanf(file1, "%f", &item[i].price);
		fgetc(file1);
		fscanf(file1, "%[^\n]s",&item[i].name);
		if(item[i].price!= 0)
			itemAmount++;
	}
	
	do
	{
		system("cls");
		menu();
        printf("\nPlease choose an option: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				system("cls");
				printf("Please enter item price: ");
				scanf(" %f", &searchedPrice);
				range(searchedPrice, item);
				system("pause");
				break;
		
			case 2:
				system("cls");
				printf("Please enter item ID: ");
				scanf(" %d", &searchedId);
				ident(searchedId, item);
				system("pause");
				break;
			
			case 3:
				system("cls");
				printf("Please enter item quantity: ");
				scanf(" %d", &searchedQuant);
				searchQuant(searchedQuant, item);
				system("pause");
				break;
			
			case 4:
				system("cls");
				printf("Please enter item name: ");
				scanf(" %[^\n]s", searchedName);
				searchName(searchedName, item);
				system("pause");
				break;
			
			case 5:
				system("cls");
				ordering(pending);
				system("pause");
				break;
			
			case 6:
				system("cls");
				seeOrders(pending);
				system("pause");
				break;
			
			case 7:
				{
					FILE *file2 = fopen("items_temp.txt","w");
				
					system("cls");
					printf("%d Please enter the name of the item you wish to add: ", itemAmount);
					scanf(" %[^\n]s", addName);
		
					printf("%d Please enter the price of the item you wish to add: ", itemAmount);
					scanf(" %f", &addPrice);
					
					printf("%d Please enter the ID of the item you wish to add: ", itemAmount);
					scanf(" %d", &addId);
					
					printf("%d Please enter the quantity of the item you wish to add: ", itemAmount);
					scanf(" %d", &addQuantity);
					
					for (x = 0; x < itemAmount; x++)
	           		{
						fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
	            	}
	            	fprintf(file2, "%d %d %.2f %s", addId, addQuantity, addPrice, addName);
	            	itemAmount = 0;
	            	
	            	fclose(file1);
	            	fclose(file2);
	            	remove("items.txt");
	            	rename("items_temp.txt", "items.txt");
	            	
	            	FILE *file1 = fopen("items.txt","r");
					for(i = 0; i < 50 && !feof(file1); i++) 
					{
						fscanf(file1, "%d", &item[i].id); 
						fgetc(file1);
						fscanf(file1, "%d", &item[i].quantity); 
						fgetc(file1);
						fscanf(file1, "%f", &item[i].price);
						fgetc(file1);
						fscanf(file1, "%[^\n]s",&item[i].name);
						if(item[i].price!= 0)
							itemAmount++;
					}
					break;
				}
				
			case 8:
				{
					FILE *file2 = fopen("items_temp.txt","w");
				
					system("cls");
					printf("%d Please enter the name of the item you wish to remove: ", itemAmount);
					scanf(" %[^\n]s", removeName);
					for (x = 0; x < itemAmount; x++)
		            {
		                if (strcasecmp(removeName, item[x].name)!=0)
		                {
		                    fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
		                }
		            }
		            itemAmount = 0;
	            	
	            	fclose(file1);
	            	fclose(file2);
	            	remove("items.txt");
	            	rename("items_temp.txt", "items.txt");
	            	
	            	FILE *file1 = fopen("items.txt","r");
					for(i = 0; i < 50 && !feof(file1); i++) 
					{
						fscanf(file1, "%d", &tempID);
						if(tempID == item[i-1].id)
							break;
						else
							item[i].id = tempID;
						fgetc(file1);
						fscanf(file1, "%d", &item[i].quantity); 
						fgetc(file1);
						fscanf(file1, "%f", &item[i].price);
						fgetc(file1);
						fscanf(file1, "%[^\n]s",&item[i].name);
						if(item[i].price!= 0)
							itemAmount++;
					}
					break;
				}
			case 9:
				{
					FILE *file2 = fopen("items_temp.txt","w");
					
					system("cls");
					printf("Please enter the name of the item you wish to replace: ");
					scanf(" %[^\n]s", replace);
            
		            printf("What do you want to replace %s with: ", replace);
		            scanf(" %[^\n]s", reName);
		            
		            printf("What is the ID of %s: ", reName);
		            scanf(" %d", &reId);
		            
		            printf("What is the quantity of %s: ", reName);
		            scanf(" %d", &reQuantity);
		            
		            printf("What is the price for %s: ", reName);
		            scanf(" %f", &rePrice);
					
					for (x = 0; x < itemAmount; x++)
		            {
		                if (strcasecmp(replace, item[x].name)!=0)
		                {	
		                    fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
		                }
		                else
		                {
		                    strcpy(item[x].name, reName);
		                    item[x].price = rePrice;
		                    item[x].id = reId;
		                    item[x].quantity = reQuantity;
		                    
		                    fprintf(file2, "%d %d %.2f %s\n", item[x].id, item[x].quantity, item[x].price, item[x].name);
		                }
		            }
					fclose(file1);
	            	fclose(file2);
	            	remove("items.txt");
	            	rename("items_temp.txt", "items.txt");		
					break;	
				}
				
			case 10:
				stop = 1;
				break;	
		}
	
	}while(stop!=1);

	
	return 0;
}