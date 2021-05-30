/* Insertion Sort
Ilk once ilk 2 elemani sonra ilk 3 elemani
en sonunda n elemani siralar */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *,int);
int main(){

  int n,i;
  printf("Dizinin eleman sayisini girin.");
  scanf("%d",&n);
  int *dizi=malloc(sizeof(int)*n);

  for(i=0; i<n; i++){
    printf("%d.elemani girin:",i+1);
    scanf("%d",&dizi[i]);
  }
  printf("Diziniz:\n");
  for(i=0; i<n; i++)
    printf("%d ",dizi[i]);


  insertionSort(dizi,n);

  printf("\nSiralanmis dizi:\n");
  for(i=0; i<n; i++)
      printf("%d ",dizi[i]);

}

void insertionSort(int *dizi,int n){
  int a,i,j,tmp;

  for(i=1;i<n;i++){
      a=i;
      for(j=i-1; j>=0; j--)
          if(dizi[a]<dizi[j]){
              tmp=dizi[a];
              dizi[a]=dizi[j];
              dizi[j]=tmp;
              a=a -1;
          }

  }
}
