#ifndef PLANET_H
#define PLANET_H

class Planet{
private:
	int id;
	unsigned int pos;
	unsigned int distance;
	char type;
public:
	Planet(unsigned int,int);
	unsigned int orbit();
	int getID(){ return this->id; }
	unsigned int getDistance(){ return this->distance; }
	unsigned int getPos(){ return this->pos; }
	char getType(){ return this->type; }
	void printPlanetInfo();

	//you may add any additional methods you may need.
};

#endif
