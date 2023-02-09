#include <stdio.h>


void QuickSort(int p, int q, int arr[]);
int partition(int p, int q, int arr[]);
void swap(int a, int b, int arr[]);


void main(){

    int n;
    printf("Enter the size of the array");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    QuickSort(0,n-1,arr);
    for(int i =0 ; i<n; i++){
        printf("%d ",arr[i]);
    }
}
int partition(int p, int q, int arr[]){
    int pivot = arr[p];
    int i = p+1;
    int j = q;
    while(1){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(i,j, arr);
        }
        else{
            swap(p,j,arr);
            break;
        }
    }
    return j;
}
void swap(int num1, int num2, int arr[]) {
   int temp =  arr[num1];
   arr[num1] = arr[num2];
   arr[num2] = temp;
}
void QuickSort(int p, int q, int arr[]){
    if(p<q){
        int j = partition(p,q,arr);
        QuickSort(p,j-1,arr);
        QuickSort(j+1,q,arr);
    }
}
