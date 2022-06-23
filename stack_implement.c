//Header Files 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define VAL -1

void Push(void);
void Pop(void);
void Display(void);
void Peek(void);
int IsFull(void);
int IsEmpty(void);


int stack[SIZE];
int top = VAL;

int main()
{
	int ch;
	while(1){
		printf("1. Adding Data.(PUSH)\n");
		printf("2. Delete Data.(POP)\n");
		printf("3. Display Data.(DISPLAY)\n");
		printf("4. Last Value.(PEEK)\n");
		printf("5. Quit\n");

		printf("Enter Your Choice :");
		scanf("%d",&ch);

		switch(ch){
		
			case 1: Push();
				break;
	
			case 2: Pop();
				break;
	
			case 3: Display();
		       		break;
			
			case 4: Peek();
				break;

			case 5:	exit(1);

			default : printf("Invalide Choice..!!\n");		
		}
	}

return 0;
}
int IsFull(void)
{
	if(top==(SIZE-1)){
		return 1;
	}
	else{
		return 0;
	}	
}
int IsEmpty(void)
{
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void Push(void)
{
	if(IsFull()){
		printf("Stack is Full\n\n");
	}
	else{
		int ele;
		printf("Enter the Elements :");
		scanf("%d",&ele);
		printf("Element \"%d\" is Pushed Successfully\n\n",stack[++top]=ele);
	}
}
void Pop(void)
{
	if(IsEmpty()){
		printf("Stack is Empty\n\n");
	}
	else{
		printf("Stack is pop : %d\n\n",stack[top--]);

	}
}
void Display(void)
{
	if(IsEmpty()){
		printf("Stack is Empty\n\n");
	}
	else{
	int i;
	printf("\n--------------------\nDisplay Stack\n--------------------\n");
	for(i=top;i>=0;i--)
		printf("%d\t",stack[i]);
	printf("\n\n");
	}
}
void Peek(void)
{
	if(IsEmpty()){
		printf("Stack is Empty\n\n");
	}
	else{
		printf("Peek Value is :%d\n\n",stack[top]);
	}

}
