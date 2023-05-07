#include <stdio.h>
int arr[5]={5,4,3,2,1};
int passCount=0;
void main(){
    // passCount=0;
    MergeSort(0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void MergeSort(int low, int high){
    passCount++;
    if(low<high){
        int mid = (high+low)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);

        Merge(low,mid,high);
    }
}

void Merge(int low, int mid, int high){
    int tempArr[5];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            tempArr[k++]=arr[i++];
        }
        else{
            tempArr[k++]=arr[j++];
        }
        
    }
    while(j<=high){
        tempArr[k++]=arr[j++];
    }
    while(i<=mid){
        tempArr[k++]=arr[i++];
    }
    for(int a=low; a<=high;a++){
        arr[a]=tempArr[a-low];
    }
}