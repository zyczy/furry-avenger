#include <iostream>//alg na nww
using namespace std;

main()

{ int a;
int x=0;

      cin  >> a;
      do {if (a%10==2)a=a/10 , x++; a=a/10;} while (a>0);
      if (x>0) cout<<"tak"<<endl;else cout <<"nie"<<endl;
system ("pause");
}
