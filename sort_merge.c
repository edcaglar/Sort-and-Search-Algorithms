/*  Merge Sort
Divide and Conquer Algoritmasidir*/
#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100
void merge(int arr[], int left, int med, int right);
void mergeSort(int arr[], int left, int right);

int main(){

      int i,arr_size;

      int arr[BOYUT];

      printf("Array boyutunu girin\n");
      scanf("%d",&arr_size);

      for(i=0; i<arr_size; i++){
        printf("%d.eleman :",i+1);
        scanf("%d",&arr[i]);
      }

      printf("\nDiziniz:\n");
      for(i=0; i<arr_size; i++)
        printf("%d ",arr[i]);

      mergeSort(arr,0,arr_size-1);

      printf("\nSiralanmis dizi:\n");
      for(i=0; i<arr_size; i++)
          printf("%d ",arr[i]);

}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int med = left + (right - left)/2;
        printf("\narr left med\n");

        mergeSort(arr,left,med);
        printf("arr med+1 right\n");
        mergeSort(arr, med+1, right);
        printf("\nmerge left med right\n");
        merge(arr, left, med, right);
    }
}

void merge(int arr[], int left, int med, int right){
    int i,j,k;
    int n1 = med-left+1;
    int n2 = right-med;

    int L[n1];
    int R[n2];

    for(i=0; i<n1 ;i++)
        L[i] = arr[left+i];
    for(j=0; j<n2; j++)
        R[j] = arr[med+j+1];
    i=0; j=0;
    k=left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k]=L[i];
            i++;
            k++;
        }

        if(R[j] < L[i]){
            arr[k]=R[j];
            k++; j++;
        }
    }

    while(i < n1){
        arr[k]=L[i];
        i++; k++;
    }
    while(j <n2){
        arr[k]=R[j];
        j++; k++;
    }
}
