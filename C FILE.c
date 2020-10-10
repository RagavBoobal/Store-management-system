#include<stdio.h>
#include<stdlib.h>
struct date
{
	int day,mon,year;
};
struct product
{
	int id;
	char name[30];
	int stock;
	int sold;
	int price;
};
struct customer
{
	int id;
	char name[30],address[60];
	long int phoneno;
};
struct Bill
{
	int id,quan;
	struct date dt;
	struct product sale[100]; 
};
main()
{
	register int i;
	int op,id,j=1,quan[100],k,total,amt;
	char o;
	FILE *pro,*bill,*cust;
	struct product p,*prorec,p2;
    struct customer c,*custrec;
	struct Bill b,*bilrec;
	while(1)
	{
		printf("\n\t\t\t1)ADD PRODUCT\n\t\t\t2)DISPLAY PRODUCTS\n\t\t\t3)Billing\n\t\t\4)ADD CUSTOMER\t\t\t5)DISPLAY CUSTOMER DETAILS\t\t\t6)PRICE LIMIT\t\t\t7)STOCK LIMI\t\t\t8)EXIT\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					while(1)
					{
					pro=fopen("product.dat","a+");
					//fflush(stdin);
					printf("\nENTER THE NAME OF THE PRODUCT : ");
					scanf("%s",p.name);
					while(1)
					{
						printf("ENTER THE PRODUCT ID : ");
						scanf("%d",&p.id);
						printf("\n");
						if(p.id>0)
						 break;
						 else
						 printf("invalid input\nre");
					}
					while(1)
					{
					printf("ENTER THE NUMBER OF PRODUCTS IN STOCK : ");
					scanf("%d",&p.stock);
					if(p.stock>=0)
					break;
					else
					printf("INVALID INPUT\nRE");
					}
					while(1)
					{
						printf("ENTER THE PRICE OF THE PRODUCT :");
						scanf("%d",&p.price);
						printf("\n");
						if(p.price>0)
						break;
						else
						printf("INVALID INPUT\nRE");
					}
					p.sold=0;
					prorec=&p;
					fread(prorec,sizeof(struct product),1,pro);
					fclose(pro);
					fflush(stdin);
					printf("DO YOU WANT TO KEEPING GOING (Y/N) : ");
					scanf("%c",&o);
					if(o=='n'||o=='N')
					{
					break;
				//system("CLS");
					}
					}
					system("CLS");
					break;
				}
			case 2:
				{
					pro=fopen("product.dat","r");
					if((pro=fopen("product.dat","r"))==NULL)
					{
						printf("NO PRODUCT HAS BEEN YET ADDED\n");
					}
					else
					{
					prorec=&p;
					while(!feof(pro))
					{
						fseek(pro,sizeof(struct product),1);
						fread(prorec,sizeof(struct product),1,pro);
						printf("PRODUCT ID\tPRODUCT NAME\tPRODUCT PRICE\tPRODUCT STOCK\tPRODUCT SOLD\t\n");
						printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",p.id,p.name,p.price,p.stock,p.sold);
					}
					}
					fclose(pro);
					break;
				}
			case 3:
				{
					//pro=fopen("product.dat","w+");
					bill=fopen("sales.dat","a");
					prorec=&p;
					bilrec=&b;
					i=0;
					while(1)
					{
						pro=fopen("product.dat","r");
						b.id=j;
						j++;
						printf("ENTER THE PRODUCT ID : ");
						scanf("%d",&id);
						while(!feof(pro))
						{
							fread(prorec,sizeof(struct product),1,pro);
							if(p.id==id)
							break;
						}
						fclose(pro);
						b.sale[i]=p;
						while(1)
						{
						printf("ENTER THE QUANTITY YOU WANT TO BUY : ");
						scanf("%d",&quan[i]);
						if(quan[i]>0)
						break;
						else
						printf("RE");
						}
						 /*pro=fopen("product.dat","w+");
						fseek(pro,id*sizeof(struct product),0);
						fread(prorec,sizeof(struct product),1,pro);
						p.stock=p.stock-quan[i];
						p.sold=p.sold+quan[i];
						fwirte(prorec,sizeof(struct product),1,pro);
						fclose(pro);*/
						//i++;
					//	fopen("product.dat","w");
						total=total+(quan[i]*p.price);
						printf("TO ADD MORE PRODUCTS PRESS (Y/N)");
						scanf("%c",&o);
						printf("\n");
						i++;
						pro=fopen("product.dat","w+");
						fseek(pro,id*sizeof(struct product),0);
						fread(prorec,sizeof(struct product),1,pro);
						p.stock=p.stock-quan[i];
						p.sold=p.sold+quan[i];
						fwrite(prorec,sizeof(struct product),1,pro);
						fclose(pro);
						if(o=='n'||o=='N')
						break;
				   }
				   		k=0;
						printf("\t\t\tBILL\nPRODUCT NAME\t PRODUCT PRICE\t QUANTITY\t");
						for(k=0;k<i;k++)
						printf("%s\t\t%d\t\t%d\n",b.id,b.sale[k].name,b.sale[k].price,quan[i]);
						printf("TOTAL : %d",total);
					fread(bilrec,sizeof(struct Bill),1,bill);
						fclose(pro);
						fclose(bill);
						break;
				}
			case 4:
				{
					while(1)
					{
						cust=fopen("customerdetail.dat","ab+");
						printf("\n ENTER THE NAME OF THE CUSTOMER:");
						scanf("%s",c.name);
						while(1)
					    {
						printf("ENTER THE PRODUCT ID : ");
						scanf("%d",&p.id);
						printf("\n");
						if(p.id>0)
						 break; 
						 else
						 printf("invalid input\nre");
					    }
						printf("\n ENTER THE CUSTOMER ADDRESS:");
						scanf("%d",c.address);
						printf("\n ENTER THE CUSTOMER PHONE NUMBER:");
						scanf("ld",&c.phoneno);
						custrec=&c;
						fread(custrec,sizeof(struct customer),1,cust);
						fclose(cust);
					   fflush(stdin);
					    printf("DO YOU WANT TO KEEPING GOING (Y/N) : ");
					    scanf("%c",&o);
					    if(o=='n'||o=='N')
					    {
					    break;
		                } 
					    system("CLS");
					    break;
					}
				}
			case 5:
			    {
			    	cust=fopen("customerdetail.dat","r");
					if((cust=fopen("customerdetail.dat","r"))==NULL)
					{
						printf("NO CUSTOMER HAS BEEN YET ADDED\n");
					}
					else
					{
					custrec=&c;
					while(!feof(cust))
					{
						fseek(cust,sizeof(struct customer),1);
						fread(custrec,sizeof(struct customer),1,cust);
						printf("CUSTOMER ID\tCUSTOMER NAME\tCUSTOMER ADDRESS\t\t\tCUSTOMER PHONE NUMBER\t\n");
						printf("%d\t\t%s\t\t%s\t\t\t\t\t\t%ld\n",c.id,c.name,c.address,c.phoneno);
					}
					}
					fclose(cust);
					break;
				}
			case 6:
			    {
			    	prorec=&p;
			    	printf("enter the amount:");
			    	scanf("%d",&amt);
			    	while(!feof(pro))
			    	{
			    		fread(prorec,sizeof(struct product),1,pro);
			    		if(p.price<amt)
			    		{
			    			printf("%d",p.name);
			    			printf("%d",p.stock);
			    			
						}
					}
					}	
			case 7:
			{
				    prorec=&p;
				    while(!feof(pro))
				    {
				    	fread(prorec,sizeof(struct product),1,pro);
						if(prorec->stock<25)
						{ 
						printf("product name:%s\nproduct id:%s\n",p.name,p.id);
					}
					
							}	
					break;
			}
									
					
					
	}	}
}

