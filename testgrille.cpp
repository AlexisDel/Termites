#include "grille.hpp"
#include <iostream>

using namespace std;

/** Infrastructure de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void testEstVide(Grille grille){
ASSERT(estVide(grille,creeCoord(15,15)) == true);
poseBrindille(grille, creeCoord(15,6));
ASSERT(estVide(grille,creeCoord(15,6)) == false);
}

void testDansGrille(){
  ASSERT(dansGrille(creeCoord(2,15)) == true);
  ASSERT(dansGrille(creeCoord(2,20)) == false);
}

void testBrindille(Grille grille){
  poseBrindille(grille,creeCoord(2,15));
  poseBrindille(grille,creeCoord(2,15));
  enleveBrindille(grille,creeCoord(2,15));
  enleveBrindille(grille,creeCoord(2,15));
}

int main(){
  Grille grille;
  initialiseGrilleVide(grille);
  testEstVide(grille);
  //testDansGrille();
  //testBrindille(grille);
}
