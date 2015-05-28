#include<stdio.h>
#include<math.h>


int kwadraty(int a, int b, int c) 
{int delta=(b)*(b)-4*(a)*(c);
float wynik;
if (delta<0) return (0);
if(delta==0)
   {wynik=-b/(2*a); printf("\n %f \n", wynik);
    return(1); 
	}
wynik=(sqrt(delta)-b)/(2*a);
printf("\n %f \n", wynik);
wynik=(-sqrt(delta)-b)/(2*a);
printf("\n %f \n", wynik);
return(2);
}
main()
{
int a,b,c;
printf("Podaj wspolczyniki (a,b,c)\n");
scanf("%d", &a);  
scanf("%d", &b);
scanf("%d", &c);
int x;
x=kwadraty(a,b,c);

printf("\n %d \n",x);
}
