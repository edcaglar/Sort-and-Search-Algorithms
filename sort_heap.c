/*Heap Agacinda Islemler*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
void buildMaxHeap(int *arr, int n);
void heapSort(int *arr , int n);

int main(){
    int i,n;

    printf("Eleman sayisini girin.");
    scanf("%d",&n);

    int *arr=malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        printf("\n%d.eleman:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Diziniz:\n");
    for(i=0; i<n ;i++)
        printf("%d ",arr[i]);

    heapSort(arr,n);

    printf("Siralanmis dizi:\n");
    for(i=0; i<n ;i++)
        printf("%d ",arr[i]);

}

void buildMaxHeap(int *arr, int n){
	int i;
    for(i = 1; i < n; i++)

        if(arr[i] > arr[(i - 1)/2]){
            int j=i;

            while(arr[j] > arr[(j-1)/2]){
                swap(&arr[j],&arr[(j-1)/2]);
                j=(j-1)/2;
            }
        }
}

void heapSort(int *arr, int n){
    buildMaxHeap(arr,n);
	int i;
	
    for(i= n-1; i > 0;i--){

        swap(&arr[0],&arr[i]);
        int j=0,index;
        do{
            index= 2*j + 1;
            if(arr[index] < arr[index+1] && index < i-1)
                index++;
            if (arr[j] < arr[index] && index < i)
                swap(&arr[j], &arr[index]);

            j=index;

        }while(index < i);
    }

}
