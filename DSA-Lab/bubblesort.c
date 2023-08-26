#include<stdio.h>
void bs(int arr[],int n){
	int i=0,j=0,k=0,temp;
	for(i=0;i<n-1;i++){
		int swapped;
		swapped=1;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swapped=0;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			if(swapped)
			break;
		}
	}
	printf("Sorted array is:");
	
	for(k=0;k<n;k++){
		printf("%d ",arr[k]);
	}
}
void main(){
	int arr[5]={25,32,89,63,99};
	bs(arr,5);
}
