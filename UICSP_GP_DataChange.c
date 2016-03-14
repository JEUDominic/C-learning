//
//
// SPGroupProject_DataChage.c
// 
// struct items *LoadItemList();
// int StorageItemList();
// int AddItem(struct items* head,char itemName[], int initialAmount, double initialPrice);
// int DeleteItem(struct items* head,int itemID);
// int ChangeAmount(struct items* head,int difference, int itemID);
// int ChangePrice(struct items* head,double price, int itemID);
// int ChangeName(struct items* head,char name[], int itemID);
// double CalculatePrice(struct items* head,int amount, int itemID);
//  
//
// Created by JEU. 20151211

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct items{
	char name[20];
	int amount;
	double price;
	struct items* next;
};



struct items *LoadItemList()
{
//This function reads the item list from a file and return the address of the first item in the list.
//Augments definition:
	//FILE* list:       Point to the open file "item.dat".
	//struct* head:     Will be return as the head of the items' linklist.
	//struct* node1:    Using it while creating the linklist.
	//struct* node2:    Using it while creating the linklist.
	//struct* p: Store the previous address while update the node1.
//Returns:
	//Return the address of the first item if reads the file into memory successfully.
	//Return NULL if can't open the file. File may not exist or is not in the right syntax.
	
	FILE* list = fopen("item.dat","r");
	if(list == NULL)
		return NULL;
	struct items* head;
	struct items* node1;
	struct items* node2;
	struct items* p;
	node1 = (struct items*)malloc(sizeof(struct items));
	head = node1;
	p = node1;
	while(fscanf(list,"%s %d %lf",node1->name,&node1->amount,&node1->price) != EOF)
	{
		p = node1;
		node2 = (struct items*)malloc(sizeof(struct items));
		node1->next = node2;
		node1 = node2;
	}
	p->next = NULL;
	
	p =  head;
	while(p){
		printf("%i %s %d %.2f %i\n",p,p->name,p->amount,p->price,p->next);
		p = p->next;
	}
		
	free(node1);
	fclose(list);
	
	return head;
}
int StorageItemList(struct items* head)
{
//This function save the item list in the memory into the file.
//Augments definition:
	//FILE*list:          Creat a file named "item.dat".
	//struct items* head: The head of the linkedlist.
//Returns:
	//Return 0:           Saved successfully.
	//Return -1:          Can't save the file.
	FILE*list = fopen("item.dat","w");
	if(list == NULL)
		return -1;
	while(head)
	{
		fprintf(list,"%s %d %f\n",head->name,head->amount,head->price);
		head = head->next;
	}
	return 0;
	
}

int AddItem(struct items* head,char itemName[], int initialAmount, double initialPrice)
{
//This function adds a new good into the end of the list.
//Augments definition:
	//struct items* head:  The head address of the item list, then change it to the new item's address.
	//char itemName[]:     The name of the new good.
	//int initialAmount:   The initial amount of the good.
	//double initialPrice: The initial Price of the amount.
//Returns:
	//Return 0:            An good has been added successfully.
	//Return -1:           There is something with exactly the same name.

	do{
		if(strcmp(head->name,itemName) == 0)
			return -1;	// Existing same item...
		if(head->next == NULL)
			break;
		head = head->next;
	}while(1);
	
	head->next = (struct items*)malloc(sizeof(struct items));
	head = head->next;
	// Adding item..
	strcpy(head->name,itemName);
	head->amount = initialAmount;
	head->price = initialPrice;
	head->next = NULL;
	
	return 0;
}

int DeleteItem(struct items* head,int itemID)
{
//This function delete an item from the list basing on the ID inputed.
//Augments definition:
	//struct items* head: The head address of the item list, then change it to the deleted item's address.
	//struct items* p:     The address of the item before the deleted item.
	//int itemID:         The itemIDth item need to be deleted, regard the first one's ID as 1.
//Returns:
	//Return 0:           Successfully delete the target item.
	//Retrun -1:          Can't find the item with the inputed ID.
//How it work: Search the list for the item with the inputed ID, delete the struct of the item, and link the former and later items together.
	
	struct items* p = head;
	for(int i = 0;i < itemID-1;i++)
	{
		if(head == NULL)
			return -1; // Invalid itemID...
		p = head;
		head = head->next;
	}
	p->next= head->next;
	free(head);
	
	return 0;
}

int ChangeAmount(struct items* head,int difference, int itemID)
{
//This function changes a thing's amount.
//Augments definition:
	//struct items* head: The head address of the item list, then change it to the amount changed item's address.
	//int difference:     The amount that change, can be negative integer to decrease the amount.
	//int itemID:         The itemIDth item need to be changed the amount, regard the first one's ID as 1.
//Returns:
	//Return 0:           Changed successfully.
	//Return -1:          Can't find the item with the inputed ID.
	//Return -2:          The amount is not enough to consume.

	for(int i = 0;i < itemID-1;i++)
	{
		if(head == NULL)
			return -1; // Invalid itemID...
		head = head->next;
	}
	if(difference < 0 && difference < 0 - head->amount)
		return -2;// The amount is not enough to consume.
		
	head->amount = head->amount + difference;
	return 0;
	
}

int ChangePrice(struct items* head,double price, int itemID){
//This function changes a thing's price.
//Augments definition:
	//struct items* head: The head address of the item list, then change it to the price changed item's address.
	//int price:          The price after change.
	//int itemID:         The itemIDth item need to be changed the price, regard the first one's ID as 1.
//Returns:
	//Return 0:           Changed successfully.
	//Return -1:          Can't find the item with the inputed ID.
	for(int i = 0;i < itemID-1;i++)
	{
		if(head == NULL)
			return -1; // Invalid itemID...
		head = head->next;
	}
	
	head->price = price;
	return 0;
	
}

int ChangeName(struct items* head,char name[], int itemID){
//This function changes a thing's name.
//Augments definition:
	//struct items* head: The head address of the item list, then change it to the name changed item's address.
	//char name[]:        The new name to be assigned.
	//int itemID:         The itemIDth item need to be changed the name, regard the first one's ID as 1.
//Returns:
	//Return 0:           Changed successfully.
	//Return -1:          Can't find the item with the inputed ID.

	for(int i = 0;i < itemID-1;i++)
	{
		if(head == NULL)
			return -1; // Invalid itemID...
		head = head->next;
	}
	strcpy(head->name,name);
	return 0;
}

double CalculatePrice(struct items* head,int amount, int itemID){
//This function calculates one thing's price.
//Augments definition:
	//struct items* head: The head address of the item list, then change it to the seleted item's address.
	//int amount:         The amount of the target item.
	//int itemID:         The ID of the target item.
//Returns definition:
	//Return total price: Buy successfully.
	//Return -1:          Can't find the item with the inputed ID.
	//Return -2:          The amount is not enough to consume.
	for(int i = 0;i < itemID-1;i++)
	{
		if(head == NULL)
			return -1; // Invalid itemID...
		head = head->next;
	}
	if(amount > head->amount)
		return -2;// The amount is not enough to consume.
	return amount*head->price;
	
}

int main()
{

	struct items* head;
	head = LoadItemList();
	while(head)
	{
		printf("%i %s %d %.2f %i\n",head,head->name,head->amount,head->price,head->next);
		head = head->next;
	}
	return 0;
}

