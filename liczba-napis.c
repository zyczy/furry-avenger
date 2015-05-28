#include <stdio.h>

int potega(int a,int b)
{
int  wynik=1;
while(b--)
{
wynik*=a;
}
return wynik;
}


main()
{
int liczba,i,z,x,y,u;
char tab[9];
scanf("%d", &liczba);
i=liczba;

for(z=0;i>0;z++)
      i=i/10;
for(i=0;z>0;z--)
   {x=liczba;
   y=potega(10,z-1);
   u=x/y;
      tab[i]=(u+48);
    liczba=liczba%y;
    i++;
   }
tab[i]='\0';   
puts(tab);
    

}
