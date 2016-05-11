//Brett Chafin's Assignment 1
//This .cpp contains class inventory functions

#include "classes.h"
using namespace std; 


//constructor 
inventory::inventory():head(NULL)
{

}

//destructor
inventory::~inventory()
{
	while(head)//while head is not NULL
	{
	item_node * temp = head;
	head = head->next;
	delete temp;
	}	
}

//checks to see if player has an item
bool inventory::check_for(char * search_item)
{
	//no items
	if(!head)
		return false;
	
	item_node * current = head;
	while(current)
	{
		if(!strcmp(current->item_name, search_item))//if match found
			return true;
		else 
			current = current->next; 
	}
	return false;//no match found

	
}

//displays inventory
int inventory::display_inventory()
{
	//no items
	if(!head)
		return 0;
	
	item_node * current = head;
	while(current)
	{
		cout << current->item_name <<endl;
		current = current->next;
	}
}

//deletes particular item
int inventory::delete_item(char * to_delete)
{
	//no items to delete
	if(!head)
		return 1;

	item_node * current = head;
	item_node * prev = current; 
	//if item if head
	if(!strcmp(head->item_name, to_delete))
	{
		head = head->next;
		delete current;
		return 0; 
	}
	
	while(current->next)
	{
		prev = current;
		current = current->next;
		if(!strcmp(current->item_name, to_delete))
		{
			prev->next = current->next;
			delete current;
			return 0;
		}
	}
	
}


//adds item to inventory
int inventory::add_item(char * to_add)
{
	if(!head)
	{
		head = new item_node;
		head->item_name = new char[strlen(to_add) +1];
		strcpy(head->item_name, to_add);
		head->next = NULL;
	}
	else
	{
		item_node * current = head;
		while(!current->next)//traverse til you get to last node
		{
			current = current->next;
		}

		current->next = new item_node;
		current->item_name = new char[strlen(to_add) +1];
		strcpy(current->item_name, to_add);
		current->next = NULL;
	}
}
