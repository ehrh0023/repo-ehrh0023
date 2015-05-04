#include "EntityManager.h"
#include "Obstacle.h"
#include <cstddef>
#include <iostream>

//Entity Manager is a singleton class
// Author: Dennis Ehrhardt (all methods in EntityManager)
EntityManager& EntityManager::getInstance()
{
	static EntityManager instance;
	return instance;
}

// Call the update method of all entities and run collisions
void EntityManager::update()
{
	cull();
	collide();
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			entities[i]->update();
		}
	}
}
// Draw all of the entities
void EntityManager::render()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			entities[i]->render();
		}
	}
}
// Add a new entity to the manager
void EntityManager::add(Entity* entity)
{
	if (entity != NULL)
	{
		entity->setID(entities.size());
		entities.push_back(entity);
	}
}

// Clear and delete all Entities in the Manager
void EntityManager::clear()
{
	for(unsigned int i = 0; i < entities.size(); i++)
	{
		if(entities[i] != NULL)
		{
			delete entities[i];
		}
	}
	
	entities.clear();
}

// Author: Andrew Hartfiel
// Get distance and direction between two objects
Vector2f EntityManager::homingFeedback(int src, int dst)
{
	if (src >= (int)entities.size() || dst >= (int)entities.size())
	{
		Vector2f fail(0,0);
		std::cout << src << ", " << dst << ", " << entities.size() << std::endl;
		return fail;
	}
	Vector2f srcPos = entities[src]->getPosition();
	Vector2f dstPos = entities[dst]->getPosition();
	Vector2f diff(dstPos.x - srcPos.x, dstPos.y - srcPos.y);
	return diff;
}

// Author: Andrew Hartfiel
// Get the Entity ID from an entity, -1 if not in vector
unsigned int EntityManager::getEntityID(Entity* entity)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i] == entity)
		{
			return i;
		}
	}
	return -1;
}

// Author: Andrew Hartfiel
// Get the Entity* from the ID, NULL if not valid
Entity* EntityManager::getEntity(unsigned int id)
{
	if (id < entities.size())
	{
		return entities[id];		
	}
	return NULL;
}

// Author: Andrew Hartfiel
// Check if the entity with the given ID was deleted
bool EntityManager::entityAvailable(unsigned int id)
{
	if ((id < entities.size()) && (entities[id] != NULL))
	{
		return true;
	}
	return false;
}
		 
// Delete the Entities on destruction		
EntityManager::~EntityManager() 
{
	clear();
};																																																						 

// Author: Evan Stuempfig & Dennis Ehrhardt
// collide all of the entities with each other and the walls
void EntityManager::collide()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i] != NULL)
		{
			for (unsigned int j = i + 1; j < entities.size(); j++)
			{
				if (entities[j] != NULL)
				{
					entities[i]->collide(entities[j]);
					entities[j]->collide(entities[i]);
				}
			}
		}
	}
}

// Author: Dennis Ehrhardt
// Check to see if the entity collides with anything
bool EntityManager::collideWithAnything(Entity* entity)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i] != NULL && entity != entities[i] && entity->body.overlaps(entities[i]->body))
		{
			return true;
		}
	}
	return false;
}


// Author: Dennis Ehrhardt
// Delete an entity set for deletion
void EntityManager::cull()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i] != NULL && entities[i]->setForDeletion)
		{
			delete entities[i];
			entities[i] = NULL;
		}
	}

}
