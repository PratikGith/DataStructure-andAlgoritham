//Define Header Files
#include <stdio.h>
#include <stdlib.h>
//Define Macros
#define CAPACITY 5

//Define Functions
int isFull(void);
int isEmpty(void);
void EnQueue(void);
void DeQueue(void);
void Display(void);

//Define variables 
int Front=-1,Rear=-1;
int Queue[CAPACITY];
void main()
{
	int choice;
	while(1){
	printf("\n1. Enqueue.\n2. Dequeue.\n3. Display.\n4. Exit\n");
	printf("Enter your choice :");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: EnQueue();
			break;
		case 2: DeQueue();
			break;
		case 3: Display();
			break;	
		case 4: exit(1);
		default: printf("Invalide Choice\n");
	}
	}
}

int isFull(void)
{
	if(Rear==(CAPACITY-1))
		return 1;
	else
		return 0;

}
int isEmpty(void)
{
	if(Front==Rear)
		return 1;
	else
		return 0;

}
void EnQueue(void)
{
	int ele=0;
	if(isFull())
		printf("Queue is Full\n");
	else{
		printf("Enter EnQueue Data:");
		scanf("%d",&ele);
		printf("\n");

		Queue[Rear] = ele;
		Rear++;
	}
}
void DeQueue(void)
{
	if(isEmpty())
		printf("Queue is Empty\n");
	else{
		int i;
		printf("DeQueue is : %d\n",Queue[Front]);
		for(i=Front;i<Rear-1;i++)
			Queue[i]=Queue[i+1];
		Rear--;
	}
}

void Display(void)
{
	if(isEmpty())
		printf("Queue is Empty\n");
	else{
		int i;
		printf("\n----------\nQueue\n----------\n");
		for(i=Front;i<Rear;i++)
				printf("%d\t",Queue[i]);
		printf("\n\n");		
	}

}
