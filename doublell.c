#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
	struct node * prev;
};
typedef struct node * NODE;
NODE getnode(){
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else{
		printf("Memory error!!\n");
		exit(0);
	}
}
NODE insert(NODE head, int item){
    NODE p;
    p = getnode();
    p->data = item;
    if(head == NULL){
        p->next = NULL;
        p->prev = NULL;
        head = p;
        return p;
    }
    p->next = head;
    head->prev = p;
    p->prev = NULL;
    head = p;
    return head;
}
void display(NODE head)
{
    NODE p = head;
    if(head == NULL)
        printf("List is empty\n");
    else{
        printf("Elements in list are:\n\t");
        while(p!=NULL){
            printf("%d\t",p->data);
            p = p->next;
        }
    }
}
NODE delete(NODE head, int item)
{
    NODE p = head;
    NODE q;
    //CASE 1:
    if(head == NULL){
        printf("\nList is empty!!");
        return head;
    }
    //CASE 2:
    if(head->next == NULL){
        if(head->data == item)
        {
            head = head->next;
            free(p);
            head->prev = NULL;
            return head;
        }
        else{
            printf("\nValue doesnt exist!!");
            return head;
        }
    }
    //CASE 3:
    q = head;
    if(head->data == item){
        head = head->next;
        free(p);
        head->prev = NULL;
        return head;
    }
    //CASE 4:
    while(q->next != NULL){
    	p = q;
        q = q->next;
        if(q->data == item){
            p->next = q->next;
            q->next->prev = q->prev;
            free(q);
            return head;
        }
    }
    if(q->next == NULL){
        printf("Value does not exist!!\n");
        return head;
    }
}
NODE insert_left(NODE head,int num,int item)
{
    NODE p, q, temp;
    p = getnode();
    p->data = item;
    if(head == NULL){
        printf("Value can not be inserted!!!!");
        return head;
    }
    if(head->data == num){
        p->next = head;
        head->prev = p;
        p->prev = NULL;
        head = p;
        return head;
    }
    q = head;
    while(q->next != NULL){
    	temp = q;
        q = q->next;
        if(q->data == num){
        	temp->next = p;
            p->prev = temp;
            p->next = q;
            q->prev = p;
            return head;
        }
	}
	if(q->next == NULL){
        printf("Given node value does not exist!!");
        return head;
    }
}
int main(){
	NODE head = NULL;
	int ch, ele, ele1;
	do{
		printf("\n\n1 : Insert an element at the front");
		printf("\n2 : Insert to the left of an element");
		printf("\n3 : Delete a specific value from the list");
		printf("\n4 : Display all the contents of the list");
		printf("\n5 : EXIT");
		printf("\nEnter your choise:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the element to be inserted:\t");
					scanf("%d",&ele);
					head = insert(head, ele);
					break;
			case 2: printf("Enter the element to be inserted:\t");
					scanf("%d",&ele);
					printf("Enter the element to which you want to insert an element to the left:\t");
					scanf("%d",&ele1);
					head = insert_left(head, ele1, ele);
					break;
			case 3: printf("Enter the element to be deleted:\t");
					scanf("%d",&ele);
					head = delete(head, ele);
					break;
			case 4: display(head);
					break;
			case 5: printf("EITING FROM THE PROGRAM!!");
					exit(0);
					break;
			default:printf("Invalid Input!!!");
		}		
	}while(ch!=5);
	return 0;
}
