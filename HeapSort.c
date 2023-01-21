#include<stdio.h>
int arr[5]={5,4,3,2,1};
int n =5;
void main(){
    HeapSort();
    for (int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
}
void InsertHeap(int i){
    int j = (i-1)/2;
    int item = arr[i];
    while(i>=0 && item >arr[j]){
        arr[i]=arr[j];
        i=j;
        j=(i-1)/2;
    }
    arr[i]=item;
}
void HeapSort(){

    int k = n-1;
    while(k>1){
        for(int i =1 ;i<=k ; i++){
            InsertHeap(i);
        }
        swap(arr[0],arr[k--]);
    }
}

void swap(int num1, int num2) {
   int temp =  arr[num1];
   arr[num1] = arr[num2];
   arr[num2] = temp;
}