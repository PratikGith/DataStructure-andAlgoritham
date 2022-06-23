#include <stdio.h>
#include <stdlib.h>

struct Node {

	int Data;
	struct Node *left;
	struct Node *right;
};

struct Node *root = NULL;

void Append(void);
void Display(void);
int Length(void);
void Add_First(void);
void Add_Middle(void);
void Delete_First(void);
void Delete_Middle(void);
void Swapping_Node(void);

int main()
{
	int len=0,ch=0;

	while(1){
		printf("1. Append Node\n");
		printf("2. Display NodeData\n");
		printf("3. Length\n");
		printf("4. Add Node at First\n");
		printf("5. Add Node at Middle / Last\n");
		printf("6. Delete First Node\n");
		printf("7. Delete Middle / Last Node\n");
		printf("8. swapping Node\n");
		printf("9. Quit\n");

		printf("Enter your choice :");
		scanf("%d",&ch);

		switch(ch){
			case 1: Append();
				break;
			case 2: Display();
				break;
			case 3: len = Length();
				printf("Length = %d\n\n",len);
				break;
			case 4: Add_First();
				break;
			case 5: Add_Middle();
				break;
			case 6: Delete_First();
				break;
			case 7: Delete_Middle();
				break;
			case 8: Swapping_Node();
				break;		
			case 9: exit(1);
			default : printf("Invalide Choice\n");		 
		}
	}

return 0;
}
void Append(void){
	struct Node*temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter Node data :");
	scanf("%d",&temp->Data);
	printf("\n");
	temp->left = NULL;
	temp->right = NULL;


	if(root == NULL){
		root=temp;
	}
	else{
		struct Node *p = root;
		while((p->right)!=NULL){
			p=p->right;
		}

		p->right=temp;
		temp->left=p;
	}
}
int Length(void)
{
	int count=0;
	struct Node *p=root;
	while(p!=NULL){
		count++;
		p=p->right;
	}
	return count;
}
void Display(void){
	struct Node *p=root;
	if(root==NULL){
		printf("\nList is Empty\n");
	}
	else{
		printf("\n------\nDISPALY DATA\n------\n");
		while(p!=NULL){
			printf("%d\n",p->Data);
			p=p->right;
		}
	}
	printf("\n");
}
void Add_First(void){
	struct Node*temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("\nENTER THE FIRST NODE DATA :");
	scanf("%d",&temp->Data);
	printf("\n");

	temp->right = NULL;
	temp->left = NULL;

	if(root == NULL)
	{
		printf("There is no Nodes in list\n");
		root=temp;
	}
	else
	{
		temp->right = root;
		root=temp;
	}
}

void Add_Middle(void){
	struct Node *temp, *p=root;
	int loc=0,len=0,i=1;

	
	printf("\nPlease! Enter Your Adding Node Location\n");
	scanf("%d",&loc);
	len=Length();
	if(loc>len){
		printf("Invalide Choice !!\n Location is not Present\n");
		printf("Length = %d\n",len);
	}
	else{
		temp=(struct Node*)malloc(sizeof(struct Node));
		printf("\nENTER NODE DATA :");
		scanf("%d",&temp->Data);
		printf("\n");

		temp->right = NULL;
		temp ->left = NULL;
		
		while(i<loc-1){
		
			p = p->right;
			i++;
		}
		//Right Side Connections
		temp->right = p->right;
		p->right->left = temp;

		//Left side connections 
		temp->left = p;
		p->right = temp;	
	}

}
void Delete_First(void){
	struct Node*p=root;
	root = root->right;
	p->right->left = NULL;
	p->right = NULL;
	
	free(p);

}
void Delete_Middle(void){
	struct Node*p=root,*q;
	int i=1,loc=0,len=0;
	printf("Which Location you Delete? Enter Location :");
	scanf("%d",&loc);
	printf("\n");

	len=Length();
	if(loc>len){
		printf("Location is Bigger than length\n");
		printf("Length = %d\n",len);
	}
	else{
		while(i<loc-1){
			p=p->right;
			i++;
		}
		q=p->right;
		// Logic
		  p->right = q->right;
		  q->right->left = p;
		  q->left = NULL;
		  q->right = NULL;

		  free(q);
	}
}
void Swapping_Node(void){

	struct Node*p=root,*q=root;
	int i=1,j=1,loc1=0,loc2=0,len=0,temp=0;

	printf("Enter Swapping Node. Node1 & Node2\n");
	printf("Location 1 = ");
	scanf("%d",&loc1);
	printf("\nLocation 2 = ");
	scanf("%d",&loc2);

	len=Length();
	if((loc1>len)||(loc2>len)){
		printf("Invalide Location\n");
		printf("Length =%d\n",len);
	}
	else{
		while(i<loc1){
			p=p->right;
			i++;
		}
		while(j<loc2){
			q=q->right;
			j++;
		}

		temp = p->Data;
		p->Data = q->Data;
		q->Data = temp;
	
	}

	

}
