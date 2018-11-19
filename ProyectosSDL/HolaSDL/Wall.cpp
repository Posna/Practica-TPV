#include "Wall.h"
#include <string>

using namespace std;


void Wall::render(){
	GameObject::render(this->t, getRect());
}

bool Wall::enWall(Vector2D p) {
	return ((p.getX() < (pos.getX() + w)) && (p.getX() > pos.getX()) && (p.getY() < (pos.getY() + h) && (p.getY() > pos.getY())));
}

Vector2D Wall::collWall(const SDL_Rect& ballRect, const Vector2D& ballVel) {
	Vector2D collVector = { 0, 0};
	Vector2D p0 = { (double)ballRect.x, (double)ballRect.y }; // top-left
	Vector2D p1 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y }; // top-right
	Vector2D p2 = { (double)ballRect.x, (double)ballRect.y + (double)ballRect.h }; // bottom-left
	Vector2D p3 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y + ballRect.h }; // bottom-right
	if (ballVel.getX() < 0 && ballVel.getY() < 0) {
		if ((enWall(p0))) {
			if ((pos.getY() + h - p0.getY()) <= (pos.getX() + w) - p0.getX())
				collVector = { 0,1 }; // Borde inferior mas cerca de p0
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if (enWall(p1)) {
			collVector = { 0,1 };
		}
		else if (enWall(p2)) collVector = { 1,0 };
	}
	else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
		if (enWall(p1)) {
			if ((pos.getY() + h - p1.getY()) <= (p1.getX() - pos.getX())) // || ballVel.getX() == 0)
				collVector = { 0,1 }; // Borde inferior mas cerca de p1
			else
				collVector = { -1,0 }; // Borde izqdo mas cerca de p1
		}
		else if (enWall(p0)) {
			collVector = { 0,1 };
		}
		else if (enWall(p3)) collVector = { -1,0 };
	}
	else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
		if (enWall(p3)) {
			if (((p3.getY() - pos.getY()) <= (p3.getX() - pos.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p3
			else
				collVector = { -1,0 }; // Borde dcho mas cerca de p3
		}
		else if (enWall(p2)) {
			collVector = { 0,-1 };
		}
		else if (enWall(p1)) collVector = { -1,0 };
	}
	else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
		if (enWall(p2)) {
			if (((p2.getY() - pos.getY()) <= (pos.getX() + w - p2.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p2
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if (enWall(p3)) {
			collVector = { 0,-1 };
		}
		else if (enWall(p0)) collVector = { 1,0 };
	}
	return collVector;
}