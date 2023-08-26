#include<stdio.h>
int rbs(int arr[],int hi,int lo,int element){
	int mid,position;
	if(lo<=hi){
	
	mid=(hi+lo)/2;
	if(arr[mid]==element){
		return ++mid;
		}
	else if(arr[mid]<element){
		lo=mid+1;
		return rbs(arr,hi,lo,element);
	}
	else{
		hi=mid-1;
		return rbs(arr,hi,lo,element);
	}
}
else
return -1;
}
void main(){
	int i,arr[5],hi=9,lo=0,element,position;
	printf("Enter array elements:");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Enter element to be searched:");
	scanf("%d",&element);
	position=rbs(arr,hi,lo,element);
	if(position>0)
	printf("Element found at %d",position);
	else
	printf("Element not found");
	
}
