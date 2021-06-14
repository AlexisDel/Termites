#include "coord.hpp"
#include <iostream>

using namespace std;

/** Infrastructure de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void testAfficheCoord(){
  Coord t = creeCoord(5,2);
  afficheCoord(t);
}


void testEgalCoord(){
  Coord p1 = creeCoord(5,2);
  Coord p2 = creeCoord(2,5);
  Coord p3 = creeCoord(5,2);
  Coord p4 = creeCoord(8,4);
  ASSERT(egalCoord(p1,p2)==false);
  ASSERT(egalCoord(p1,p3)==true);
  ASSERT(egalCoord(p2,p4)==false);
}

void testDevantCoord(){
  Coord t = creeCoord(5,2);
  ASSERT(devantCoord(t,N).x == 4 && devantCoord(t,N).y == 2);
  ASSERT(devantCoord(t,SE).x == 6 && devantCoord(t,SE).y == 3);
}

int main(){
  //testAfficheCoord();
  testEgalCoord();
  testDevantCoord();
}
