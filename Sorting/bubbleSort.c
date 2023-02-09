#include<stdio.h>

void bubbleSort(int arr[], int n);

void swap(int i, int j, int arr[]);

void main(){
    int n ;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Sorted array");
    bubbleSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
}
    

void bubbleSort(int arr[], int n){
    for(int i =0 ; i< n-1; i++ ){
        for(int j =0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(j,j+1,arr);
            }
        }
    }
}

void swap(int i, int j, int arr[]) {
   int temp =  arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}
