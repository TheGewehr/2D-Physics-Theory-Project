#ifndef __2DVECTOR_H__
#define __2DVECTOR_H__

//using namespace std;

#include <math.h>

template<class TYPE>

class Vector2D
{
public:

	TYPE x, y; // Variables

	// Constructors

	Vector2D() {

	};

	Vector2D(const Vector2D& vect2d)
	{
		x = vect2d.x;
		y = vect2d.y;
		
	}

	Vector2D(const double val1, const double val2)
	{
		x = val1;
		y = val2;
	}

	// Set the operators

	Vector2D operator -(const Vector2D& v)
	{

		x = x - v.x;
		y = y - v.y;

		return(*this);

	}

	Vector2D operator =(const Vector2D& v)
	{

		x = v.x;
		y = v.y;
		

		return(*this);
	}

	Vector2D operator +(const Vector2D& v)
	{


		x = x + v.x;
		y = y + v.y;
		

		return(*this);

	}

	const Vector2D& operator -=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
		

		return(*this);
	}

	const Vector2D& operator +=(const Vector2D& v)
	{
		x += v.x;
		y += v.y;
		

		return(*this);
	}

	bool operator ==(const Vector2D& v) const
	{
		return (x == v.x && y == v.y );
	}

	bool operator !=(const Vector2D& v) const
	{
		return (x != v.x || y != v.y );
	}

	const Vector2D& operator *(const int v)
	{
		x = x * v;
		y = y * v;
		

		return(*this);
	}

	// Usefull methods

	bool IsZero() const  // Verify if the vector is null
	{
		return (x == 0 && y == 0 );
	}

	Vector2D& SetToZero() // Sets the vector to zero
	{
		x = y = 0;
		return(*this);
	}

	Vector2D& Normalize() // Normalize the vector
	{
		x = y = 1;
		return(*this);
	}

	Vector2D& Negate() // Negates the vector
	{
		x = -x;
		y = -y;
		

		return(*this);
	}

	TYPE DistanceTo(const Vector2D v) const // Mesures the scalar distance between vectors
	{
		TYPE fx = x - v.x;
		TYPE fy = y - v.y;
		

		return (TYPE)sqrt((fx * fx) + (fy * fy));
	}

	//Vector2D<double> Vector01;

};

#endif 
