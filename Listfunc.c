#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode(){
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	if(p != NULL)
		return p;
	else{
		printf("Memory could not be allocated\n");
		exit(0);
	}
}
NODE insert_front(int item,NODE head){
	NODE p;
	p = getnode();
	p->data = item;
	p->next = head;
	head = p;
	return head;
}
void display(NODE head){
	NODE p;
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	p = head;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}
NODE sort(NODE head){
	NODE p = head;
	NODE q = NULL;
	int temp;
	if(head == NULL)
		return head;
	while(p->next != NULL){
		q = p->next;
		while(q != NULL){
			if(p->data > q->data){
				temp = p->data;
				p->data = q->data;
				q->data = temp;	
			}
			q = q->next;
		}
		p = p->next;
	}
	return head;
}
NODE reverse(NODE head){
	NODE curr = head;
	NODE prev = NULL;
	NODE nextn = NULL;
	if(head==NULL){
		printf("List is empty\n");
		return head;
	}
	if(head->next == NULL)
		return head;
	while(curr!=NULL){
		nextn = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextn;
	}
	head = prev;
	return head;
}
NODE concatenate(NODE h1,NODE h2){
	NODE p = h1;
	if(h1 == NULL)
		return h2;
	if(h2 == NULL)
		return h1;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = h2;
	return h1;
}
int main(){
	NODE head1 = NULL;
	NODE head2 = NULL;
	int ch, ele, n, i;
	do{
	   	printf("\n\n1 : Insert into List1\n2 : Insert to List2");
	   	printf("\n3 : Sort List1\n4 : Sort List2");
	   	printf("\n5 : Reverse List1\n6 : Reverse List2");
	   	printf("\n7 : Concatenate");
	   	printf("\n8 : Display List1/Concatenated List");
	   	printf("\n9 : Display List2");
	   	printf("\n10 : EXIT");
	    scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the no. of elements:\t");
				    scanf("%d",&n);
			    	printf("Enter the items:\n\t");
			    	for(i=0;i<n;i++)
			    	{
				    	scanf("%d",&ele);
					    head1 = insert_front(ele, head1);
				    }
				    break;
			case 2: printf("Enter the no. of elements:\t");
				    scanf("%d",&n);
			    	printf("Enter the items:\n");
			    	for(i=0;i<n;i++){
				    	scanf("%d",&ele);
					    head2 = insert_front(ele, head2);
				    }
				    break;
			case 3: head1 = sort(head1);
				    break;
			case 4: head2 = sort(head2);
				    break;
			case 5: head1= reverse(head1);
				    break;
			case 6: head2 = reverse(head2);
				    break;
			case 7: head1 = concatenate(head1, head2);
				    break;
			case 8: display(head1);
				    break;
			case 9: display(head2);
				    break;
			case 10:break;
			default:printf("Invalid input!!!!");
		}
	}while(ch!=10);
	return 0;
}
