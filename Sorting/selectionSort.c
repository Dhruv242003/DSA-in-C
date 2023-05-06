
#include<stdio.h>
void main(){


    int n ;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Sorted array\n");
    selectionSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void selectionSort(int arr[], int n){
    int min;
    int minIdx;
    for(int i=0; i<n-1; i++){
        min = arr[i];
        for(int j=i; j<n ; j++){
            if(arr[j]<min){
                min = arr[j];
                minIdx=j;
            } 
        }
        if(arr[i]!=arr[minIdx]){
            int temp;
            temp = arr[i];
            arr[i]=min;
            arr[minIdx]=temp;
        }
        

    }
}