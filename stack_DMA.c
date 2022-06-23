#include <stdio.h>
#include <stdlib.h>

int isEmpty(void);
int isFull(void);
void CreateStack(void);
void Push(void);
void Pop(void);
void Display(void);

int Size,curr,*top,*stack;
int main()
{
	int ch,ele;
	CreateStack();

	while(1){
		printf("1. Push.\n");
		printf("2. Pop.\n");
		printf("3. Display\n");
		printf("4. Quit.\n");

		printf("Enter your Choice :");
		scanf("%d",&ch);

		switch(ch){
			case 1: Push();
				break;

			case 2: Pop();
				break;

			case 3: Display();
				break;

			case 4: exit(1);
			default : printf("Invalide Option\n");	
		
		}
	}

return 0;
}
void CreateStack()
{
	
	printf("How many Stack you emplements? \nEnter Size of Stack :");
	scanf("%d",&Size);
	curr=Size;
	stack = (int *)malloc(sizeof(int)*Size); // 4Bytes * 5 = 20 Bytes DMA mem. allocated
	if(stack==NULL){
		printf("\nstack creation is failed\n");
		exit(0);
	}
	else
		top=stack;

}

int isEmpty(void)
{
	if(top==stack)
		return 1;
	else
		return 0;
}
int isFull(void)
{
	if(stack==NULL)
		return 1;
	else
		return 0;
}

void Push(void)
{
	int ele;
	printf("Enter the Elements:");
	scanf("%d",&ele);
	if(top==stack+curr){
		++curr;
		stack=(int *)realloc(stack,curr*sizeof(int));

		if(isFull()){
			printf("Stack is Full\n\n");
		}
		else{
			*top=ele;
			top++;
			printf(" %d Element Inserted...\n\n",ele);
		}
	}
	else{
		*top=ele;
		top++;
		printf("\nElement pushed...\n");
	}

}
void Pop(void)
{
	if(isEmpty()){
		printf("Stack is Empty..\n\n");
	}
	else{
		top--;
		printf("Elemet is Poped : %d\n\n",*top);
		if(curr>Size){
			--curr;
			stack=(int *)realloc(stack,curr*sizeof(int));
		
		}
	}
}

void Display(void)
{
	if(isEmpty()){
		printf("stack is empty...\n\n");
	}
	else{
	int *i;
	printf("\n----------------\n  Display Stack\n----------------\n");
	for(i=top-1;i>=stack;i--)
		printf("%d\t",*i);
	printf("\n\n");

	}
}	


