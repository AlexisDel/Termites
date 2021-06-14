#include "DEFINITIONS.hpp"
#include "coord.hpp"
#include "grille.hpp"
#include "termite.hpp"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

/** Affichage graphique de la grille
* @param[in] la grille, les termites
**/
void afficheGrille(Grille grille, Termites termites){
  //Parcour de la grille
  for (int y = 0; y < GRILLE_HEIGHT; y++){
    for (int x = 0; x < GRILLE_WIDTH; x++){

      //Affichage des termites
      if (contientTermite(grille,creeCoord(x,y)) == true){
        Direction dir = termites.tab[grille.tab[y][x].termite_id].direction;
        if (dir == NO || dir == SE  ) cout << "\\";
        else if (dir == N || dir == S) cout << "|";
        else if (dir == NE || dir == SO) cout << "/";
        else if (dir == E || dir == O) cout << "-";
      }
      //Affichage des brindilles
      else if (contientBrindille(grille,creeCoord(x,y)) == true){
        cout << "*";
      }
      //Affichage du vide
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
}


/** Génere un nombre donnée de termite, les stock dans la liste "termites" et les place sur la grille
* @param[in] la grille, les termites
**/
void generationTermite(Termites &termites, Grille grille){
  Termite termite;
  int x;
  int y;
  //Trouve une case vide dans la grille
  for (int i = 0; i < TERMITE_NUMBER; i++){
    do {
      x = rand()%GRILLE_WIDTH;
      y = rand()%GRILLE_HEIGHT;
    }while(estVide(grille, creeCoord(x,y)) == false);

    //Initialise le termite
    initialiseTermite(termite, i, creeCoord(x,y), static_cast<Direction>(rand()%8));
    //Place le termite dans la case trouvé précédemment
    grille.tab[y][x].termite = true;
    grille.tab[y][x].termite_id = i;
    //Stock le termite dans la liste "termites"
    termites.tab[i] = termite;
  }
}


/** Génere un nombre donnée de brindille et les place dans la grille
* @param[in] la grille, les termites
**/
void generationBrindille(Grille &grille){
  int x;
  int y;
  //Trouve une case vide dans la grille
  for (int i = 0; i < BRINDILLE_NUMBER; i++){
    do {
      x = rand()%GRILLE_WIDTH;
      y = rand()%GRILLE_HEIGHT;
    }while(estVide(grille, creeCoord(x,y)) == false);

    poseBrindille(grille,creeCoord(x,y));
  }
}


/** Lit les entrer utilisateur et agit en conséquence
* @param[in] nbPasse
**/
bool getcar(int &nbPasse){
  string input;
  //Lit la saisie de l'utilisateur (sur une ligne)
  getline (cin, input);

  //Mise à jour de nbPasse
  if (input == "*"){
   nbPasse = nbPasse*2;
  }
  else if (input == "/"){
   nbPasse = nbPasse/2;
  }

  //Arrete le programme
  if (input == "."){
   return false;
  }
  return true;
}

int main(){

  //Initialise le seed du random
  srand (time(0));

  //Création et initialisation de la grille
  Grille grille;
  initialiseGrilleVide(grille);

  generationBrindille(grille);

  Termites termites;
  generationTermite(termites, grille);

  int nbPasse;
  cout << "Saisissez le pas souhaité (nbPasse) : " ;
  cin >> nbPasse;

  //Compteur d'itération
  unsigned int iter = 0;

  //Boucle principal
  while(getcar(nbPasse)){
    //Boucle du nombre de passes
    for (int i = 0; i < nbPasse; i++){
      for (int i = 0; i < TERMITE_NUMBER; i++){
        marcheAleatoire(grille, termites.tab[i]);
        RecupEtPoseBrindille(grille, termites.tab[i]);
      }
      iter++;
    }system("clear");
    usleep(10000);
    afficheGrille(grille,termites);
    cout << "nbPasse : " << nbPasse << endl;
  }
  cout << "Iteration : " << iter << endl;
}
