#include <iostream>
using namespace std;
    main() //Jan ZYczkowski i Piotr Rzasa
{
      int a,b,c,d,e;
      cin >>a>>b>>c>>d>>e;
      if (a%2==b%2) cout<<"No! No! No!";
      else { if (b%2==c%2) cout<<"No! No! No!";
      else { if (c%2==d%2) cout<<"No! No! No!";
      else { if (d%2==e%2) cout<<"No! No! No!";
      else cout<<"Yes! Yes! Yes!";
      }}}


}
