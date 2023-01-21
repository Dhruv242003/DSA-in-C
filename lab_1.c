#include <stdio.h>

struct emp{
   char name[25];
   int emp_id;
   int salary;
};


void QuickSort(int p, int q, struct emp arr[]);
int partition(int p, int q, struct emp arr[]);
void swap(int a, int b, struct emp arr[]);




void main(){

    

    struct emp arr[3];
    
    for (int i = 0; i < 3; i++){
        printf("Enter the name of the employee\n");
        scanf("%s",&arr[i].name);
        printf("Enter the employee id\n");
        scanf("%d",&arr[i].emp_id);
        printf("Enter the salary of the employee");
        scanf("%d",&arr[i].salary);
    }

    QuickSort(0,2,arr);
    printf("Sorted employee id is :\n");
    for(int i =0 ; i<3; i++){
        printf("%d %s %d\n",arr[i].emp_id,arr[i].name,arr[i].salary);
        
    }
}



int partition(int p, int q, struct emp arr[]){
    int pivot = arr[p].emp_id;
    int i = p+1;
    int j = q;
    while(1){
        while(arr[i].emp_id<=pivot){
            i++;
        }
        while(arr[j].emp_id>pivot){
            j--;
        }
        if(i<j){
            swap(i,j,arr);
        }
        else{
           swap(p,j,arr);
            break;
        }
    }
    return j;
}

void swap(int num1, int num2, struct emp arr[]) {
   struct emp temp =  arr[num1];
   arr[num1] = arr[num2];
   arr[num2] = temp;
}


void QuickSort(int p, int q, struct emp arr[]){
    if(p<q){
        int j = partition(p,q,arr);
        QuickSort(p,j-1,arr);
        QuickSort(j+1,q,arr);
    }
}
