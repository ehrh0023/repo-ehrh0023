#pragma once

template <class T>
/*! 
	\brief A two dimensional templated vector of the form (x, y)
	\author Dennis Ehrhardt
*/
class Vector2
{
	
public:
	T x;
	T y;

	/*! The default constructor creates a zero vector. */
	Vector2(): x(0), y(0) {}
	
	/*! This constructor requires two parameters: xcoord and ycoord.
		\param xcoord the x coordinate in pixels
		\param posY the y coordinate in pixels
	*/
	Vector2(T xcoord, T ycoord): x(xcoord), y(ycoord) {}

	/*	Example Alternative Constructor to use if argument list is long 
			or stuff beyond initialization is needed
	
	Vector2(T xcoord, T ycoord): 
		x(xcoord), 
		y(ycoord) 
	{
		//other initialization stuff
	}
	*/


	/*! Override == operator to correctly check if vectors are equivalent */
	inline bool operator==(Vector2<T> const&);
	/*! Override != operator to correctly check if vectors are not equivalent */
	inline bool operator!=(Vector2<T> const&);

	/*! Override = operator to set a vector equal to another */
	Vector2<T> operator=(Vector2<T> const&);
	/*! Set x and y of the vector
		\param x the x value
		\param y the y value
		\return The new vector (Vector2)
	*/
	Vector2<T> setValues(T x, T y);
	/*! Sets the Vector to (0,0)
		\return The vector (0,0) (Vector2)
	*/
	Vector2 zero();
	
	/*! Override + operator to correctly add another vector 
		\return The resulting vector (Vector2)
	*/
	Vector2<T> operator+(Vector2<T> const&) const;
	/*! Override += operator to add another vector and set to the result
		\return The resulting vector (Vector2)
	*/
	Vector2<T> operator+=(Vector2<T> const&);
	
	/*! Override - operator to correctly subtract another vector 
		\return The resulting vector (Vector2)
	*/
	Vector2<T> operator-(Vector2<T> const&) const;
	/*! Override -= operator to subtract another vector and set to the result
		\return The resulting vector (Vector2)
	*/
	Vector2<T> operator-=(Vector2<T> const&);
	
	/*! Override * operator to multiply the vector by a scalar
		\return The resulting vector (Vector2)
	*/
	Vector2<T> operator*(T) const;
	/*! Override *= operator to multiply the vector by a scalar and set to the result
		\return The resulting vector (Vector2)
	*/
	Vector2<T> operator*=(T const&);

	/*! Returns the dot product of this dot v
		\param v the second vector
		\return The dot product (float)
	*/
	float dot(Vector2<T> const& v)  const;

	/*! Computes the zcross product between this and vector v
	\param v the second vector
	\return The z component of the zcross product
	*/
	float zcross(Vector2<T> const& v) const;

	/*! Returns the magnitude of the vector
		\return Magnitude (float)
	*/
	float magnitude() const;
	/*! Returns the magnitude squared of the vector
		\return Magnitude squared (float)
	*/
	float magnitudeSquared() const;

	/*! Returns the distance between two vectors
		\param vec the second vector
		\return The distance between the vectors as a (float)
	*/
	float length(Vector2<T> vec) const;
	/*! Returns the distance squared between two vectors
		\param vec the second vector
		\return The distance between the vectors squared (float)
	*/
	float lengthSquared(Vector2<T> vec) const;
	
	/*! Makes the vector have a magnitude of 1
		\return The normalized vector (Vector2)
	*/
	Vector2 normalize();

	/*! Clamps the vector to a maximum magnitude
		\param max the maximum value
		\return The clamped vector (Vector2)
	*/
	Vector2 clamp(T max);
	/*! Clamps the x component of the vector to a maximum
		\param max the maximum value
		\return The clamped vector (Vector2)
	*/
	Vector2 clampX(T max);
	/*! Clamps the y component of the vector to a maximum
		\param max the maximum value
		\return The clamped vector (Vector2)
	*/
	Vector2 clampY(T max);


	/*! Rotates the Vector in radians
		\param angle angle in radians
		\return The rotated vector (Vector2)
	*/
	Vector2 rotate(float);

	/*! Returns the angle between two vectors
	\param v the second vector
	\returns the angle betweem two vectors from -PI to PI
	*/
	float angle(Vector2<T> const& v)  const;

	/*! Returns the magnitude of angle between two vectors
	\param v the second vector
	\returns the angle betweem two vectors from 0 to PI
	*/
	float angleMagnitude(Vector2<T> const& v)  const;

	/*! Rotates the vector by pi radians
		\return The flipped vector (Vector2)
	*/
	Vector2<T> flip();
};

#include "Vector2.cpp"

// Typedef Example: Define a couple of handy Vector2s (Won't work in this file right now. Will look into later)
typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
