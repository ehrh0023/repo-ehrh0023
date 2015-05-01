#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>

// Author: Dennis Ehrhardt (all methods in Vector2)
template <class T>
bool Vector2<T>::operator==(Vector2<T> const& vec)
{
	// Check if vectors are equal
	return x == vec.x && y == vec.y;
}

template <class T>
bool Vector2<T>::operator!=(Vector2<T> const& vec)
{
	// Check if vectors are not equal
	return x != vec.x || y != vec.y;
}	
template <class T>
Vector2<T> Vector2<T>::operator=(Vector2<T> const& v)
{
	// Set this equal to another vector
	x = v.x;
	y = v.y;
		
	return *this;
}
	
template <class T>
Vector2<T> Vector2<T>::setValues(T x, T y)
{
	// Set x and y of the vector
	this->x = x;
	this->y = y;

	return *this;
}

template <class T>
Vector2<T> Vector2<T>::zero() 
{
	// Sets the Vector to (0,0)
	x = 0;
	y = 0;

	return *this;
}

template <class T>
Vector2<T> Vector2<T>::operator+(Vector2<T> const& v) const
{
	// Add with another vector and return the result
	Vector2<T> vec;
		
	vec.x = x + v.x;
	vec.y = y + v.y;

	return vec;
}

template <class T>
Vector2<T> Vector2<T>::operator+=(Vector2<T> const& v)
{
	// Add and set equal to the result with another vector and return the result
	x += v.x;
	y += v.y;
	return *this;
}

template <class T>	
Vector2<T> Vector2<T>::operator-(Vector2<T> const& v) const
{
	// Subtract with another vector and return the result
	Vector2<T> vec;
		
	vec.x = x - v.x;
	vec.y = y - v.y;

	return vec;
}

template <class T>
Vector2<T> Vector2<T>::operator-=(Vector2<T> const& v)
{
	// Subtract and set equal to the result with another vector and return the result
	x -= v.x;
	y -= v.y;
	return *this;
}
		
template <class T>
Vector2<T> Vector2<T>::operator*(T scalar) const
{
	// Multiply with a scalar and return the result
	Vector2<T> vec;
		
	vec.x = x * scalar;
	vec.y = y * scalar;

	return vec;
}
	
template <class T>
Vector2<T> Vector2<T>::operator*=(T const& scalar)
{
	// Multiply and set equal to the result with a scalar and return the result
	x *= scalar;
	y *= scalar;
	return *this;
}

template <class T>
float Vector2<T>::dot(Vector2<T> const& v) const
{
	// Returns the dot product of this dot v
	return x * v.x + y * v.y;
}


template <class T>
float Vector2<T>::zcross(Vector2<T> const& v) const
{
	return x*v.y - v.x*y;
}

template <class T>
float Vector2<T>::magnitude() const
{
	// Returns the magnitude of the vector
	return sqrt(x*x + y*y);
}

template <class T>
float Vector2<T>::magnitudeSquared() const
{
	// Returns the magnitude squared of the vector
	return x*x + y*y;
}

template <class T>
float Vector2<T>::length(Vector2<T> vec) const
{
	// Returns the distance between two vectors
	return (*this - vec).magnitude();
}

template <class T>
float Vector2<T>::lengthSquared(Vector2<T> vec) const
{
	// Returns the distance squared between two vectors
	return (*this - vec).magnitudeSquared();
}

template <class T>
Vector2<T> Vector2<T>::normalize()
{
	// Makes the vector have a magnitude of 1
	float currentMagnitude =  magnitude();
	
	if(currentMagnitude)
	{
		*this *= 1.0f / currentMagnitude;
	}

	return *this;
}

template <class T>
Vector2<T> Vector2<T>::clamp(T max)
{
	// Clamps the vector to a max
	T currentMagnitude =  magnitude();
	
	if (currentMagnitude && (currentMagnitude > max))
	{
		*this *= max / currentMagnitude;
	}

	return *this;
}

template <class T>
Vector2<T> Vector2<T>::clampX(T max)
{
	// Clamps the x part of the vector to a max
	T currentMagnitude =  abs(x);
	
	if (currentMagnitude && (currentMagnitude > max))
	{
		x *= max / x;
	}

	return *this;
}

template <class T>
Vector2<T> Vector2<T>::clampY(T max)
{
	// Clamps the y part of the vector to a max
	T currentMagnitude =  abs(y);
	
	if (currentMagnitude && (currentMagnitude > max))
	{
		y *= max / y;
	}

	return *this;
}

template <class T>
Vector2<T> Vector2<T>::rotate(float angle) 
{
	//Rotates the Vector by angle radians
	float x0 = x;
	float y0 = y;

	x = x0 * cos(angle) - y0 * sin(angle);
	y = x0 * sin(angle) + y0 * cos(angle);

	return *this;
}

template <class T>
float Vector2<T>::angle(Vector2<T> const& v) const
{
	float l1 = magnitude();
	float l2 = v.magnitude();
	float l12 = l1 * l2;
	if (l12 == 0)
		l12 = .00001;

	float rotation = acos(dot(v) / l12);
	
	if (zcross(v) < 0)
		rotation = -rotation;
	
	return rotation;
}

template <class T>
float Vector2<T>::angleMagnitude(Vector2<T> const& v) const
{
	float l1 = magnitude();
	float l2 = v.magnitude();
	float l12 = l1 * l2;
	if (l12 == 0)
		l12 = .00001;
	float rotation = acos(dot(v) / (l12));
	return acos(dot(v));
}

template <class T>
Vector2<T> Vector2<T>::flip()
{
	return *this *=- 1;
}
	
