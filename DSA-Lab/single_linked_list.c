#include<stdlib.h>
#include<stdio.h>


struct node{
	int data;
	struct node *link;
};


void get_data(struct node *head){                   // traverse list and print each data and number of nodes
	struct node* temp;
	int count=0;
	temp=head;
	printf("\nData of nodes:");
	while(temp!=NULL){	
		count++;
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\nNumber of nodes are:%d",count);	
}


void add_end(struct node *head,int a){             // add new node at end of linked list
	
	struct node* temp;
	temp=head;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	struct node* newnode=malloc(sizeof(struct node));
	temp->link=newnode;
	newnode->data=a;
	newnode->link=NULL;
	printf("\nNode added at end");
	//printf("\nNew node data is:%d",newnode->data);

}

struct node* add_beg(struct node* head,int data){              // insert node at beginning of linked list
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=data; 
	newnode->link=head;
	head=newnode;
	printf("\nNode added at beginning");
	return head;
}


void add_at_pos(struct node* head,int data,int pos){           // insert node at any position in linked list
	struct node* ptr=head;
	struct node* ptr2=malloc(sizeof(struct node));
	ptr2->data=data;
	ptr2->link=NULL;
	pos--;
	while(pos!=1){
		ptr=ptr->link;
		pos--;
	}
	ptr2->link=ptr->link;
	ptr->link=ptr2;
	printf("Node added at position %d",pos);
}


struct node* delete_beg(struct node* head){               // delete first node in a linked list
	if(head==NULL){
		printf("No nodes available");
	}
	else{
	struct node* temp;
	temp=head;
	head=head->link;
	free(temp);
	temp=NULL;
	printf("\nNode deleted from beginning");
}
return head;	
}

void delete_last(struct node* head){                  //delete last node in a linked list
	if(head==NULL){
		printf("List already empty!");
	}
	else if(head->link==NULL){
		free(head);
		head=NULL;
	}
	else{
		struct node* temp=head;
		struct node* temp2=head;
		while(temp->link!=NULL){
			temp2=temp;
			temp=temp->link;
		}
		temp2->link=NULL;
		free(temp);
		temp=NULL;
		printf("\nNode deleted end");
	}

}


void del_at_pos(struct node **head,int pos){         // delete node at specific position
	struct node* current=*head;
	struct node* prev=*head;
	if(*head==NULL){
		printf("List is already empty!");
	}
	else if(pos==1){
		*head=current->link;
		free(current);
		current=NULL;
		printf("\nNode deleted from position %d",pos);
	}
	else{
		while(pos!=1){
			prev=current;
			current=current->link;
			pos--;
		}
		prev->link=current->link;
		free(current);
		current=NULL;
		printf("\nNode deleted from position %d",pos);
	}
}



void sort(struct node* head){                               // sort a linked list
	struct node *p,*q,*end;
	int temp;
	for(end=NULL;end!=head->link;end=p){
		for(p=head;p->link!=end;p=p->link){
			q=p->link;
			if(p->data > q->data){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
	printf("\nLinked list sorted");
}


void search(struct node* head,int key){                // binary search in list
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			printf("\nElement found!");
			return;
		}
		temp=temp->link;
	}
	printf("\nElement not found!");
}

void main(){
	printf("-----Single Linked List Operations-----");
	struct node* head=malloc(sizeof(struct node));               
	printf("\nEnter data of first node:");
	scanf("%d",&head->data);
	head->link=NULL;
	int yn=1,choice,num,pos;
	while(yn==1){
		printf("What signle linked list operation do you want to perform ?");
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
				add_at_pos(head,num,pos);
				get_data(head);
				break;
			case 4:
				head=delete_beg(head);
				get_data(head);
				break;
			case 5:
				delete_last(head);
				get_data(head);
				break;
			case 6:
				printf("\nEnter position:");
				scanf("%d",&pos);
				del_at_pos(&head,pos);
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




