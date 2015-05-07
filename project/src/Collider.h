#ifndef COLLIDER_H
#define COLLIDER_H
#include "Vector2.h"
#include <stdlib.h>

class Entity;

namespace Collision
{
	enum Type
	{
		None,
		AABB
	};
}

class Collider
{
protected:
	Collision::Type type;
	Vector2f& position;
	Entity* parent;

public:
	Collider(Vector2f& pos, Entity* p = NULL)
		:type(Collision::None),
		position(pos),
		parent(p)
	{
	}

	virtual void collide(Collider* col) = 0;
	virtual void boundsCollide() = 0;

	Collision::Type getType()
	{
		return type;
	}

	Vector2f getPosition()
	{
		return position;
	}

	Entity* getParent()
	{
		return parent;
	}

	virtual ~Collider() {}
		
	virtual void clearCollisionData() = 0;
};
#endif

#include "Entity/Entity.h"