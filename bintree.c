#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * lchild;
	struct node * rchild;
};
typedef struct node * NODE;
NODE getnode(int item){
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
NODE insert(NODE root, int item){
	if(root == NULL){
		return getnode(item);
	}
	if(item < root->data){
		root->lchild = insert(root->lchild, item);
	}
	else if(item > root->data){
		root->rchild = insert(root->rchild, item);
	}
	return root;
}
void preorder(NODE root){
	if(root == NULL)
		return;
	printf("%d\t",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(NODE root){
	if(root == NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\t",root->data);
}
void inorder(NODE root){
	if(root == NULL)
		return;
	inorder(root->lchild);
	printf("%d\t",root->data);
	inorder(root->rchild);
}
int main(){
	NODE root = NULL;
	int ch, ele;
	do{
		printf("\n\n1 : Insert an element into the tree");
		printf("\n2 : INORDER");
		printf("\n3 : PREORDER");
		printf("\n4 : POSTORDER");
		printf("\n5 : EXIT");
		printf("\nEnter your choie:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the element to be inserted:\t");
					scanf("%d",&ele);
					root = insert(root, ele);
					break;
			case 2: inorder(root);
					break;
			case 3: preorder(root);
					break;
			case 4: postorder(root);
					break;
			case 5: printf("Exiting from the program!!\n\n");
					exit(0);
			default:printf("Invalid Choise!!");
		}
	}while(ch!=0);
	return 0;
}
