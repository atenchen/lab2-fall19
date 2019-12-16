#include "Star.h"
#include "Planet.h"
#include <iostream>
#include <cstdlib>

Star::Star(){
  this->current_planets = 0;
  this->planets = NULL;
  this->next_ID = 0;
}
Star::~Star(){
  for(int i = 0; i < current_planets; i++){
    delete planets[i];
  }
  delete[] planets;
}
int Star::addPlanet(){
  Planet ** newPlanets = new Planet*[current_planets + 1];
  Planet * newPlanet = new Planet(rand()%3001,next_ID++);
  for(int i = 0; i < current_planets;i++){
    newPlanets[i] = planets[i];
    //delete planets[i];
  }
  newPlanets[current_planets++] = newPlanet;
  delete[] planets;
  planets = newPlanets;
  return next_ID - 1;
}

bool Star::removePlanet(int id){
  /* Planet**newPlanets = new Planet*[current_planets-1];
  bool found = false;
  for(int i =0; i< current_planets;i++){
    if(not found and i == current_planets - 1){break;}
    if(planets[i]->getID() == id){
      delete planets[i];
      found = true;
    }
    else{
      if(found){
	newPlanets[i-1] = planets[i];
      }
      else{
	newPlanets[i] = planets[i];
      }
    }
  }
  if(!found){
    delete[] newPlanets;
    return false;
  }
  delete [] planets;
  planets = newPlanets;
  current_planets--;
  return true;
  }*/
  /*
  bool removeID = false;
  int locationID = 0;
  for(int i = 0; i < current_planets; i++){
    if(id == planets[i]->getID()){
      locationID = i;
      removeID = true;
      break;
    }
  }
  if(!removeID){
    return false;
  }
  Planet ** newPlanets = new Planet*[current_planets-1];
  for(int i = 0; i < locationID;i++){
    newPlanets[i] = planets[i];
  }
  for(int i = locationID + 1; i < current_planets;i++){
    newPlanets[i-1] = planets[i];
  }
  delete planets[locationID];
  current_planets--;
  delete[] planets;
  return removeID;
  }*/
  bool removeID = false;
  for(int i = 0; i<current_planets;i++){
    if(id == planets[i]->getID()){
      removeID = true;
      break;
    }
  }
  if(!removeID){
    return false;
  }
  Planet ** newPlanets = new Planet*[current_planets-1];
  int j = 0;
  for(int i = 0; i < current_planets; i++){
    if(id != planets[i]->getID()){
      newPlanets[j]=planets[i];
      j++;
    }
    else{
      delete planets[i];
    }
  }
  delete[] planets;
  planets = newPlanets;
  current_planets--;
  return true;
}


Planet * Star::getPlanet(int iD){
  for(int i = 0; i < current_planets; i++){
    if(iD == planets[i]->getID()){
      return planets[i];
    }
  }
  return NULL;
}

void Star::orbit(){
  for(int i = 0; i < current_planets; i++){
    planets[i]->orbit();
  }
}

void Star::printStarInfo(){
  std::cout << "Current Number of Planets: " << current_planets << std::endl;
  for(int i = 0; i < current_planets; i++){
    planets[i]->printPlanetInfo();
  }
}
