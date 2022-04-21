#include<stdio.h>
#include<stdlib.h>

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
int main()
{
	int i,n,a;
	Node *head,*current_node,*previous_node;
	printf("enter number of nodes you want in the linked list\n");
	scanf("%d",&n);
	printf("Enter the values for nodes\n");
	
	for(i = 0;i < n;i++)
	{
		printf("Enter the %dth value :\n",i+1); 
		scanf("%d",&a);
		current_node = create_node(a);
		if(i == 0)
			head = current_node;
		if(i != 0)
			previous_node -> link = current_node;
		previous_node = current_node;	 	
	}
	
	printf("The linked list you want to create is \n");
	printf("\n");
	current_node = head;
	i=0;
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
	return 0;
}
