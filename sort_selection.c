/* Selection Sort
Dizinin en kucuk elemanin bulup basta i=0 a esitken dizi[i]
ye koyuyor sonra ayni islemi i+1 den devam ettiriyor. i <n-1 e kadar . */
#include <stdio.h>
#include <stdlib.h>

void selectionsort(int *,int);

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

  selectionsort(dizi,n);

  printf("\nSiralanmis dizi:\n");
  for(i=0; i<n; i++)
    printf("%d ",dizi[i]);

}

void selectionsort(int * dizi, int n){
  int  i , j , enkucuk , tmp;

  for(i=0;i<n-1;i++){
    enkucuk = i;                              //Selection
    for(j=i+1;j<n;j++)                         //Sort
      if(dizi[j] < dizi[enkucuk])                 //Algoritmasi
        enkucuk = j;

    tmp=dizi[i];
    dizi[i]=dizi[enkucuk];
    dizi[enkucuk]=tmp;
  }
}
