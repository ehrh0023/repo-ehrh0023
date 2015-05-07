#pragma once
#include "Collider.h"
#include "Rect.h"

class AABBCollider: public Collider
{
	Rect& box;
	bool collideRight;
	bool collideLeft;
	bool collideDown;
	bool collideUp;

public:
	AABBCollider(Rect& body, Entity* p = NULL);

	void collide(Collider* col);
	void boundsCollide();
	void AABBCollision(AABBCollider* col);

	Collision::Type getType();

	Vector2f getPosition();
	Rect getBody();
	
	void clearCollisionData();
	bool getCollideRight();
	bool getCollideLeft();
	bool getCollideDown();
	bool getCollideUp();
};