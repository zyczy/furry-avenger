#ifndef header
#define header
#include <stdio.h>
#include <stdlib.h>

struct dane{
int wymiar_n;
int wymiar_m;
int** wsk;
};


void delete(struct dane* tab);
void delete_part(struct dane* tab, int rozmiar);
struct dane create(int rozmiar_n, int rozmiar_m); 
void print_x(struct dane* tab);
void print(struct dane* tab);
#endif