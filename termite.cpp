#include "termite.hpp"


#include <stdlib.h>
#include <iostream>


using namespace std;


void initialiseTermite(Termite &termite, int id, Coord position, Direction direction){
  termite.id = id;
  termite.position = position;
  termite.direction = direction;
  termite.porteBrindille = false;
  termite.deplacementAvecBrindille = 0;
  termite.deplacementSansBrindille = MIN_DEPLACEMENTSANSBRINDILLE;
}

Direction directionTermite(Termite termite){
  return termite.direction;
}

Coord devantTermite(Termite termite){
  return devantCoord(termite.position, termite.direction);
}

bool porteBrindille(Termite termite){
  return termite.porteBrindille;
}

void tourneADroite(Termite &termite){
  termite.direction = aDroite(termite.direction);
}

void tourneAGauche(Termite &termite){
  termite.direction = aGauche(termite.direction);
}

void tourneAleat(Termite &termite){
  int r = rand() % 2;
  if (r){
    tourneAGauche(termite);
  }
  else{
    tourneADroite(termite);
  }
}

bool laVoieEstLibre(Grille grille, Termite termite){
  return estVide(grille,devantCoord(termite.position, termite.direction));
}

bool brindilleEnFace(Grille grille, Termite termite){
  return contientBrindille(grille,devantCoord(termite.position, termite.direction));
}

bool Enferme(Grille grille, Termite termite){
  int nb_direction_libre = 0;
  Direction directionDroite = aDroite(termite.direction);
  while(termite.direction != directionDroite){
    if (estVide(grille,devantCoord(termite.position, directionDroite))){
      nb_direction_libre++;
    }
    directionDroite = aDroite(directionDroite);
  }
  if (nb_direction_libre == 0){
    return true;
  }
  return false;
}

void avanceTermite(Grille &grille, Termite &termite){

  //Met à jour l'ancienne case du termite
  grille.tab[getY(termite.position)][getX(termite.position)].termite = false;
  grille.tab[getY(termite.position)][getX(termite.position)].termite_id = -1;

  //Mise à jour de la positition du termite
  termite.position = devantCoord(termite.position, termite.direction);

  //Met à jour la nouvelle case du termite
  grille.tab[getY(termite.position)][getX(termite.position)].termite = true;
  grille.tab[getY(termite.position)][getX(termite.position)].termite_id = termite.id;

  //Mise à jour du compteur de pas du termite
  if (termite.porteBrindille == true){
    termite.deplacementAvecBrindille ++;
  }
  if (termite.porteBrindille == false){
    termite.deplacementSansBrindille ++;
  }
}

void dechargeTermite(Grille &grille, Termite &termite){
  if (Enferme(grille, termite) == false){
    //Ajoute la brindille dans la case devant
    grille.tab[getY(devantCoord(termite.position, termite.direction))][getX(devantCoord(termite.position, termite.direction))].brindille = true;

    //Retire la brindille du termite
    termite.porteBrindille = false;
    termite.deplacementAvecBrindille = 0;
  }
}

void chargeTermite(Grille &grille, Termite &termite){

  //Retire la brindille dans la case devant
  grille.tab[getY(devantCoord(termite.position, termite.direction))][getX(devantCoord(termite.position, termite.direction))].brindille = false;

  //Ajoute la brindille du termite
  termite.porteBrindille = true;
  termite.deplacementSansBrindille = 0;
}

void demiTour(Termite &termite){

  //Traitement des cas dans lequel la termite est dans un des coins de la grille
  if (egalCoord(termite.position,creeCoord(0,0)) && termite.direction == NE){
    tourneADroite(termite);
    tourneADroite(termite);
  }
  else if (egalCoord(termite.position,creeCoord(0,0)) && termite.direction == SO){
    tourneAGauche(termite);
    tourneAGauche(termite);
  }
  else if (egalCoord(termite.position,creeCoord(GRILLE_WIDTH-1,0)) && termite.direction == NO){
    tourneAGauche(termite);
    tourneAGauche(termite);
  }
  else if (egalCoord(termite.position,creeCoord(GRILLE_WIDTH-1,0)) && termite.direction == SE){
    tourneADroite(termite);
    tourneADroite(termite);
  }
  else if (egalCoord(termite.position,creeCoord(0,GRILLE_HEIGHT-1)) && termite.direction == NO){
    tourneADroite(termite);
    tourneADroite(termite);
  }
  else if (egalCoord(termite.position,creeCoord(0,GRILLE_HEIGHT-1)) && termite.direction == SE){
    tourneAGauche(termite);
    tourneAGauche(termite);
  }
  else if (egalCoord(termite.position,creeCoord(GRILLE_WIDTH-1,GRILLE_HEIGHT-1)) && termite.direction == NE){
    tourneAGauche(termite);
    tourneAGauche(termite);
  }
  else if (egalCoord(termite.position,creeCoord(GRILLE_WIDTH-1,GRILLE_HEIGHT-1)) && termite.direction == SO){
    tourneADroite(termite);
    tourneADroite(termite);
  }
  //Traitement des cas dans lequel la termite n'est pas dans un des coins de la grille
  else{
    for (int i = 0; i < 4; i++){
      tourneADroite(termite);
    }
  }
}


void marcheAleatoire(Grille &grille, Termite &termite){

  //Effetue un demi tour si la termite est en limite de grille
  if (pasDansGrille(devantCoord(termite.position, termite.direction))){
    demiTour(termite);
  }

  //Si la voie est libre, dans 9 cas sur 10, le termite avance tout droit
  if (laVoieEstLibre(grille, termite)){
    if(rand()%10 != 0){
      avanceTermite(grille,termite);
    }
    //Sinon il tourne à droite tant que la case enface de lui n'est pas libre
    else{
      termite.direction = aDroite(termite.direction);
      int i = 0;
      while (estVide(grille, devantCoord(termite.position, termite.direction)) == false){
        tourneADroite(termite);
        i++;
        if (i > 8) break;
      }
    }
  }
  //Si la case en face de luit n'est pas libre, il tourne à droite tant que la case enface de lui n'est pas libre
  else{
    int i = 0;
    while (estVide(grille, devantCoord(termite.position, termite.direction)) == false){
      tourneAleat(termite);
      i++;
      if (i > 8) break;
    }
  }
}

void RecupEtPoseBrindille(Grille &grille, Termite &termite){
  //Si il y a une brindille devant et quelle se situe dans le grille
  if (grille.tab[getY(devantCoord(termite.position, termite.direction))][getX(devantCoord(termite.position, termite.direction))].brindille == true && dansGrille(devantCoord(termite.position, termite.direction))){
    //Cas ou la termite prends la brindille
    if (termite.porteBrindille == false && termite.deplacementSansBrindille >= MIN_DEPLACEMENTSANSBRINDILLE){
      chargeTermite(grille, termite);
    }
    else if (termite.porteBrindille == true && termite.deplacementAvecBrindille >= MIN_DEPLACEMENTAVECBRINDILLE){
      //Cas ou la termite depose la termite
      int i = 0;
      while (estVide(grille, devantCoord(termite.position, termite.direction)) == false || dansGrille(devantCoord(termite.position, termite.direction)) == false){
        tourneADroite(termite);
        i++;
        if (i > 8) break;
      }
      dechargeTermite(grille,termite);
    }
  }
}
