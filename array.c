#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void delete(struct dane* tab)
{
int usun;
for(usun=0; usun<((*tab).wymiar_n); usun++)
  {
  free(((*tab).wsk)[usun]);
  }
free((*tab).wsk);
(*tab).wsk=NULL;
(*tab).wymiar_n = 0;
(*tab).wymiar_m = 0;
}

void delete_part(struct dane* tab, int rozmiar)
{
int usun;
for(usun=0; usun<rozmiar; usun++)
  {
  free((((*tab).wsk))[usun]);
  }
free(*((*tab).wsk));
(*tab).wsk=NULL;
(*tab).wymiar_n = 0;
(*tab).wymiar_m = 0;
}

struct dane create(int rozmiar_n, int rozmiar_m)  /*tworzy strukturê zawieraj¹c¹ tablicê dwuwymiarow¹ o rozmiarach podanych  */
{
struct dane tablica;
tablica.wsk = (int**)malloc(rozmiar_n*(sizeof(int*)));
if(tablica.wsk==NULL)
  {
  free(tablica.wsk);
  return;
  }
else
  {
  int i;
  for(i=0; i<rozmiar_n; i++)
    {
    (tablica.wsk)[i] = (int*)malloc(rozmiar_m*sizeof(int));
    if((tablica.wsk)[i]==NULL)
      {
      delete_part(&tablica, i);
      return;
      }
    }
  tablica.wymiar_n = rozmiar_n;
  tablica.wymiar_m = rozmiar_m;
  return tablica;
  }
}

void print_x(struct dane* tab)
{
int wypisz_n, wypisz_m;
for(wypisz_n=0; wypisz_n<(*tab).wymiar_n; wypisz_n++)
  {
  for(wypisz_m=0; wypisz_m<(*tab).wymiar_m; wypisz_m++)
    {
    if(((*tab).wsk)[wypisz_n][wypisz_m]  == 1)
      printf(" x");
    else
      printf("  ");
    }
  putchar('\n');
  }
}

void print(struct dane* tab)
{
int wypisz_n, wypisz_m;
for(wypisz_n=0; wypisz_n<(*tab).wymiar_n; wypisz_n++)
  {
  for(wypisz_m=0; wypisz_m<(*tab).wymiar_m; wypisz_m++)
    {
    printf("%d", ((*tab).wsk)[wypisz_n][wypisz_m]);
    }
  putchar('\n');
  }
}
