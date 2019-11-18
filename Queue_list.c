#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node{
	int data;
	struct node *next;
};
typedef struct node* NODE;
NODE getnode(){
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else{
		printf("No memory allocation\n");
		exit(0);
	}
}
NODE insert(NODE head,int item){
	NODE p, q=head;
	p = getnode();
	p->data = item;
	if(head == NULL){
		p->next = NULL;
		head = p;
		return head;
	}
	else{
		q=head;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
		return head;
	}
}
NODE delete(NODE head)
{
	NODE p;
	int item;
	if(head==NULL){
		printf("Undreflow\n");
		return head;
	}
	else{
		item=head->data;
		p=head;
		head=head->next;
		free(p);
		printf("Deleted element is %d\n",item);
		return head;
	}
}
void display(NODE head)
{
	NODE p;
	if(head == NULL)
	{
		printf("Empty Queue\n");
	}
	else{
	    p=head;
	    printf("Elements in Queue are\n");
	    while(p!=NULL)
	    {
    		printf("%d\n",p->data);
    		p=p->next;
	    }
	}
}
int main()
{
	NODE head=NULL;
	int ch,ele;
	do{
	    printf("\n\n1 : Insert an element");
	    printf("\n2 : Delete an element");
	    printf("\n3 : Display all the elements");
	    printf("\n4 : EXIT");
	    printf("\nEnter your choise:\t");
	    scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter element to be inserted\n");
				    scanf("%d",&ele);
			    	head=insert(head,ele);
				    break;
			case 2: head=delete(head);
				    break;
			case 3: display(head);
				    break;
			case 4: exit(0);
			default:printf("\nInvalid choise!!");
		}
	}while(ch!=4);
	return 0;
}
