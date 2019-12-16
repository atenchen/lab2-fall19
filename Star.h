#ifndef STAR_H
#define STAR_H
#include "Planet.h"

class Star{
 public:
  int current_planets;
  int next_ID;
  Planet ** planets;
  Star();
  ~Star();
  int addPlanet();
  bool removePlanet(int);
  Planet * getPlanet(int);
  void orbit();    
  void printStarInfo();
  unsigned int getCurrentNumPlanets(){ return this->current_planets; }
  //you may add any additional methods you may need.
};

#endif
