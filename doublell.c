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
int main(){
	NODE head = NULL;
	int ch, ele;
	do{
		printf("\n\n1 : Insert an element to the left");
		printf("\n2 : Delete a specific value from the list");
		printf("\n3 : Display all the contents of the list");
		printf("\n4 : EXIT");
		printf("\nEnter your choise:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the element to be inserted:\t");
					scanf("%d",&ele);
					head = insert(head, ele);
					break;
			case 2: printf("Enter the eleemnt to be deleted:\t");
					scanf("%d",&ele);
					head = delete(head, ele);
					break;
			case 3: display(head);
					break;
			case 4: printf("EITING FROM THE PROGRAM!!");
					exit(0);
					break;
			default:printf("Invalid Input!!!");
		}		
	}while(ch!=4);
	return 0;
}
