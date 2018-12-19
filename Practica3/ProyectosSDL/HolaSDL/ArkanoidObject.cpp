#include "ArkanoidObject.h"


using namespace std;

void ArkanoidObject::loadFromFile(ifstream& file) {
	double x, y;
	file >> x >> y >> w >> h;
	pos = Vector2D(x, y);
}

void ArkanoidObject::saveToFile(ofstream& file) {
	file << (int)(pos.getX()) << " " << (int)(pos.getY()) << " " << w << " " << h << endl;
}