#pragma once

//Structure du point
struct Coord
{
  int x;
  int y;
};

/** Crée un point ayant pour coordonnées x et y
* @param[in] x et y deux entiers
* @return un point
**/
Coord creeCoord(int x, int y);


/** Affiche les coordonnées d'un point
* @param[in] un point
**/
void afficheCoord(Coord point);


/** Renvoie la composante X des coordonnées d'un point
* @param[in] un point
* @return un entier
**/
int getX(Coord point);


/** Renvoie la composante Y des coordonnées d'un point
* @param[in] un point
* @return un entier
**/
int getY(Coord point);


/** Test si deux point sont égaux
* @param[in] deux point
* @return un booléen
**/
bool egalCoord(Coord point1, Coord point2);


enum Direction { NO, N, NE, E, SE, S, SO, O };


/** Affiche le point cardinal correspondant à une Direction
* @param[in] une direction
**/
void afficheDirection(Direction direction);


/** Renvoie la direction à droite d'une direction donnée
* @param[in] une direction
* @return une direction
**/
Direction aDroite(Direction point);


/** Renvoie la direction à gauche d'une direction donnée
* @param[in] une direction
* @return une direction
**/
Direction aGauche(Direction point);


/** Renvoie le point devant (relatif à la direction) un point donnée
* @param[in] un point, une direction
* @return un point
**/
Coord devantCoord(Coord point, Direction direction);


/** Renvoie le point derriere (relatif à la direction) un point donnée
* @param[in] un point, une direction
* @return un point
**/
Coord derriereCoord(Coord point, Direction direction);
