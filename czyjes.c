#include<stdio.h>
#include<stdlib.h>
#define ROZMIAR 10
void add(int **ptab,int n,int new_elem);
 
void main(void)
{
  int *tablica;
  int i,nowy;
 
  tablica=NULL;
 
  for(i=0;i<ROZMIAR;i++)
  {
    printf("Podaj nowy element tablicy\n");
    scanf("%d",&nowy);
    add(&tablica,i,nowy);
    
  }
 
  for(i=0;i<ROZMIAR;i++)
    printf("%d,",tablica[i]);
  printf("\n");
 
  free(tablica);
  tablica=NULL;
 
}
 
void add(int **ptab,int n, int new_elem)
{
  int *newtab;
  int i;
 
  newtab=calloc((n+1),sizeof(int));
  
 
  for(i=0;i<n;i++)
    newtab[i]=(*ptab)[i];
  newtab[n]=new_elem;
 
  free(*ptab);
  *ptab=NULL;
 
  *ptab=newtab;
}
