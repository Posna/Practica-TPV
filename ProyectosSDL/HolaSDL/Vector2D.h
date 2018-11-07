#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <iostream>
#include <string>

using namespace std;

class Vector2D
{
private:
	double x = 0;
	double y = 0;

public:
	Vector2D() {}
	Vector2D(double x, double y) :
		x(x), y(y) {}
	double getX() const;
	double getY() const;
	void normaliza();
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator-(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& v) const;



};

#endif
