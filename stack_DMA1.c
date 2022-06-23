#include<stdio.h>
#include<stdlib.h>

struct Node{
	int Data;
	struct Node *link;

}*top=NULL;
#define MAX 5

void push(void);
void pop(void);
int isEmpty(void);
int isFull(void);
void display(void);
int st_count(void);
void peek(void);
void stack_destroy(void);

int main()
{
	int ch;
	while(1){

		printf("1. push an element\n");
		printf("2. pop an element\n");
		printf("3. Display & count an elements\n");
		printf("4. Print top of the stack\n");
		printf("5. destroy stack\n");
		printf("6. Quit\n");
	
		printf("Enter your choice :");
		scanf("%d",&ch);

		switch(ch){
			
			case 1: push();
				break;

			case 2: pop();
				break;

			case 3: display();
				break;

			case 4: peek();
				break;

			case 5: stack_destroy();
				break;
			
			case 6: exit(1);
			default : printf("Invalide! choice\n\n");	
		
		}
	}
return 0;
}
void push(void)
{
	int ele;
	struct Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value which you want to push into the stack : ");
	scanf("%d",&ele);

	if(isFull())
		printf("stack is full\n\n");
	else{
		temp->Data=ele;
		temp->link=top;
		top=temp;
	}	
}
void pop(void)
{
	struct Node *temp;
	if(isEmpty())
		printf("stack is empty\n\n");
	else{
		temp=top;
		printf("Value popped out is : %d\n\n",temp->Data);
		top=top->link;

		free(temp);
	}
}
void display(void)
{
	int c=0;
	struct Node *temp;
	if(isEmpty())
		printf("stack is empty\n\n");
	else
	{
		printf("\n-------------------\n  Display Elements\n-------------------\n");
		temp=top;
		while(temp!=NULL){
			printf("%d\t",temp->Data);
			temp=temp->link;
			c++;
		}
		printf("\nLength of stack is : %d\n\n",c);
	}


}
void peek(void)
{
	if(isEmpty())
		printf("stack is empty\n\n");
	else
		printf("Top value of stack is : %d\n\n",top->Data);
}
void stack_destroy(void)
{
	struct Node *temp;
	temp=top;
	while(temp!=NULL){
		temp=top;
		printf("Value popped out is : %d\n\n",temp->Data);
		top=top->link;
		temp=temp->link;
	}
	free(temp);
	printf("\n\nSTACK IS DESTROY\n\n");
}
int st_count(void)
{
	int c=0;
	struct Node*temp=top;
	while(temp!=NULL){
		temp=temp->link;
		c++;
	}
	return c;
		
}
int isEmpty(void)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
int isFull(void)
{
	int count =0;
	count = st_count();
	if(count==MAX)
		return 1;
	else
		return 0;
}
