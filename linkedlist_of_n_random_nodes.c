/*Creating a linkedlist of n nodes and each node values are random values from some given range and then searching a particular element is in the linked_list or not.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int data;
	struct node *link;
};
typedef struct node Node;

Node* create_node(int a)
{
	Node *current;
	current = (Node*) malloc(sizeof(Node));
	current -> data = a;
	current -> link = NULL;
	return current;
}

int Random(int lower, int upper)
{ 
		int num = (rand() % (upper - lower + 1)) + lower;
		return num;
}

int main()
{
	int i,n,a,b,lower,upper,num;
	Node *head,*current_node,*previous_node;
	printf("enter number of nodes you want in the linked list\n");
	scanf("%d",&n);
	printf("Enter the lower limits of random values from where data values of the linked_list are chosen \n");
	scanf("%d",&lower);
	printf("Enter the upper limits of random values from where data values of the linked_list are chosen \n");
	scanf("%d",&upper);
	srand(time(0));
	for(i = 0;i < n;i++)
	{
		num = Random(lower, upper); 
		printf("The random number at %dth node is %d\n",i+1,num);
		current_node = create_node(num);
		if(i == 0)
			head = current_node;
		if(i != 0)
			previous_node -> link = current_node;
		previous_node = current_node;	 	
	}
	
	printf("The created linked_list is .... \n");
	printf("\n");
	current_node = head;
	i = 0;
	while(current_node -> link != NULL)
	{
		
		printf("Data value at the %dth node is = %d\n",i+1,current_node -> data);
		printf("Address of the value at the %dth node is %p\n",i+1,&current_node -> data);
		printf("Address at the %dth node is = %p\n",i+1,current_node -> link);
		printf("\n");
		current_node = current_node -> link;
		i++;
	}
	printf("Data value at the %dth node is = %d\n",n,current_node -> data);
	printf("Address at the %dth node is = %p\n",n,current_node -> link);
	printf("\n");
	
	printf("Enter the number which you want to search in above linked_list \n");
	scanf("%d",&b);
	current_node = head;
	i = 0; 
	while(current_node -> link != NULL)
	{
		if(current_node -> data == b)
		{
			printf("%d is present in the linked_list  and it is at the %dth node of the Linked_list \n",b,i+1);
			break;
		}	
		current_node = current_node -> link;
		i++;
	}
	if(current_node -> data == b && current_node -> link == NULL )
		printf("%d is present in the linked_list  and it is at the %dth node of the Linked_list \n",b,n);
	if(current_node -> data != b && current_node -> link == NULL)
		printf("%d is  not present in the link_list \n",b);
		
	return 0;
}
