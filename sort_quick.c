#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

int main(){
    int high,i;
    printf("Dizinin eleman sayisini girin.");
    scanf("%d",&high);
    int *arr=malloc(sizeof(int)*high);

    for(i=0; i<high; i++){
        printf("%d.elemani girin:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nDiziniz:\n");
    for(i=0; i<high; i++)
        printf("%d ",arr[i]);

    quickSort(arr,0,high-1);

    printf("\nSiralanmis arr:\n");
    for(i=0;i<high;i++)
        printf("%d ",arr[i]);
}

void quickSort(int *arr, int low, int high){
    if(low < high){
    int pivot = partition(arr, low, high);

    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot+1,high);
    }
}

int partition(int *arr, int low, int high){
    int tmp,j;
    int i = (low-1);
    int pivot = arr[high];

    for(j = low; j <= high-1 ;j++){

        if(arr[j] <= pivot){
            i++;
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }
    tmp=arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=tmp;

    return i+1;






}
