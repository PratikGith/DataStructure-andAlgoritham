#include <stdio.h>
#include <stdlib.h>

void Append();
int Length();
void Display();

struct Node {
	int Data;
	struct Node *link;

};
struct Node *root = NULL;

int main()
{
	int ch=0,len=0;

	while(1){
		printf("1. Append\n");
		printf("2. Length\n");
		printf("3. Display\n");
		printf("4. Quit\n");

		printf("Enter your Choice :");
		scanf("%d",&ch);

		switch(ch){
			case 1 : Append();
				break;
			case 2 : len=Length();
				printf("Length is : %d\n",len);
				break;
			case 3 : Display();
				break;
			case 4 : exit(1);
		        default: printf("Invalide Outout Choice\n");
	
		}
	}

return 0;
}

void Append()
{
	struct Node *new=NULL;
	new = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the data\n");
	scanf("%d",&new->Data);
	new->link=NULL;

	if(root==NULL){
		root=new;
	}
	else{
		struct Node *last=root;
		while(last->link!=NULL)
			last=last->link;
			last->link=new;
	
	}

}
int Length()
{
	int count=0;
	struct Node *node=root;
	while(node!=NULL)
	{
		++count;
		node=node->link;
	}
	return count;
}
void Display()
{
	if(root==NULL){
		printf("List is Empty!!\n");
	}
	else{
		struct Node *node=root;
		printf("\nList of Elements\n------------------------\n");
		while(node!=NULL){
			printf("%d\n",node->Data);
			node=node->link;
		
		}
	}
	

}

