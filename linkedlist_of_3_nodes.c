#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int main()
{
	struct node *head;
	struct node *current;

	head = (struct node*) malloc(sizeof(struct node));
	head -> data = 1;
	head -> link = NULL;
	printf("After creating the fast node value of the data is = %d\n",head -> data);
	printf("Address of the first node at first is = %p\n",head -> link);
	
	current = (struct node*) malloc(sizeof(struct node));
	current -> data = 2;
	current -> link = NULL;
	head -> link = current;
	printf("After creating the second node value of the data is = %d\n",current -> data);
	printf("Address of the second node at first is = %p\n",current -> link);
	printf("Address of the first node after creating the second node is = %p\n",head -> link);
	
	current = (struct node*) malloc(sizeof(struct node));
	current -> data = 3;
	current -> link = NULL;
	head -> link ->link = current;
	printf("After creating the third node value of the data is = %d\n",current -> data);
	printf("Address of the third node at first is = %p\n",current -> link);
	printf("Address of the second node after creating the  third node is = %p\n",head -> link -> link);
	
	return 0;
}
