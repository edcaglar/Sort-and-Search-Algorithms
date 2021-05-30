#include <stdio.h>

void shell(int  arr[],int boyut);

int main(){

  int n,i;

  printf("Olusturulmasini istediginiz dizinin boyutunu girin\n");
  scanf("%d",&n);
  int dizi[n];   //Dizinin boyutunu aldik

  printf("Dizinin elemanlarini sirasiyla girin.\n");

  for(i=0;i<n;i++){
    printf("%d.eleman\t=",i+1);
    scanf("%d",&dizi[i]);     //Dizinin elemanlarini aldik
  }

  printf("Olusturulan dizi =");
  for(i=0;i<n;i++)
    printf(" %d\t",dizi[i]);   //Diziyi ekrana yazdirdik.

  printf("\n");
  shell(dizi,n);    

}

void shell(int arr[],int boyut){  //SHELL SORT

  int gap,i,j;
  int tmp;
  for(gap=boyut/2;gap>0;gap/=2)
    for(i=gap;i<boyut;i++)
      for(j=i-gap; j>=0 && arr[j]>arr[j+gap]; j-=gap){
        tmp=arr[j];
        arr[j]=arr[j+gap];
        arr[j+gap]=tmp;
      }

  printf("\nSiralanmis dizi =");
  for(i=0;i<boyut;i++)
    printf(" %d\t",arr[i]);

  printf("\n");
}
