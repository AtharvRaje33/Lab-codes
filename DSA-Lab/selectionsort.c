#include<stdio.h>
void ss(int arr[],int n){
	int i,j,imin,temp,k;
	imin=0;
	for(i=0;i<n-1;i++){
		imin=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[imin]){
				imin=j;
			}
		}
		if(imin!=i){
			temp=arr[imin];
			arr[imin]=arr[i];
			arr[i]=temp;
		}
	}
	printf("Sorted array:");
	for(k=0;k<n;k++){
		printf("%d ",arr[k]);
	}
}
void main(){
	int arr[4]={7,6,4,3};
	ss(arr,4);
}
