#include<stdio.h>
void qsf(int arr[],int low,int high){
	int pivot,i,j,temp;
	if(low<high){
		pivot=low;
		i=low+1;
		j=high;
		while(i<j){
		
		while(arr[i]<arr[pivot] && i<=high){
			i++;
		}
		while(arr[j]>arr[pivot] && j>=low){
			j--;
		}
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[j];
	arr[j]=arr[pivot];
	arr[pivot]=temp;
	qsf(arr,low,j-1);
	qsf(arr,j+1,high);
}
}
void main(){
	int arr[6]={10,9,7,20,4,15},k;
	qsf(arr,0,5);
	for(k=0;k<6;k++){
		printf("%d ",arr[k]);
	}
	
}
