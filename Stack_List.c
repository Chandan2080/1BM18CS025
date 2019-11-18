#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node* NODE;
NODE getnode(){
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
}
NODE push(NODE head,int item,int *t){
	NODE p;
	p=getnode();
	p->data=item;
	if(head==NULL){
		p->next=NULL;
		head=p;
		(*t)++;
		return head;
	}
	else{
		p->next=head;
		head=p;
		(*t)++;
		return head;
	}
}
NODE pop(NODE head)
{
	NODE p;
	int item;
	if(head==NULL){
		printf("Stack undreflow\n");
		return head;
	}
	item=head->data;
	p=head;
	head=head->next;
	free(p);
	printf("Deleted element is %d\n",item);
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL){
		printf("Empty\n");
		return;
	}
    p=head;
	printf("Elements in stack are\n");
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}
int main()
{
	NODE head = NULL;
	int ch, ele, top = -1;
	do{
	    printf("\n\n1 : Push an element");
	    printf("\n2 : Pop an element");
	    printf("\n3 : Display all the elements");
	    printf("\n4 : EXIT");
	    printf("\nEnter your choise:\t");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1: printf("Enter element to be inserted\n");
			        scanf("%d",&ele);
			        head = push(head,ele,&top);
				    break;
			case 2: head = pop(head);
				    break;
			case 3: display(head);
				    break;
			case 4: exit(0);
			default: printf("\nInvalid choise!!");
		}
	}while(ch!=0);
	return 0;
}
