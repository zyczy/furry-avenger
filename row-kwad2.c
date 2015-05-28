#include<stdio.h>
#include<math.h>


 kwadraty(int a, int b, int c,float* tab) 
{int delta=(b*b)-(4*a*c);
//printf("\n %d \n", delta);
if (delta<0) return (0);
if(delta==0)
   {tab[0]=(-b)/(2*a); 
   tab[1]=(-b)/(2*a);
    return(1); 
	}
tab[0]=(sqrt(delta)-b)/(2*a);

tab[1]=((-sqrt(delta))-b)/(2*a);

return(2);
}
main()
{
int a,b,c;
printf("Podaj wspolczyniki (a,b,c)\n");
scanf("%d", &a);  
scanf("%d", &b);
scanf("%d", &c);
float tab[2];
int x;
x=kwadraty(a,b,c,tab);
if (x==0) printf("\n NULL");
else printf("\n %f \n %f", tab[0],tab[1]);
}
