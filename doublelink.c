#include <stdio.h>
#include<stdlib.h>

struct Node{
	int Data;
	struct Node *pre;
	struct Node *next;

};
struct Node*root;
void main()
{
	struct Node *One;
	struct Node *Two;
	struct Node *Three;
// Memory Allocation of Node
One = (struct Node *)malloc(sizeof(struct Node));
Two = (struct Node *)malloc(sizeof(struct Node));
Three = (struct Node *)malloc(sizeof(struct Node));

//Assign Data
One->Data =11;
Two->Data=21;
Three->Data=31;

//Connect Node
One->pre = NULL;
One->next = Two;

Two->pre = One;
Two->next = Three;

Three->pre = Two;
Three->next = NULL;

//
root = One;	


printf("The Data Node is\n");
struct Node *p=root;
while(p!=NULL)
{
	printf("%d\n",p->Data);
	p=p->next;
}
	
}
