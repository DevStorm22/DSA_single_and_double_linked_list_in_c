/*

Created by Kaushik Chandrashekhar Musale.
All copy writes are reserved.
Menu driven program for performing operations on doubly linked list
Date:- 19/09/2023

*/

//Doubly linked list

/*Operation of the doubly linked list
1.Creation and initialization of the doubly linked list
2.Counting the nodes of the doubly linked list
3.Searching the element form the doubly linked list
4.Insertion of node before the first node in the doubly linked list
5.Insertion of node in the given position in the doubly linked list
6.Insertion of node after the last node in the doubly linked list
7.Removing first node from the doubly linked list
8.Removing node of given position form the doubly linked list
9.Removing last node from the doubly linked list
10.Sorting the doubly linked list
11.Concating the doubly linked list
12.Seprating the doubly linked list
13.Merging the sorted doubly linked lists
14.Merging and sorting the doubly linked lists
15.Displaying the doubly linked list
16.Reverse printing of the doubly linked list
17.Quit*/

//Header files
#include <stdio.h>
#include <stdlib.h>

//ADT
typedef struct dnode
{
	int data;
	struct dnode *next, *prev;
}dnode;

//Function declaration
dnode *creation_and_initialization_of_doubly_linked_list(dnode*);
int counting_of_nodes_in_doubly_linked_list(dnode *);
dnode *searching_an_element_from_doubly_linked_list(dnode *, int);
dnode *insertion_of_node_at_the_beginning_of_doubly_linked_list(dnode *, int);
dnode *insertion_of_node_at_the_given_position_of_doubly_linked_list(dnode *,int, int);
dnode *insertion_of_node_at_the_ending_of_doubly_linked_list(dnode *, int);
dnode *deletion_of_node_at_the_beginning_of_doubly_linked_list(dnode *);
dnode *deletion_of_node_at_the_given_position_of_doubly_linked_list(dnode *, int);
dnode *deletion_of_node_at_the_ending_of_doubly_linked_list(dnode *);
dnode *sorting_the_doubly_linked_list(dnode *);
dnode *concatinating_the_doubly_linked_list(dnode *);
dnode *spliting_the_doubly_linke_list(dnode *);
dnode *merging_the_sorted_doubly_linked_list(dnode *);
dnode *merging_and_sorting_doubly_linked_list(dnode *);
void displaying_the_doubly_linked_list(dnode *);
void displaying_the_doubly_linked_list_in_reverse_order(dnode *);

//Main function
int main()
{
	dnode *head;
	int option, c, key, temp, pos;
	head = creation_and_initialization_of_doubly_linked_list(head);
	do
	{
		printf("\nOperation of the doubly linked list\n1.Counting the nodes of the doubly linked list\n2.Searching the element form the doubly linked list\n3.Insertion of node before the first node in the doubly linked list\n4.Insertion of node in the given position in the doubly linked list\n5.Insertion of node after the last node in the doubly linked list\n6.Removing first node from the doubly linked list\n7.Removing node of given position form the doubly linked list\n8.Removing last node from the doubly linked list\n9.Sorting the doubly linked list\n10.Concating the doubly linked list\n11.Seprating the doubly linked list\n12.Merging the sorted doubly linked lists\n13.Merging and sorting the doubly linked list\n14.Displaying the doubly linked list\n15.Reverse printing of the doubly linked list\n16.Quit\nEnter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				c = counting_of_nodes_in_doubly_linked_list(head);
				printf("Number of nodes of the doubly linked list are %d", c);
				break;
			case 2:
				printf("Enter element to search in the doubly linked list: ");
				scanf("%d", &key);
				head = searching_an_element_from_doubly_linked_list(head, key);
				break;
			case 3:
				printf("Enter the element to insert at the beginnig of the doubly linked list: ");
				scanf("%d", &temp);
				head = insertion_of_node_at_the_beginning_of_doubly_linked_list(head, temp);
				break;
			case 4:
				printf("Enter the position of the node to be inserted: ");
				scanf("%d", &pos);
				printf("Enter the element to insert at the given position in the doubly linked list: ");
				scanf("%d", &temp);
				head = insertion_of_node_at_the_given_position_of_doubly_linked_list(head, pos, temp);
				break;
			case 5:
				printf("Enter the element to insert at the ending of the doubly linked list: ");
				scanf("%d", &temp);
				head = insertion_of_node_at_the_ending_of_doubly_linked_list(head, temp);
				break;
			case 6:
				head = deletion_of_node_at_the_beginning_of_doubly_linked_list(head);
				break;
			case 7:
				printf("Enter the position of the node to be removed: ");
				scanf("%d", &pos);
				head = deletion_of_node_at_the_given_position_of_doubly_linked_list(head, pos);
				break;
			case 8:
				head = deletion_of_node_at_the_ending_of_doubly_linked_list(head);
				break;
			case 9:
				head = sorting_the_doubly_linked_list(head);
				break;
			case 10:
				head = concatinating_the_doubly_linked_list(head);
				break;
			case 11:
				head = spliting_the_doubly_linke_list(head);
				break;
			case 12:
				head = merging_the_sorted_doubly_linked_list(head);
				break;
			case 13:
				head = merging_and_sorting_doubly_linked_list(head);
				break;
			case 14:	
				displaying_the_doubly_linked_list(head);
				break;
			case 15:
				displaying_the_doubly_linked_list_in_reverse_order(head);
				break;
		}
	}
	while(option != 16);
	return 0;
}

//Function definition
dnode *creation_and_initialization_of_doubly_linked_list(dnode *head)
{
	dnode *p, *q;
	int size, i;
	printf("Enter the size of the doubly linked list: ");
	scanf("%d", &size);
	head = (dnode *) malloc (sizeof(dnode));
	printf("Enter the head of the doubly linked list: ");
	scanf("%d", &(head -> data));
	head -> prev = head -> next = NULL;
	p = head;
	for(i = 1; i < size; i++)
	{
		q = p;
		p -> next = (dnode *) malloc (sizeof(dnode));
		p = p -> next;
		p -> next = NULL;
		p -> prev = q;
		printf("Enter the data for the node %d: ", i + 1);
		scanf("%d", &(p -> data));
	}
	return head;
}

int counting_of_nodes_in_doubly_linked_list(dnode *head)
{
	dnode *p;
	int c;
	p = head;
	c = 0;
	while(p != NULL)
	{
		c++;
		p = p -> next;
	}
	printf("\n");
	return c;
}

dnode *searching_an_element_from_doubly_linked_list(dnode *head, int key)
{
	dnode *p;
	int flag;
	p = head;
	while(p != NULL)
	{
		if(key == p -> data)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
		p = p -> next;
	}
	if(flag == 1)
	{
		printf("Element found!!!\n");
	}
	else
	{
		printf("Element not found!!!\n");
	}
	return head;
}

dnode *insertion_of_node_at_the_beginning_of_doubly_linked_list(dnode *head, int key)
{
	dnode *p, *q;
	p = head;
	q = (dnode *) malloc (sizeof(dnode));
	q -> next = NULL;
	q -> data = key;
	q -> next = p;
	p -> prev = q;
	head = q;
	printf("Element inserted!\n");
	return head;
}

dnode *insertion_of_node_at_the_given_position_of_doubly_linked_list(dnode *head, int pos, int key)
{
	dnode *p, *q;
	int c;
	p = head;
	c = 0;
	q = (dnode*) malloc (sizeof(dnode));
	q -> data = key;
	q -> prev = NULL;
	q -> next = NULL;
	while (c != pos - 2)
	{
		c++;
		p = p -> next;
	}
	q -> next = p -> next;
	q -> prev = p;
	p -> next = q;
	q -> next -> prev = q;
	printf("Element inserted!\n");
	return head;
}

dnode *insertion_of_node_at_the_ending_of_doubly_linked_list(dnode *head, int key)
{
	dnode *p, *q;
	p = head;
	q = (dnode *) malloc (sizeof(dnode));
	q -> data = key;
	q -> next = NULL;
	q -> prev = NULL;
	while(p -> next != NULL)
	{
		p = p -> next;
	}
	p -> next = q;
	q -> prev = p;
	printf("Element inserted!\n");
	return head;
}

dnode *deletion_of_node_at_the_beginning_of_doubly_linked_list(dnode *head)
{
	dnode *p;
	p = head;
	head = head -> next;
	free(p);
	head -> prev = NULL;
	printf("Element deleted!\n");
	return head;
}

dnode *deletion_of_node_at_the_given_position_of_doubly_linked_list(dnode *head, int pos)
{
	dnode *p, *q;
	int c;
	p = head;
	c = 0;
	q = (dnode*) malloc (sizeof(dnode));
	q -> next = q -> prev = NULL;
	while(c != pos - 2)
	{
		c++;
		p = p -> next;
	}
	q = p -> next;
	p -> next = q -> next;
	q -> next -> prev = p;
	free(q);
	printf("Element deleted!\n");
	return head;
}

dnode *deletion_of_node_at_the_ending_of_doubly_linked_list(dnode *head)
{
	dnode *p, *q;
	int temp;
	p = head;
	while(p -> next -> next != NULL)
	{
		p = p -> next;
	}
	q = p -> next;
	p -> next = NULL;
	free(q);
	printf("Element deleted!\n");
	return head;
}

dnode *sorting_the_doubly_linked_list(dnode *head)
{
	dnode *p, *q;
	int temp;
	int c;
	p = head;
	c = 0;
	while(p != NULL)
	{
		c++;
		p = p -> next;
	}
	for(p = head; p -> next != NULL; p = p -> next)
	{
		q = p -> next;
		for (q = p -> next; q != NULL; q = q -> next)
		{
			if(q -> data < p -> data)
			{
				temp = p -> data;
				p -> data = q -> data;
				q -> data = temp;
			}
		}
	}
	printf("\n");
	return head;
}

dnode *concatinating_the_doubly_linked_list(dnode *head)
{
	dnode *h, *p;
	h = creation_and_initialization_of_doubly_linked_list(h);
	p = head;
	while(p -> next != NULL)
	{
		p = p -> next;
	}
	p -> next = h;
	h -> prev = p;
	printf("\n");
	return head;
}

dnode *spliting_the_doubly_linke_list(dnode *head)
{
	dnode *p, *q;
	int c, pos;
	printf("\nEnter the point where you want to split the doubly linked list: ");
	scanf("%d", &pos);
	c = 0;
	p = head;
	while(c != pos - 2)
	{
		c++;
		p = p -> next;
	}
	q = p -> next;
	p -> next = NULL;
	q -> prev = NULL;
	printf("\n");
	return head;
}

dnode *merging_the_sorted_doubly_linked_list(dnode *head)
{
	dnode *h, *p;
	h = creation_and_initialization_of_doubly_linked_list(h);
	head = sorting_the_doubly_linked_list(head);
	h = sorting_the_doubly_linked_list(h);
	p = head;
	while(p -> next != NULL)
	{
		p = p -> next;
	}
	p -> next = h;
	h -> prev = p;
	printf("\n");
	return head;
}

dnode *merging_and_sorting_doubly_linked_list(dnode *head)
{
	dnode *h;
	h = (dnode *) malloc (sizeof(dnode));
	head = concatinating_the_doubly_linked_list(head);
	head = sorting_the_doubly_linked_list(head);
	return head;
	printf("\n");
}

void displaying_the_doubly_linked_list(dnode *head)
{
	dnode *p;
	p = head;
	while(p != NULL)
	{
		printf("<- %d ->", (p -> data));
		p = p -> next;
	}
	printf("\n");
}

void displaying_the_doubly_linked_list_in_reverse_order(dnode *head)
{
	dnode *p;
	p = head;
	printf("\n");
	while(p -> next != NULL)
	{
		p = p -> next;
	}
	while(p != NULL)
	{
		printf("<- %d ->", (p -> data));
		p = p -> prev;
	}
	printf("\n");
}