#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* create_node(int data){                               // create node
	struct tree* newnode=malloc(sizeof(struct tree));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}


void inorder(struct tree* root){                  // inorder traversal
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}


void preorder(struct tree* root){                              // preorder traversal
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(struct tree* root){                            // postorder traversal
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}


int isBST(struct tree* root){                  // check if tree is BST or not
	static struct tree* prev=NULL;
	if(root!=NULL){
		if(!isBST(root->left)){
			return 0;
		}
		if(prev!=NULL && root->data <= prev->data){
			return 0;
		}
		prev=root;
		return isBST(root->right);
	}
	else{
		return 1;
	}
  
}


int rsearch(struct tree* root,int key){                // recursive search in BST
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


int isearch(struct tree* root,int key){           // iterative search in BST
	while(root!=NULL){
	
	if(key==root->data){
		printf("\nElement found in tree");
		return;
	}
	else if(key<root->data){
		root=root->left;
	}
	else{
		root=root->right;
		}
	}
	printf("\nElement not found in tree");
	return;
}


int insert(struct tree* root,int data){              // insert node in tree
	struct tree* prev=NULL;
	struct tree* newnode = create_node(data);
		while(root!=NULL){
		prev=root;
		if(data==root->data){
			printf("Node with same value already exists");
			return;
		}
		else if(data<root->data){
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
	if(data<prev->data){
		prev->left=newnode;
		printf("\nNode inserted\n");
	}
	else{
		prev->right=newnode;
		printf("\nNode inserted\n");
	}
}


struct tree* inorderpredecessor(struct tree* root){      // returns previous node
	root=root->left;
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}

struct tree* deletenode(struct tree* root, int data) {             // deletes node
    struct tree* prev;

    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deletenode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deletenode(root->right, data);
    }
    else if (data == root->data) {
        if (root->left == NULL) {
            struct tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct tree* temp = root->left;
            free(root);
            return temp;
        }
        prev = inorderpredecessor(root);
        root->data = prev->data;
        root->left = deletenode(root->left, prev->data);
    }
    return root;
}



int main(){
	int data,choice,chk=1,dt,dtt,key,key2;
	printf("Enter data of root of tree:");
	scanf("%d",&data);
	struct tree* root=create_node(data);
	
	while(chk==1){
	printf("\nEnter operation you want to perform:\n1)Add node\n2)Preorder Traversal\n3)Inorder Traversal\n4)Postorder Traversal\n5)Delete node\n6)Iterative Search\n7)Recurrsive Search\n8)Check if tree is BST\n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("\nEnter data of new node:");
			scanf("%d",&dt);
			insert(root,dt);
			break;
			
		case 2:
			printf("\nPreorder Traversal is:");
			preorder(root);
			break;
			
		case 3:
			printf("\nInorder Traversal is:");
			inorder(root);
			break;
			
		case 4:
			printf("\nPostorder Traversal is:");
			postorder(root);
			break;
			
		case 5:
			
			printf("\nEnter data of node to be deleted:");
			scanf("%d",&dtt);
			deletenode(root,dtt);
			inorder(root);
			break;
		
		case 6:
		
			printf("\nEnter data to be searched in tree:");
			scanf("%d",&key);
			isearch(root,key);
			break;
			
		case 7:
			printf("\nEnter data to be searched in tree:");
			scanf("%d",&key2);
			rsearch(root,key);
			break;
			
		case 8:
			if(isBST(root)==1){
				printf("\nTree is BST");
			}
			else{
				printf("\nTree is not BST");
			}
			break;
	}
	printf("\nDo you want to run again:\n1)Yes\n2)No\n");
	scanf("%d",&chk);
	system("CLS");
}
	

	
	return 0;
}
