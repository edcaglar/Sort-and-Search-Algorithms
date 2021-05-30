#include <stdio.h>
#include <stdlib.h>

int binarySearch(int s[], int x, int n2);
int * bubbleSort(int dizi[], int n);
int main(){

  int tmp,i,j,n,eleman;
  
  printf("Olusturmak istdiginiz dizinin boyutunu girin.\t=");
  scanf("%d",&n);
  int *dizi = (int *) malloc(sizeof(int)*n);

  for(i=0;i<n;i++){   //DIZIYI BURDA KULLANICIDAN ALIYORUZ
    printf("\nDizinin %d. elemanini giriniz\t=",i+1);
    scanf("%d",&dizi[i]);
  }

  printf("\nGirdiginiz dizi\t=");
  for(i=0;i<n;i++){   //DIZIYI BURDA EKRANA YAZDIRIYORUZ
    printf("%d\t",dizi[i]);
  }

  dizi = bubbleSort(dizi,n);

  printf("\nDizinin siralanmis sekli  =");
  for(i=0;i<n;i++){   //SIRALANMIS DIZIYI BURDA EKRANA YAZDIRIYORUZ
    printf("%d\t",dizi[i]);
  }

  printf("\n\nDizide sirasini bulmak istediginiz elemani yazin\n");
  scanf("%d",&eleman);//BULUNMASI ISTENEN ELEMANI ALDIK

  printf("Aradiginiz eleman dizinin %d. sirasinda.\n",binarySearch(dizi,eleman,n));

}


int * bubbleSort(int dizi[],int n){
	int i, j, tmp;
	for(i=0;i<n-1;i++){ //BUBBLE SORT diziyi kucukten buyuge siraladi
    for(j=0;j<n-1;j++){//BUBBLE SORT DIZIYI SIRALARKEN EN BUYUK ELEMANI SAGA ATARAK SIRALAR
      if(dizi[j]>dizi[j+1]){
        tmp=dizi[j];
        dizi[j]=dizi[j+1];
        dizi[j+1]=tmp;
      }
    }
  }
  return dizi;
}


int binarySearch(int s[],int x,int n2){

  int low,med,high;
  low=0;

  high=n2-1;

  while(low<=high){
    med=(high+low)/2;
    if(x<s[med])
      high=med-1;

    else if(x>s[med])
      low=med+1;

    else
      return med;
  }

  return -1;

}
