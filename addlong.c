#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode(){
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else{
		printf("No memory allocatipon\n");
		exit(0);
	}
}
NODE create_head(){
    p = getnode();
    p->data = -1;
    p->next = p;
    return p;
}
NODE add_long_no(NODE n1, NODE n2){
    NODE num1 = n1->next;
    NODE num2 = n2->next;
    n = create_head();
    int carry = 0;
    int sum=0;
    int pn1,pn2;
    while((num1!=n1)||(num2!=n2)){
        if(num1 == n1)
            pn1 = 0;
        else
            pn1 = num1->data;
        if(num2 == n2)
            pn2 = 0;
        else
            pn2 = num2->data;
        sum = pn1+pn2+carry;
        carry = sum/10;
        n = insert_end(n,sum%10);
        if(num1!=n1)
            num1 = num1->next;
        if(num2!=n2)
            num2 = num2->next;
    }
    if(carry>0)
        n = insert_end(n,carry);
    return n;
}
NODE insert_end(NODE head,int item){
	NODE p,q;
	q = getnode();
	q->data = item;
	q->next = NULL;
	if(head==NULL){
		return q;
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next = q;
	return head;
}
void display_sum(NODE n){
    int arr[100];
    if(n->next=n)
        printf("EMPTY!!");
    else{
        int i=0;
        NODE p = n->next;
        while(p!=n){
            arr[i] = p->data;
            i++;
            p = p->next;
        }
        for(int j=i-1;j>=0;i--)
            printf("%d",arr[j]);
    }
}
int main(){ 
    
