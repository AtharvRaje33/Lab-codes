#include<stdio.h>
int linearsearch(int arr[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(key==arr[i]){
			return i;
		}
	}
	return -1;
}

void main(){
	int arr[10]={4,2,3,1,5,6,9,8,7,10};
	int n=10,key=6,ans;
	ans=linearsearch(arr,n,key);
	if(ans>=0){
		printf("Element found at index %d",ans);
	}
	else
	printf("Element not found");
}
