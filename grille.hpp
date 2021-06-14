#pragma once


#include "DEFINITIONS.hpp"
#include "coord.hpp"


//Structure d'une la case de la grille
struct Case{
  bool brindille;
  bool termite;
  int termite_id;

};

//Structure de la grille contenant les cases
struct Grille{
  Case tab[GRILLE_HEIGHT][GRILLE_WIDTH];
};

/** Rempli la grille de case vide (sans brindille ni termite)
* @param[in/out] une grille
**/
void initialiseGrilleVide(Grille &grille);


/** Verifie si un case est vide
* @param[in] une grille, un point
* @return un booléen
**/
bool estVide(Grille grille, Coord position);


/** Verifie si une case donnée est dans la grille
* @param[in] un point
* @return un booléen
**/
bool pasDansGrille(Coord position);


/** Verifie si une case donnée est dans la grille
* @param[in] un point
* @return un booléen
**/
bool dansGrille(Coord position);


/** Verifie si une case donnée contient une brindille
* @param[in] un point
* @return un booléen
**/
bool contientBrindille(Grille grille, Coord position);


/** Verifie si une case donnée contient un termite
* @param[in] un point
* @return un booléen
**/
bool contientTermite(Grille grille, Coord position);


/** Renvoie le numéro du termite se trouvant dans une case donnée
* @param[in] une grille, un point
* @return un entier
**/
int numeroTermite(Grille grille, Coord position);


/** Pose une brindille dans une case donnée
* @param[in/out] une grille, un point
**/
void poseBrindille(Grille &grille, Coord position);


/** Enleve une brindille dans une case donnée
* @param[in/out] une grille, un point
**/
void enleveBrindille(Grille &grille, Coord position);


/** Pose un termite donnée dans une case donnée
* @param[in/out] une grille, un point, un entier (id du termite)
**/
void poseTermite(Grille &grille, Coord position, int id);


/** Enleve un termite donnée d'une case donnée
* @param[in/out] une grille, un point, un entier (id du termite)
**/
void enleveTermite(Grille &grille, Coord position, int id);
