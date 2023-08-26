#include<stdio.h>
int ibs(int arr[],int lo,int hi,int element){
	int mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(arr[mid]==element){
			return ++mid;
		}
		else if(arr[mid]<element){
			lo=mid+1;
		}
		else
		hi=mid-1;
}
if(lo>hi){
	return -1;
}
}
void main(){
	int i,arr[5],lo=0,hi=4,element,res;
	printf("Enter array elements:");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
		}
		printf("Enter element to be searched:");
		scanf("%d",&element);
		res=ibs(arr,lo,hi,element);
		if(res>0)
		printf("Element found at position %d",res);
		else
		printf("Element not found");
}
