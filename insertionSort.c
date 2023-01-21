#include<stdio.h>

void insertionSort(int arr[], int n);

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

    insertionSort(arr,n);

    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}


void insertionSort(int arr[], int n){
    
    int current;
    int prev;
    for (int i = 1; i < n; i++)
    {
        current=arr[i];
        prev=i-1;
        while(prev>=0 && current< arr[prev]){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=current;
    }
    
}

