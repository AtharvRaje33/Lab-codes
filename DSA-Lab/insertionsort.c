#include<stdio.h>
void is(int arr[],int n){
	int i,j,key,k;
	for(i=0;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;	
	}
	printf("Sorted array:");
	for(k=0;k<n;k++){
		printf("%d ",arr[k]);
	}
}
void main(){
	int arr[5]={1,3,2,4,5};
	int n=5;
	is(arr,n);
	
}
