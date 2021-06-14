#include "grille.hpp"


using namespace std;


void initialiseGrilleVide(Grille &grille){
  for (int y = 0; y < GRILLE_HEIGHT; y++){
    for (int x = 0; x < GRILLE_WIDTH; x++){
      grille.tab[y][x].brindille = false;
      grille.tab[y][x].termite = false;
      grille.tab[y][x].termite_id = -1;
    }
  }
}

bool estVide(Grille grille, Coord position){
  return (grille.tab[position.y][position.x].brindille == false && grille.tab[position.y][position.x].termite == false);
}

bool pasDansGrille(Coord position){
  return (getY(position) < 0  ||  getY(position) >= GRILLE_HEIGHT  ||  getX(position) < 0  ||  getX(position) >= GRILLE_WIDTH-1);
}

bool dansGrille(Coord position){
  return (getY(position) > 0  &&  getY(position) < GRILLE_HEIGHT  &&  getX(position) > 0  &&  getX(position) < GRILLE_WIDTH-1);
}

bool contientBrindille(Grille grille, Coord position){
  return (grille.tab[position.y][position.x].brindille);
}

bool contientTermite(Grille grille, Coord position){
  return (grille.tab[position.y][position.x].termite);
}

int numeroTermite(Grille grille, Coord position){
  return (grille.tab[position.y][position.x].termite_id);
}

void poseBrindille(Grille &grille, Coord position){
  if (estVide(grille,position) == true){
    grille.tab[position.y][position.x].brindille = true;
  }
}

void enleveBrindille(Grille &grille, Coord position){
  grille.tab[position.y][position.x].brindille = false;
}

void poseTermite(Grille &grille, Coord position, int id){
  if (estVide(grille,position) == true){
    grille.tab[position.y][position.x].termite = true;
    grille.tab[position.y][position.x].termite_id = id;
  }
}

void enleveTermite(Grille &grille, Coord position, int id){
  grille.tab[position.y][position.x].termite = false;
  grille.tab[position.y][position.x].termite_id = -1;
}
