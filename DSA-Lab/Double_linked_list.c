#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

 
void get_data(struct node* head){             // get data of list
	struct node* temp;
	int count=0;
	temp=head;
	printf("\nData of nodes is:");
	while(temp!=NULL){
		count++;
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\nNumber of nodes:%d",count);
}



struct node* add_beg(struct node* head,int num){                  // add node at beginning
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	return head;
}



void add_end(struct node* head,int num){                     // add node at end
	struct node* temp;
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	newnode->prev=temp;
	temp->next=newnode;
}


 
void add_any(struct node* head,int num,int pos){                      // add node at any position
	struct node* newnode=malloc(sizeof(struct node));
	struct node *temp,*temp2;
	newnode->data=num;
	newnode->next=NULL;
	newnode->prev=NULL;
	temp=head;
	pos--;
	while(pos!=1){
		temp=temp->next;
		pos--;
	}
	temp2=temp->next;
	temp->next=newnode;
	temp2->prev=newnode;
	newnode->prev=temp;
	newnode->next=temp2;
}



struct node* delete_beg(struct node* head){                  // delete first node
	if(head==NULL){
		printf("No nodes available");
	}
	else{
		struct node* temp=NULL;
		temp=head;
		head=head->next;
		free(temp);
		temp=NULL;
		head->prev=NULL;
		
	}
		return head;
}



void delete_end(struct node* head){         // delete last node
	struct node *temp,*temp2;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp2=temp->prev;
	temp2->next=NULL;
	free(temp);
	temp=NULL;
}



void delete_any(struct node* head,int pos){       // delete node at position
	struct node *temp,*temp2;
	temp=head;
	while(pos>1){
		temp=temp->next;
		pos--;
	}	
	temp2=temp->prev;
	temp2->next=temp->next; 
	temp->next->prev=temp2;
	free(temp);
	temp=NULL;
}




void sort(struct node* head){                               // sort a linked list
	struct node *p,*q,*end;
	int temp;
	for(end=NULL;end!=head->next;end=p){
		for(p=head;p->next!=end;p=p->next){
			q=p->next;
			if(p->data > q->data){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
	printf("\nLinked list sorted");
}


void search(struct node* head,int key){                // linear search in list
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			printf("\nElement found!");
			return;
		}
		temp=temp->next;
	}
	printf("\nElement not found!");
}





void main(){
	printf("-----Double Linked List Operations-----");
	struct node* head=malloc(sizeof(struct node));
	printf("\nEnter data of first node:");
	scanf("%d",&head->data);
	head->next=NULL;
	head->prev=NULL;
	int yn=1,choice,num,pos;
	while(yn==1){
		printf("\nWhat double linked list operation do you want to perform ?");
		printf("\n1)Add node in beginning\n2)Add node at end\n3)Add node at specified position\n4)Delete node at beginning\n");
		printf("5)Delete node at end\n6)Delete node at specified position\n7)Sort linked list\n8)Search linked list\n9)Get data of list\n");
		scanf("%d",&choice);
		while(choice<1 && choice>9){
			printf("Please enter valid choice!!!\n");
			scanf("%d",&choice);
		}
		switch(choice){
			case 1:
				printf("\nEnter data of newnode:");
				scanf("%d",&num);
				head=add_beg(head,num);
				get_data(head);
				break;
			case 2:
				printf("\nEnter data of newnode:");
				scanf("%d",&num);
				add_end(head,num);
				get_data(head);
				break;
			case 3:
				printf("\nEnter data of newnode:");
				scanf("%d",&num);
				printf("\nEnter position:");
				scanf("%d",&pos);
				add_any(head,num,pos);
				get_data(head);
				break;
			case 4:
				head=delete_beg(head);
				get_data(head);
				break;
			case 5:
				delete_end(head);
				get_data(head);
				break;
			case 6:
				printf("\nEnter position:");
				scanf("%d",&pos);
				delete_any(head,pos);
				get_data(head);
				break;
			case 7:
				sort(head);
				get_data(head);
				break;
			case 8:
				printf("\nEnter number to be searched:");
				scanf("%d",&num);
				search(head,num);
				break;
			case 9:
				get_data(head);
				break;
			default:
				printf("\nEnter a valid choice!");
		}
	printf("\nDo you want to run again?\n1)Yes\n2)No\n");
	scanf("%d",&yn);
	system("CLS");
	}
}
