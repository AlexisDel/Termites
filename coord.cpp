#include "coord.hpp"

#include <iostream>

using namespace std;

Coord creeCoord(int x, int y){
  Coord point;
  point.x = x;
  point.y = y;
  return point;
}

void afficheCoord(Coord point){
  cout << "( " << point.x << " ; " << point.y << " )" << endl;
}

int getX(Coord point){
  return point.x;
}

int getY(Coord point){
  return point.y;
}

bool egalCoord(Coord point1, Coord point2){
  return (point1.x == point2.x && point1.y == point2.y);
}

void afficheDirection(Direction direction){
  if (direction == NO) cout << "Nord-Ouest" << endl;
  else if (direction == N) cout << "Nord" << endl;
  else if (direction == NE) cout << "Nord-Est" << endl;
  else if (direction == E) cout << "Est" << endl;
  else if (direction == SE) cout << "Sud-Est" << endl;
  else if (direction == S) cout << "Sud" << endl;
  else if (direction == SO) cout << "Sud-Ouest" << endl;
  else if (direction == O) cout << "Ouest" << endl;
}

Direction aDroite(Direction point){
  switch (point) {
    case NO:
    return N;
    case N:
    return NE;
    case NE:
    return E;
    case E:
    return SE;
    case SE:
    return S;
    case S:
    return SO;
    case SO:
    return O;
    case O:
    return NO;
  }
}

Direction aGauche(Direction point){
  switch (point) {
    case NO:
    return O;
    case O:
    return SO;
    case SO:
    return S;
    case S:
    return SE;
    case SE:
    return E;
    case E:
    return NE;
    case NE:
    return N;
    case N:
    return NO;
  }
}

Coord devantCoord(Coord point, Direction direction){
  switch (direction) {
    case NO:
    return creeCoord( point.x-1, point.y-1);
    case N:
    return creeCoord( point.x, point.y-1);
    case NE:
    return creeCoord( point.x+1, point.y-1);
    case E:
    return creeCoord( point.x+1, point.y);
    case SE:
    return creeCoord( point.x+1, point.y+1);
    case S:
    return creeCoord( point.x, point.y+1);
    case SO:
    return creeCoord( point.x-1, point.y+1);
    case O:
    return creeCoord( point.x-1, point.y);
  }
}

Coord derriereCoord(Coord point, Direction direction){
  switch (direction) {
    case NO:
    return creeCoord( point.x+1, point.y+1);
    case N:
    return creeCoord( point.x, point.y+1);
    case NE:
    return creeCoord( point.x-1, point.y+1);
    case E:
    return creeCoord( point.x-1, point.y);
    case SE:
    return creeCoord( point.x-1, point.y-1);
    case S:
    return creeCoord( point.x, point.y-1);
    case SO:
    return creeCoord( point.x+1, point.y-1);
    case O:
    return creeCoord( point.x+1, point.y);
  }
}
