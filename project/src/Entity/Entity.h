#ifndef ENTITY_H
#ifndef COLLIDER_H
#include "../Collider.h"
#else
#define ENTITY_H
#include "../Rect.h"
#include "../Vector2.h"
#include "../Color.h"
#include "../Drawing.h"

#ifndef ENTITYMANAGER_h
class EntityManager;
#endif

/*! 
	\brief This is the base class for all Entities. Robots, targets, and obstacles are all derived from this class. 
	\author Dennis Ehrhardt
	\author Evan Stuempfig
	\author Andrew Hartfiel
	\author David Tran
*/
class Entity
{
protected:
	Rect body;
	Vector2f orientation;
	float rotation;
	int speed;
	Vector2f velocity;
	unsigned int entityID;
	bool setForDeletion;
	Color rgb;
	Collider* collider;
	
public:
	/*! This constructor requires three parameters: x position, y position, and radius.
		\param posX the x position in pixels
		\param posY the y position in pixels
		\param radius the radius in pixels
	*/
	Entity(int posX, int posY, int width, int height);

	/*! This constructor requires two parameters: location and radius.
		\param location the x and y position in pixels as a Vector2
		\param radius the radius in pixels
	*/
	Entity(Vector2f topleft, int width, int height);

	virtual ~Entity() {}

	/*! Update the entity's position and behavior
	*/
	virtual void update();

	/*! Draw the entity on the screen
	*/
	virtual void render();
	
	/*! Shift the entity to a new position
		\param shift how much to shift the entity by in pixels as a Vector2
	*/
	void translate(Vector2<int> const& shift);

	/*! Shift the entity to a new position
		\param shift how much to shift the entity by in pixels as a Vector2
	*/
	void translate(Vector2f const& shift);

	/*! Shift the entity to a new position
		\param xShift how much to shift the entity in the x direction in pixels
		\param yShift how much to shift the entity in the y direction in pixels
	*/
	void translate(int x, int y);
	
	/*! Rotate the entity's orientation in degrees
		\param angle how much to rotate the entity in degrees
	*/
	void rotate(float angle);

	/*! Rotate the entity's orientation
		\param angle how much to rotate the entity in radians
	*/
	void rotateRad(float angle);

	
	/*! Get the position of the center
		\return The position (Vector2)
	*/
	Vector2f getPosition() const;

	/*! Set the position of the center
		\param newPosition the new position of the center
	*/
	void setPosition(Vector2f const&);

	/*! Get the orientation of the entity
		\return The orientation (Vector2)
	*/
	Vector2f getOrientation () const;

	/*! Set the orientation of entity
		\param newOrientation the new orientation of the entity
	*/
	void setOrientation(Vector2f const&);

	/*! Get the current speed in pixels per second
		\return The speed (int)
	*/
	
	float getRotation () const;

	/*! Set the rotation of entity
		\param newRotation the new rotation of the entity
	*/
	void setRotation(float);

	/*! Get the current speed in pixels per second
		\return The speed (int)
	*/	

	int getSpeed() const;

	/*! Set the current speed in pixels per second
		\param newSpeed the new speed of the entity
		\note values below 0 are rounded to 0
	*/
	void setSpeed(int);
	
	/*! Get the velocity of the entity in pixels per second
		\return The velocity (Vector2)
	*/
	Vector2f getVelocity() const;

	/*! Set the velocity of the entity in pixels per second
		\param newVelocity the new velocity of the entity
	*/
	void setVelocity(Vector2f const&);
	
	/*! Check if there is a collision with another entity
		\param otherEntity the other entity
		\return True if collided, False otherwise
	*/
	bool collide(Entity* otherEntity);

	/*! Check that the entity is within the bounds of the map if it is not in bounds, it is brought in bounds
		\return False if out of bounds and brought back, True if originally in bounds
	*/
	bool boundsCheck();

	/*! Get the ID of the entity
	\return The ID (int)
	*/
	unsigned int getID();
	
	/*! Change the color of the entity
		\param newColor the new color of the entity
	*/
	
	void setColor(Color newColor);

	/*! Get the color of the entity as RGB floats
		\return The color makeup of the entity
	*/
	Color getColor();

/*	float getRed();
	float getGreen();
	float getBlue();
*/

	/*! Tell the EntityManager to delete this object
	*/
	void markForDeletion();

	/*! Called when this entity collides with another
		\param otherEntity the other entity
	*/
	virtual void onCollide(Entity* otherEntity);

private:
	/*! Give the entity an ID
	\param the new ID of the entity
	*/
	void setID(unsigned int);
	
	friend class EntityManager;
};


#include "../Collider.h"

#endif
#endif