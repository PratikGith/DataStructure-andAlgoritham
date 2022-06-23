/*
Name:pratik_prajapati.
Task : All functions of single_linked_list
Sub: DS
*/

#include <stdio.h>
#include <stdlib.h>

struct node{

	int data;
	struct node*link;

};
struct node *root=NULL;

void create();
void append(); 
int length();
void add_first();
void add_middle();
void remove_first();
void remove_middle();
void remove_last();
void search();
void swap_node();
void Display(); 	

void main()
{
	int len,choice;
//	create();

	while(1)
	{
		printf("1. Display \n");
		printf("2. Length \n");
		printf("3. append \n");
		printf("4. add_first \n");
		printf("5. add_middle \n");
		printf("6. remove_first \n");
		printf("7. remove_middle \n");
		printf("8. remove_last \n");
		printf("9. swap_node \n");
		printf("10. search \n");
		printf("11. Quit \n");
	

		printf("Enter your choice:\n");
		scanf("%d",&choice);

	switch(choice)
	{
		case 1: Display();
			break;
		case 2: len=length();
			printf("Length=%d :\t",len);
			break;
		case 3: append();
			break;
		case 4: add_first();
			break;
		case 5: add_middle();
			break;
		case 6: remove_first();
			break;
		case 7: remove_middle();
			break;
		case 8: remove_last();
			break;
		case 9: swap_node();
			break;
		case 10: search();
			 break;
		case 11: exit(1);
		default: printf("Invalid choice :\n");
	}
	}
	

}
/*
void create()
{

	struct node *temp,*last;
	while(1)
	{
	temp=(struct node *)malloc(sizeof(struct node *));
	printf("Enter elements of node data :\n ");
	scanf("%d",&temp->data);

	if(root==NULL)
	{
		root=temp;
		last=temp;
	
	}
	else
	{
		last->link=temp;
		last=temp;
	}

	printf("Do you Enter more nodes? (y/n) :\n");
	if('n'=='n'||"no"=="no")
	{
		last->link=NULL;
		break;
	}
	}

}
*/
int length()
{
	
	int count=0;
	struct node *p=root;
		while(p!=NULL)
		{
			count++;
			p=p->link;
	
		}
return count;
}
void display()
{
	if(root==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
	struct node*p=root;
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			p=p->link;
		}
	}

}

void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));

	printf("Enter the node elemets :\n");
	scanf("%d",&temp->data);
	temp->link=NULL;

	if(root==NULL)
		root=temp;
	else
	{
		struct node *last;
		last=root;
		while(last->link!=NULL)
		{
			 last=last->link;
		}
		last->link=temp;

	}

}
void add_first()
{
	struct node*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter new node data:\n");
	scanf("%d",&temp->data);

	temp->link=root;	//1-right_side_connection
	root=temp;		//2- Left_side_connection

}
void add_middle()
{
	int len,loc,i=1;
	struct node *temp,*p;
	printf("Enter the location:\n");
	scanf("%d",&loc);

	len=length();
	if(loc>len)
		{
			printf("Invalid location :");
			printf("Length is =%d\n",len);
		}

	p=root;
	while(i<loc)
		{
			p=p->link;
			i++;
		
		}
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter new node data :\n");
	scanf("%d",&temp->data);

		 temp->link=p->link;  	
		  p->link=temp;
}

void remove_first()
{
	struct node *temp=root;

	root=root->link;
	temp->link=NULL;
	
		free(temp);

}
void remove_middle()
{
	struct node *p,*q;
	int len,loc,i=1;

	printf("Enter the location:\n");
	scanf("%d",&loc);

	len=length();		//suppose len=5
	if(loc>len)
	{
		printf("Invalid location\n");
		printf("Total lenth is =%d\n",len);
	}
	
	p=root;		//1000
	while(i<loc) 	
	{
		p=p->link;
		i++;
	
	}
	q=p->link;		//suppose p=3000,q=40000
	p->link=q->link;
	q->link=NULL;		//if it's last node, no need to this statement
		
		free(q);

}
void remove_last()
{

	struct node *p,*q;
	int len,loc,i=1;

	printf("Enter location:\t");
	scanf("%d",&loc);

	len=length();
	if(loc>len)
	{
		printf("Invalid location\n");
		printf("length=%d\n",len);
	}
	p=root;
	while(i<loc)
	{
		p=p->link;
		i++;

	}
	q=p->link;
	p->link=q->link;
	//q->link=NULL;
	free(q);
}
void search()
{
	int ele,c=0;
	struct node *p=root;

	printf("Enter elements :");
	scanf("%d",&ele);

	while(p!=NULL)
	{
		if(p->data==ele)
		{
			c++;
			break;
		}
		p=p->link;
	
	}

	if(c)
		printf("element is found\n");
	else
		printf("element is not found\n");

}
void swap_node()
{
	int l1,l2,i=1,j=1,t,len;
	struct node *p,*q;

	printf("Enter swap locations no:\n");
	scanf("%d %d",&l1,&l2);

	len=length();
	if(l1>len||l2>len)
	{
		printf("Location is bigger to length\n");
		printf("length=%d\n",len);
	}

	p=q=root;
	
	while(i<l1)
	{
		p=p->link;
		i++;
	}
	while(j<l2)
	{
		q=q->link;
		j++;
	}

	//swapping logic

	t=p->data;
	p->data=q->data;
	q->data=t;


}	

void Display()
{
	struct node *p;
	if(p==NULL)
		printf("List is empty\n");
	else
	{
		p=root;
		while(p!=NULL)
			{
				printf("%d\n",p->data);
				p=p->link;
			
			}
	}
}


