#pragma once


#include "DEFINITIONS.hpp"
#include "coord.hpp"
#include "grille.hpp"


//Structure du termite
struct Termite{
  int id;
  Coord position;
  Direction direction;
  bool porteBrindille;
  int deplacementAvecBrindille;
  int deplacementSansBrindille;
};


//Structure de la liste de termite
struct Termites{
  Termite tab[TERMITE_NUMBER];
};


/** Initialiste un termite
* @param[in/out] un termite, un identifiant, une position, une direction
**/
void initialiseTermite(Termite &termite, int id, Coord position, Direction direction);


/** Renvoie la direction d'un termite
* @param[in] un termite
* @return une direction
**/
Direction directionTermite(Termite termite);


/** Renvoie la position d'un termite
* @param[in] un termite
* @return un point
**/
Coord devantTermite(Termite termite);


/** Test si un termite porte une brindille
* @param[in] un termite
* @return un booléen
**/
bool porteBrindille(Termite termite);


/** Fait tourner le termite à droite
* @param[in/out] un termite
**/
void tourneADroite(Termite &termite);


/** Fait tourner le termite à gauche
* @param[in/out] un termite
**/
void tourneAGauche(Termite &termite);


/** Fait tourner le termite à droite ou à gauche
* @param[in/out] un termite
**/
void tourneAleat(Termite &termite);


/** Test si la case devant le termite est libre
* @param[in] une grille, un termite
* @return un booléen
**/
bool laVoieEstLibre(Grille grille, Termite termite);


/** Test si la case devant le termite contient une brindille
* @param[in] une grille, un termite
* @return un booléen
**/
bool brindilleEnFace(Grille grille, Termite termite);


/** Test si le termite est enfermé
* @param[in] une grille, un termite
* @return un booléen
**/
bool Enferme(Grille grille, Termite termite);


/** Fait avancer le termite
* @param[in/out] une grille, un termite
**/
void avanceTermite(Grille &grille, Termite &termite);


/** Decharge la brindille du termite
* @param[in/out] une grille, un termite
**/
void dechargeTermite(Grille &grille, Termite &termite);


/** Charge la brindille du termite
* @param[in/out] une grille, un termite
**/
void chargeTermite(Grille &grille, Termite &termite);


/** Fait faire un demi tour au termite
* @param[in/out] un termite
**/
void demiTour(Termite &termite);


/** Fait avancer le termite de manière aléatoire
* @param[in/out] une grille, un termite
**/
void marcheAleatoire(Grille &grille, Termite &termite);


/** Recupé ou pose une brindille si possible
* @param[in/out] une grille, un termite
**/
void RecupEtPoseBrindille(Grille &grille, Termite &termite);
