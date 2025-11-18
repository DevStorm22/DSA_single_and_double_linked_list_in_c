/*

Created by Kaushik Chandrashekhar Musale.
All copy writes are reserved.
Menu driven program for performing operations on singly linked list
Date:- 01/08/2023

*/

// Linked list operation through functions

/*

Operation of the linked list
1.Creation and initialization
2.Counting the nodes of the linked list
3.Searching the element form the linked list
4.Insertion of node before the first node
5.Insertion of node in the given position
6.Insertion of node after the last node
7.Removing first node from the linked list
8.Removing node of given position form the linked list
9.Removing last node from the linked list
10.Reversing the linked list
11.Sorting the linked list
12.Concating the linked list
13.Seprating the linked list
14.Merging the sorted linked list
15.Displaying the linked list
16.Quit

*/

// Header file
#include <stdio.h>
#include <stdlib.h>

// ADT
typedef struct node {
  int data;
  struct node *next;
} node;

// Function declaration
node *creation_and_initialization();
int counting_nodes(node *);
node *searching_element(node *, int);
node *insertion_of_node_at_the_beginning(node *);
node *insertion_of_node_at_the_given_position(node *, int);
node *insertion_of_node_at_the_end(node *);
node *deletion_of_node_at_beginning(node *);
node *deletion_of_node_at_given_position(node *, int);
node *deletion_of_node_at_end(node *);
node *reversing_the_linked_list(node *);
node *sorting_the_linked_list(node *);
node *concatinating_the_linked_list(node *, node *);
node *separating_the_linked_list(node *, int);
node *merging_the_sorted_linked_list(node *);
void display_linked_list(node *);

// Main Function
int main() {
  node *h, *t;                   // Declaring the node pointer
  int option, c, temp, position; // Declaring variables

  // Creation and initialization of Linked list
h = creation_and_initialization();

  // Menu
do {
    printf(
        "\nOperation of the linked list\n1.Counting the nodes of the linked "
        "list\n2.Searching the element form the linked list\n3.Insertion of "
        "node before the first node\n4.Insertion of node in the given "
        "position\n5.Insertion of node after the last node\n6.Removing first "
        "node from the linked list\n7.Removing node of given position form the "
        "linked list\n8.Removing last node from the linked list\n9.Reversing "
        "the linked list\n10.Sorting the linked list\n11.Concating the linked "
        "list\n12.Seprating the linked list\n13.Merging the sorted linked "
        "list\n14.Displaying the linked list\n15.Quit\n\nEnter your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      c = counting_nodes(h);
      printf("\nCouting of the nodes: %d\n", c);
      break;
    case 2:
      printf("\nEnter element to search: ");
      scanf("%d", &temp);
      h = searching_element(h, temp);
      printf("\n");
      break;
    case 3:
      h = insertion_of_node_at_the_beginning(h);
      printf("\n");
      break;
    case 4:
      printf("\nEnter position of the node: ");
      scanf("%d", &position);
      h = insertion_of_node_at_the_given_position(h, position);
      printf("\n");
      break;
    case 5:
      h = insertion_of_node_at_the_end(h);
      printf("\n");
      break;
    case 6:
      h = deletion_of_node_at_beginning(h);
      printf("\n");
      break;
    case 7:
      printf("\nEnter position of the node: ");
      scanf("%d", &position);
      h = deletion_of_node_at_given_position(h, position);
      printf("\n");
      break;
    case 8:
      h = deletion_of_node_at_end(h);
      break;
    case 9:
      h = reversing_the_linked_list(h);
      break;
    case 10:
      h = sorting_the_linked_list(h);
      break;
    case 11:
      t = creation_and_initialization();
      h = concatinating_the_linked_list(h, t);
      break;
    case 12:

      printf("Enter the position to obtained seprate linked list from: ");
      scanf("%d", &position);
      h = separating_the_linked_list(h, position);
      break;
    case 13:
      h = merging_the_sorted_linked_list(h);
      break;
    case 14:
      display_linked_list(h);
      break;
    }
  } while (option != 15);
}
// Function definition
node *creation_and_initialization() {
    node *head, *p;
    int size, i;
    head = (node *)malloc(sizeof(node));
    // Taking the element from the user
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);
    printf("Enter the head: ");
    scanf("%d", &(head->data));
    head->next = NULL;
    // Taking the element from the user
    p = head;
    for (i = 1; i < size; i++)
    {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
            p->next = NULL;
            printf("Enter the element %d: ", i + 1);
            scanf("%d", &(p->data));
    }
    return head;
}

int counting_nodes(node *head) {
    node *p;
    int c;
    p = (node *)malloc(sizeof(node));
    p = head;
    c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

node *searching_element(node *head, int temp) {
    node *p;
    int flag = 0;
    p = (node *)malloc(sizeof(node));
    p = head;
    while (p != NULL)
    {
        if (temp == p->data)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag)
    {
        printf("Element founded");
    }
    else
    {
        printf("Element not founded");
    }
    return head;
}

node *insertion_of_node_at_the_beginning(node *head)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    q = (node *)malloc(sizeof(node));
    q = head;
    printf("Enter data for the new node (before first node): ");
    scanf("%d", &(p->data));
    p->next = q;
    return p;
}

node *insertion_of_node_at_the_given_position(node *head, int position)
{
    node *p, *q;
    int c;
    p = head;
    c = 0;
    while (c != position - 2)
    {
        c++;
        p = p->next;
    }
    q = (node *)malloc(sizeof(node));
    printf("Enter data for the new node: ");
    scanf("%d", &(q->data));
    q->next = p->next;
    p->next = q;
    return head;
}

node *insertion_of_node_at_the_end(node *head)
{
    node *p, *q;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    q = (node *)malloc(sizeof(node));
    p->next = q;
    q->next = NULL;
    printf("Enter data for the new node (after last node): ");
    scanf("%d", &(q->data));
    return head;
}

node *deletion_of_node_at_beginning(node *head)
{
    node *p, *q;
    q = head;
    head = head->next;
    free(q);
    printf("\nNode remove");
    return head;
}

node *deletion_of_node_at_given_position(node *head, int position)
{
    node *p, *q, *t;
    int c = 0;
    p = head;
    while (c != position - 2)
    {
        c++;
        p = p->next;
    }
    printf("\nNode remove");
    q = p->next;
    t = q->next;
    p->next = t;
    free(q);
    return head;
}

node *deletion_of_node_at_end(node *head)
{
    node *p, *q;
    p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    free(q);
    printf("\nNode remove");
    return head;
}

node *reversing_the_linked_list(node *head)
{
    node *p, *q, *t;
    p = t = head;
    q = NULL;
    while (p != NULL)
    {
        p = p->next;
        t->next = q;
        q = t;
        t = p;
    }
    return q;
}

node *sorting_the_linked_list(node *head)
{
    node *p, *q;
    int temp;
    for (p = head; p->next != NULL; p = p->next)
    {
        q = p->next;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return head;
}

node *concatinating_the_linked_list(node *head1, node *head2)
{
    node *p, *h;
    int s, i;
    p = head1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head2;
    return head1;
}

node *separating_the_linked_list(node *head, int position)
{
    node *p, *h;
    int c = 0;
    p = head;
    while (c != position - 2)
    {
        c++;
        p = p->next;
    }
    h = p->next;
    p->next = NULL;
    p = head;
    display_linked_list(p);
    printf("\n");
    p = h;
    display_linked_list(p);
    printf("\n");
    return head;
}

node *merging_the_sorted_linked_list(node *head)
{
    node *p, *h, *q;
    q = creation_and_initialization();
    p = sorting_the_linked_list(head);
    q = sorting_the_linked_list(q);
    h = concatinating_the_linked_list(p, q);
    return h;
}

void display_linked_list(node *head)
{
    node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d ->", (p->data));
        p = p->next;
    }
}
