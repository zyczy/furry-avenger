#include <iostream>
using namespace std;
    main() //Jan ZYczkowski i Piotr Rzasa
{
      int a,b;
      cin >>a,b;
int x=b;
      for(; x>=10;a=a*10)
      x=(x/10);
cout <<x;
      int y=a+b;
      for(int p =1;p<=y;p++)
      if(y%p==0) cout<<p<<endl;
      }


