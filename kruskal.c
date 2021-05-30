#include <stdio.h>
#include <stdlib.h>

struct n{
  int firstNode;
  int secondNode;
  int value;
};
typedef struct n data;

void kruskal(data *dizi, int *visited, int dugumSayisi, int kenarSayisi);
void swap(data *dizi1, data *dizi2);

int main(){
  int kenarSayisi, i, j;
  FILE *fp = fopen("input.txt","r");
  fscanf(fp,"%d",&kenarSayisi);
  data *dizi = (data*)malloc(sizeof(data)*kenarSayisi);
  int dugumSayisi = 8;
  int *visited = (int *)malloc(sizeof(int)*8);

  for(i=0; i < dugumSayisi; i++)
    visited[i]=0;

  for(i=0; i < kenarSayisi; i++)
    fscanf(fp,"%d %d %d", &dizi[i].firstNode, &dizi[i].secondNode, &dizi[i].value);
  fclose(fp);

  for(i=0; i < kenarSayisi; i++)
    for(j=0; j < kenarSayisi-1; j++)
      if(dizi[j].value > dizi[j+1].value)
        swap(&dizi[j],&dizi[j+1]);

  for(i=0; i < kenarSayisi; i++)
    printf("%d %d %d\n", dizi[i].firstNode, dizi[i].secondNode, dizi[i].value);
  printf("\nEn kisa yol:\n");
  kruskal(dizi, visited , dugumSayisi, kenarSayisi);

}

void swap(data *dizi1, data *dizi2){
  data *temp = (data *)malloc(sizeof(data));
  *temp = *dizi1;
  *dizi1 = *dizi2;
  *dizi2 = *temp;
}

void kruskal(data *dizi, int *visited, int dugumSayisi, int kenarSayisi){
  int i=0,j=0;
  while(i < dugumSayisi){
    if(dizi[j].firstNode != 0 || dizi[j].secondNode != 0){
      printf("%d %d %d\n", dizi[j].firstNode, dizi[j].secondNode, dizi[j].value);
      visited[dizi[j].firstNode] = 1;
      visited[dizi[j].secondNode] = 1;
      i++;
    }
    j++;
  }
}
