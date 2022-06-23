// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int Data;
    struct Node*link;
};
struct Node *root=NULL;

void Display(void);
void Append(void);
int Length(void);
void Add_First(void);
void Add_Middle(void);
void Delete_First(void);
void Delete_Middle(void);
void swapping_node(void);
int main() {
    // Write C code here
    int len=0,ch=0;
    
    while(1){
        printf("1. Display Output\n");
        printf("2. Append Data\n");
        printf("3. Length\n");
	printf("4. Add First Node\n");
	printf("5. Add Middle Node\n");
	printf("6. Delete First Node\n");
	printf("7. Delete Middle Node\n");
	printf("8. Swapping Nodes\n");
        printf("9. Quit\n");
        
        printf("Enter your choice :");
        scanf("%d",&ch);
        
        switch(ch){
            case 1 : Display();
		     printf("\n----------\n");
                        break;

            case 2 : Append();
		     printf("\n----------\n");
                        break;

            case 3 : len=Length();
                     printf("\nLength = %d\n",len);
		     printf("\n----------\n");
                        break;

	    case 4 : Add_First();
		     printf("\n----------\n");
			break;

   	    case 5 : Add_Middle();
		     printf("\n----------\n");
			break;

   	    case 6 : Delete_First();
		     printf("\n----------\n");
			break;
   	    case 7 : Delete_Middle();
		     printf("\n----------\n");
			break;
   	    case 8 : swapping_node();
		     printf("\n----------\n");
			break;
            case 9 : exit(1);
           default : printf("Invalid Input\n");
            
        }
    }
    return 0;
}

void Display(void)
{
    struct Node*list=root;
    if(root==NULL)
    {
        printf("List Is Empty\n");
    }
    else{
    printf("\n-----------\nDisplay Data\n------------\n");    
    while(list!=NULL){
        printf("%d\n",list->Data);
        list=list->link;
        }
        printf("\n------------\n");
    }
}
void Append(void)
{
    struct Node *NewNode;
    NewNode = (struct Node*)malloc(sizeof(struct Node));
    printf("ENTER DATA :");
    scanf("%d",&NewNode->Data);
    NewNode->link =NULL;
    
    if(root == NULL)
    {
        root = NewNode;
    }
    else
    {
        struct Node*last=root;
        while((last->link)!=NULL){
            last=last->link;
        }
        last->link=NewNode;
    }
}
int Length(void)
{
   int count=0;
   struct Node*p=root;
   while(p!=NULL)
   {
   	++count;
	p=p->link;
   }
  return count; 
}

void Add_First(void)
{
	struct Node *temp;
	temp= (struct Node*)malloc(sizeof(struct Node));
	printf("Add at First Data :\n");
	scanf("%d",&temp->Data);
	temp->link=NULL;

	if(root==NULL)
	{
		printf("There is no Data is Present\n");
	}
	else
	{
		temp->link=root;
		root=temp;
	}
	

}
void Add_Middle(void )
{
	int i=1,loc,len;
	struct Node *temp,*p;
	
	printf("Enter the Location when you are add Node: ");
	scanf("%d",&loc);
	printf("\n");
	len=Length();

	if(loc>len){
		printf("INVALIDE LOCATION  !!!\nLocation is out of Range\n");
		printf("Total Length is :%d\n",len);
	}
	else{
	temp=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the Data :");
	scanf("%d",&temp->Data);
	printf("\n");
	temp->link=NULL;
	
	p=root;
	while(i<loc){
		p=p->link;
		++i;
	}
		temp->link=p->link; // right side connection 
		p->link = temp;  // Left Side connection 2nd


	}

}

void Delete_First(void)
{
      struct Node*temp=root;
      root = root->link;
      temp->link = NULL;

      free(temp);
}
/*
void Delete_Middle()
{
	struct Node *p,*q;
	int len,loc,i=1;

	printf("Enter the location:\n");
	scanf("%d",&loc);

	len=Length();		//suppose len=5
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
*/
void Delete_Middle(void)
{
     struct Node *p=root,*q;
     int i=1,loc=0,len=0;
     printf("Enter Delete node location :");
     scanf("%d",&loc);
     printf("\n");

     len = Length();
   if(loc>len){
      printf("Location is Bigger then Length..\nPlease! Add Proper Location\n");
      printf("Length = %d\n",len);

   }
   else{
   	while(i<loc-1){
           p=p->link;
             i++;
   	}

  	q = p->link;
	//Logic
		p->link = q->link;
		q->link = NULL;

	free(q);
	}
}
void swapping_node()
{
	struct Node *p=root,*q=root;
	int i=1,j=1,loc1=0,loc2=0;
	int temp=0;

	printf("Enter the Swapping Location\n Please! Enter Location1 and Location2\n");
	scanf("%d%d",&loc1,&loc2);
	int len=Length();
	if((loc1>len)||(loc2>len))
	{
		printf("Invalide Location\n");
		printf("Length = %d\n",len);
	}
	else
	{
		while(i<loc1){
			p = p->link;
			i++;
		}
		while(j<loc2){
			q = q->link;
			j++;
		}
		
	// Swapping Logic
		temp = p->Data;
		p->Data = q->Data;
		q->Data = temp;
	
	}

}




































