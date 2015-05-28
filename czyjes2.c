#include <stdio.h>
#include <stdlib.h>

void add(int** ptab, int n, int new_elem)
{
int* nowa_tab=malloc((n+1)*sizeof(int));

int przepisz;
for(przepisz=0; przepisz<n; przepisz++)
{
nowa_tab[przepisz]=(*ptab)[przepisz];
}
nowa_tab[n]=new_elem;
free(*ptab);
*ptab=nowa_tab;
}


void main()
{
int* wsk=NULL;
int funkcja, wypisz;
for(funkcja=0; funkcja<10; funkcja++)
{
add(&wsk, funkcja, (funkcja+1));


}
for(wypisz=0; wypisz<funkcja; wypisz++)
printf("%3d", wsk[wypisz]);
putchar('\n');
}
