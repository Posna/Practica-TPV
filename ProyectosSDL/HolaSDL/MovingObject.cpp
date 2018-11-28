#include "MovingObject.h"

using namespace std;

void MovingObject::loadFromFile() {

}
void MovingObject::saveToFile()
{

}
virtual void MovingObject::update()
{
	//Movimiento pos + veldir
	 pos =  pos + veldir;
}