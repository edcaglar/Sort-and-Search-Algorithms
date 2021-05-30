/*Bubble Sort Algoritmasi
Verileri 2 li olarak siralar ve her adimda en buyuk eleman
dizinin sonuna atilmis olur.(0-1, 1-2, 2-3 karsilastirmalari yapilarak)
Bu karsilastirmalar n kere yapilir ve  en sondaki eleman en buyuk
eleman olacagi icin her adimda bakilan eleman sayisi 1 azalir */
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int);

int main(){
    int n,i;
    printf("Dizinin eleman sayisini girin.");
    scanf("%d",&n);
    int *dizi=malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        printf("%d.elemani girin:",i+1);
        scanf("%d",&dizi[i]);
    }

    printf("\nDiziniz:\n");
    for(i=0; i<n; i++)
        printf("%d ",dizi[i]);

    bubbleSort(dizi,n);

    printf("\nSiralanmis dizi:\n");
    for(i=0;i<n;i++)
        printf("%d ",dizi[i]);


}

void bubbleSort(int *dizi, int n){
    int i,j,tmp;
    for(i=0;i<n;i++)
        for(j=0;j<n-1-i;j++)
            if(dizi[j+1]<dizi[j]){
            tmp=dizi[j];
            dizi[j]=dizi[j+1];
            dizi[j+1]=tmp;
            }
}
