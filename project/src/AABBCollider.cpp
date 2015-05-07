#include "AABBCollider.h"

AABBCollider::AABBCollider(Rect& body, Entity* p)
	:Collider(body.getTopLeft(), p),
	box(body)
{
	type = Collision::AABB;
	clearCollisionData();
}

void AABBCollider::collide(Collider* col)
{
	switch(col->getType())
	{
	case Collision::None:
		box.containsPoint(col->getPosition());
		break;
	case Collision::AABB:
		AABBCollision(dynamic_cast<AABBCollider*>(col));
	}
}

void AABBCollider::boundsCollide()
{
	float velX = 0;
	float velY = 0;

	if (parent != NULL)
	{
		velX = parent->getVelocity().x;
		velY = parent->getVelocity().y;
	}

	if (box.getBottom() + velY < 0)
	{
		if (parent != NULL)
			parent->onCollideDown();
		box.setBottom(0);
		collideDown = true;
	}

	if (box.getTop() + velY >= Drawing::getWindowHeight())
	{
		if (parent != NULL)
			parent->onCollideUp();
		box.setTop(Drawing::getWindowHeight() - 1);
		collideUp = true;
	}


	if (box.getLeft() + velX < 0)
	{
		if (parent != NULL)
			parent->onCollideLeft();
		box.setLeft(0);
		collideLeft = true;
	}


	if (box.getRight() + velY >= Drawing::getWindowWidth())
	{
		if (parent != NULL)
			parent->onCollideRight();
		box.setRight(Drawing::getWindowWidth() - 1);
		collideRight = true;
	}
}

Collision::Type AABBCollider::getType()
{
	return type;
}

Vector2f AABBCollider::getPosition()
{
	return position;
}
		
Rect AABBCollider::getBody()
{
	return box;
}

void AABBCollider::AABBCollision(AABBCollider* col)
{
	float velX = 0;
	float velY = 0;

	if(parent != NULL)
	{
		velX = parent->getVelocity().x;
		velY = parent->getVelocity().y;
	}

	float bottom1 = box.getBottom();
	float bottom2 = col->box.getBottom();
	float top1 = box.getTop();
	float top2 = col->box.getTop();
	float left1 = box.getLeft();
	float left2 = col->box.getLeft();
	float right1 = box.getRight();
	float right2 = col->box.getRight();
	/*
	if ((bottom1 + 1 + velY < top2) &&
		(top1 + velY > bottom2) &&
		(right1 + velX > left2) &&
		(left1 + velX < right2) &&
		bottom1 <= top2) 
	{ 
		if (velY >= 0) 
		{
			if(parent != NULL)
				parent->onCollideDown();
			box.setBottom(top2);
			collideDown = true;
		}
	}
	
	if ((bottom1 + velY < top2) &&
		(top1 - 1 + velY > bottom2) &&
		(right1 + velX > left2) &&
		(left1 + velX < right2) &&
		top1 >= bottom2) 
	{ 
		if (velY <= 0) 
		{
			if(parent != NULL)
				parent->onCollideUp();
			box.setTop(bottom2);
			collideUp = true;
		}
	}
	*/
	if ((bottom1 + velY < top2) &&
		(top1 + velY > bottom2) &&
		(right1 + 1 + velX > left2) &&
		(left1 + velX < right2) &&
		right1 <= left2) 
	{ 
		if (velX >= 0) 
		{
			if(parent != NULL)
				parent->onCollideRight();
			box.setRight(left2);
			collideRight = true;
		}
	}
	
	if ((bottom1 + velY < top2) &&
		(top1 + velY > bottom2) &&
		(right1 + velX > left2) &&
		(left1 - 1 + velX < right2) &&
		left1 >= right2) 
	{ 
		if (velX <= 0) 
		{
			if(parent != NULL)
				parent->onCollideLeft();
			box.setLeft(right2);
			collideLeft = true;
		}
	}		
}
	
void AABBCollider::clearCollisionData()
{
	collideRight = false;
	collideLeft = false;
	collideDown = false;
	collideUp = false;	
}

bool  AABBCollider::getCollideRight()
{
	return collideRight;
}

bool  AABBCollider::getCollideLeft()
{
	return collideLeft;
}

bool  AABBCollider::getCollideDown()
{
	return collideDown;
}

bool  AABBCollider::getCollideUp()
{
	return collideUp;
}