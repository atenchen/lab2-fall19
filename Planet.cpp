#include "Planet.h"
#include <iostream>
#include <cstdlib>

Planet::Planet(unsigned int distance, int id){
  char types[3] = {'h','r','g'};
	this->id = id;
	this->distance = distance%3000;
	this->pos = rand()%360;
	this->type = types[rand()%3];
}

unsigned int Planet::orbit(){
	this->pos = (pos + 1)%360;
	return this->pos;
}

void Planet::printPlanetInfo(){
	std::cout << "Planet ID: " << id << std::endl;
	std::cout << "Position: " << pos << std::endl; 
	std::cout << "Distance: " << distance << std::endl;
	std::cout << "Type:" << type << std::endl;
}
