#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree* left;
	struct tree* right;
	int height;
};


void inorder(struct tree* root){                  // inorder traversal
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}


int max (int a, int b){                 // function to calculate maximum
    return (a>b)?a:b;
}


int getheight(struct tree* n){        // function ot get height of node
	if(n==NULL){
		return 0;
	}
	return n->height;
}
 
struct tree* createnode(int data){                           // function ot create node
	struct tree* node = malloc(sizeof(struct tree));
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	node->height=1;
	return node;
}

int getbf(struct tree* node){                           // function ot get balance factor
	if(node==NULL){ 
		return 0;
	}
	return getheight(node->left)-getheight(node->right);
}

struct tree* ll(struct tree* x){          // left left rotation         
	struct tree* y=x->right;         //                                            x
	struct tree* t2=y->left;		               //                       \            
	y->left=x;					  //                             y
	x->right=t2;                                                           //      / \    
	x->height=max(getheight(x->left),getheight(x->right))+1;               //     t2  z
	y->height=max(getheight(y->left),getheight(y->right))+1;
	return y;
}

 
struct tree* rr(struct tree* y){                 // right right rotation
	struct tree* x=y->left;         //                                          y
	struct tree* t2=x->right;       				//	   /
	x->right=y;					//                        x								
	y->left=t2;				      //                          /   \   .
	y->height=max(getheight(y->left),getheight(y->right))+1;	//        z     t2
	x->height=max(getheight(x->left),getheight(x->right))+1; 
	return x;      
}


struct tree* insert(struct tree* node,int data){                   // insertion in tree	
	if(node==NULL){
		return(createnode(data));
	}
	
	if(data<node->data){
		node->left=insert(node->left,data);
	}
	else if(data > node->data){
		node->right=insert(node->right,data);
	}
	return node;
	
	node->height=max(getheight(node->left),getheight(node->right))+1;
	int bf = getbf(node);
	if(bf>1 && data<node->left->data){           // rr case 
		return rr(node);
	}
	
	if(bf>-1 && data>node->right->data){       // ll case
		return ll(node);
	}
	
	if(bf>1 && data>node->left->data){    // lr case
		node->left=ll(node->left);
		return rr(node);
	}
	
	if(bf<-1 && data<node->right->data){    // rl case
		node->right = rr(node->right);
		return ll(node);
	}
	return node;
}


int rsearch(struct tree* root,int key){                // recursive search in tree
	if(root==NULL){
		printf("\nElement not found in tree");
		return;
	}
	if(key==root->data){
		printf("\nElement found in tree");
		return;
	}
	else if(key<root->data){
		rsearch(root->left,key);
	}
	else{
		rsearch(root->right,key);
	}
}


int main(){                                                       // main function
	 struct tree * root = malloc(sizeof(struct tree));
	 root->left=NULL;
	 root->right=NULL;
	 root->height=getheight(root);
	 printf("Enter data of root of the tree:");
	 scanf("%d",&root->data);
	 int choice,d,s,t=1;
	 
	 while(t==1){
	 
	 
	 printf("Enter operation you want to perform:\n1)Insert Node\n2)Inorder Traversal\n3)Search\n");
	 scanf("%d",&choice);
	 switch(choice){
	 	case 1: 
	 	printf("Enter data of element to be inserted:");
	 	scanf("%d",&d);
	 	root=insert(root,d);
	 	printf("Node with data %d inserted",d);
	 	break;
	 	
	 	case 2:
	 		inorder(root);
	 		break;
	 		
	 	case 3:
	 		printf("Enter element you want to search:");
	 		scanf("%d",&s);
	 		rsearch(root,s);
	 		break;
	 		
	 }
	 printf("\nDo you want to run again?\n1)Yes\n2)No");
	 scanf("%d",&t);

}
	 
	return 0;
}
