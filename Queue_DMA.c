// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int Data;
    int *Right;
};
struct Queue *Rear = NULL;
struct Queue *Front = NULL;

void insert(void);
void delete(void);
void display(void);
void main()
{
    int ch , len ;
    while(1)
    {
        printf("\n/**Queue operations**/\n");
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Display \n");
        printf("4.Quit \n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1    :    insert();
                                break;
            case 2    :    delete();
                                break;
            case 3    :    display();
                                break;
            case 4    :    exit(0);
            default   :    printf("Invalid choice....\n\n");
        }
    }
}
void insert()
{
    struct Queue *New;
    New = (struct Queue*)malloc(sizeof(struct Queue));
    printf("Enter Data : ");
    scanf("%d",&New->Data);
    New->Right =NULL;
    printf("\n");
    
    if(Front == NULL){
	Rear = New;
        Front=New;
    }
    else{
        Rear->Right = New;
        Rear = New;
    }

}
void delete(void)
{
	return 0;
}
void display(void)
{
	struct Queue *temp=Front;
	printf("\n------------\n  Display Queue\n------------\n");
	while(temp!=NULL){
	printf("%d")
}
