# include <iostream>
using namespace std;
main()
{
      //a<b<c<1-100>
  for (int a=1;a<999;a++)
   {for (int b=2;b<1000;b++)
     { for (int c=3;c<1001;c++)    
       {if (a*a + b*b == c*c)
         cout <<a<<" "<<b<<" "<<c<<"\t";
         }
       }
     }
     system("pause");
  }
