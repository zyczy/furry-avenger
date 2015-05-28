#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h>
#define ROZMIAR_N 22
#define ROZMIAR_M 88

int main()
{
struct dane tab = create(ROZMIAR_N,ROZMIAR_M);
int wypelnij_n, wypelnij_m;
for(wypelnij_n=0; wypelnij_n<tab.wymiar_n; wypelnij_n++)
  {
  for(wypelnij_m=0; wypelnij_m<tab.wymiar_m; wypelnij_m++)
    {
    (tab.wsk)[wypelnij_n][wypelnij_m]=0;
    }
  }
FILE * plik;
if ((plik = fopen("gra_in.txt", "r")) == NULL)
  {
  printf("Nie udalo siê otworzyc pliku.\n");
  return 0;
  }
int i;
int n;

while(!feof(plik))
{
fscanf(plik, "%d", &n);
fscanf(plik, "%d", &i);
if(i>ROZMIAR_N || i<=0 || n<=0 || n>ROZMIAR_M)
  {
  printf("Podano zle dane.\n");
  return 0;
  }
(tab.wsk)[i-1][n-1] = 1;
}

if(fclose(plik))
  {
  printf("Nie moge zamknac pliku\n");
  return 0;
  }

print_x(&tab);
char znak1;
znak1 = getchar();
if(znak1!='k')
  {
  char znak;
  while(znak!='k')
    {
    struct dane sas = create(ROZMIAR_N, ROZMIAR_M);
    int a, b;
    int sasiedzi;
    for(a=0; a<ROZMIAR_N; a++)    //zliczanie sasiadow
      {
      for(b=0; b<ROZMIAR_M; b++)
	{
	int gora, dol, lewo, prawo;
	gora = b-1;
	dol = b+1;
	lewo = a-1;
	prawo = a+1;
	sasiedzi = 0;
	if(gora>=0 && (tab.wsk)[a][gora] == 1)
	  sasiedzi++;
	if(lewo>=0 && (tab.wsk)[lewo][b] == 1)
	  sasiedzi++;
	if(prawo<ROZMIAR_N && (tab.wsk)[prawo][b] ==1)
	  sasiedzi++;
	if(dol<ROZMIAR_M && (tab.wsk)[a][dol] ==1)
	  sasiedzi++;
	if(gora>=0 && lewo>=0 && (tab.wsk)[lewo][gora]==1)
	  sasiedzi++;
	if(gora>=0 && prawo<ROZMIAR_N && (tab.wsk)[prawo][gora]==1)
	  sasiedzi++;
	if(dol<ROZMIAR_M && lewo>=0 && (tab.wsk)[lewo][dol]==1)
	  sasiedzi++;
	if(dol<ROZMIAR_M && prawo<ROZMIAR_N && (tab.wsk)[prawo][dol]==1)
	  sasiedzi++;
	(sas.wsk)[a][b]=sasiedzi;     //wpisanie liczby sasiadow do tabeli
	}
      }
    int c,d;
    for(c=0; c<ROZMIAR_N; c++)
      {
      for(d=0; d<ROZMIAR_M; d++)
	{
	if((tab.wsk)[c][d]==1)    //sprawdzam czy kolejne komorki sa zywe
	  {
	  if((sas.wsk)[c][d]!=2 && (sas.wsk)[c][d]!=3)
	    {
	    (tab.wsk)[c][d]=0;
	    }
	  }
	else if((tab.wsk)[c][d]==0)
	  {
	  if((sas.wsk)[c][d]==3)
	    {
	    (tab.wsk)[c][d] = 1;
	    }
	  }
	}
      }
    system("clear");
    print_x(&tab);
    znak=getchar();

    }
  }

FILE* plik2;
if((plik2 = fopen("gra_out.txt", "w"))==NULL)
   {
   printf("Nie moge otworzyc pliku.\n");
   return 0;
   }

int x,y;
for(x=0; x<ROZMIAR_N; x++)
  {
  for(y=0; y<ROZMIAR_M; y++)
    {
    if((tab.wsk)[x][y] == 1)
      {
      fprintf(plik2, "%d ", x+1);
      fprintf(plik2, "%d\n", y+1);
      }
    }
  }
if(fclose(plik2))
  {
  printf("Nie moge zamknac pliku!\n");
  return 0;
  }
return 0;
}
