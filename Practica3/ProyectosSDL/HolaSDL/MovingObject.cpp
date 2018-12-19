#include "MovingObject.h"

using namespace std;

void MovingObject::loadFromFile(ifstream& file) {
	double x, y;
	file >> x >> y;
	veldir = Vector2D(x, y);
	ArkanoidObject::loadFromFile(file);
}
void MovingObject::saveToFile(ofstream& file)
{
	file << veldir.getX() << " " << veldir.getY() << " ";
	ArkanoidObject::saveToFile(file);
}
void MovingObject::update()
{
	 pos =  pos + veldir;
	 ArkanoidObject::update();
}