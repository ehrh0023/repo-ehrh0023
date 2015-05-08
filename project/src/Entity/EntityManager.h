#ifndef ENTITYMANAGER_h
#define ENTITYMANAGER_h
#include <vector>
#include "Entity.h"

/*! 
	\brief This class is used to manage entities.
	\note EntityManager is a singleton class. 
	\author Dennis Ehrhardt
*/
class EntityManager
{
private:
	std::vector<Entity*> entities;

public:
	static int leftWins;
	static int rightWins;

	/* Entity Manager is a singleton class */
	static EntityManager& getInstance();

	/*! Call the update method of all entities and run collisions */
	void update();
	/*! Draw all of the entities */
	void render();
	
	/*! Add a new entity to the manager
	\param newEntity the new entity to add
	*/
	void add(Entity*);
	
	/*! Clear and delete all Entities in the Manager */
	void clear();

	/*! Get the direction and distance from one entity to another
		\param src the ID of the source object
		\param dst the ID of the destination object
		\returns A the distance and direction (Vector2)
	*/
	Vector2f homingFeedback(int src, int dst);

	/*! Gets the ID of an entity
		\param entity the entity
		\return The ID of the entity, if it exists, -1 if not (unsigned int)
	*/
	unsigned int getEntityID(Entity* entity);

	/*! Gets the entity given an ID
		\param id the id
		\return The entity, if it exists, NULL if not (Entity*)
	*/
	Entity* getEntity(unsigned int id);
	
	/*! Returns false if the entity with the given ID has been deleted
		\param id the id
		\return Return true if the entity still exists, false if deleted
	*/
	bool entityAvailable(unsigned int id);
		

	/*! Checks to see if the entity collides with anything
	\param takes in an Entity to check if it collides with anything
	\return Returns true if it collides with another entity and false if it doesn't
	*/
	bool collideWithAnything(Entity*);

	// Delete the Entities on destruction		
	~EntityManager();

	// collide all of the entities with each other, informing entities to reach as necessary, and have each entity check for collisions with walls
	void collide();	

private:

	EntityManager() {};
	EntityManager(EntityManager const&);
	void operator=(EntityManager const&);

	/*! Delete all entities set for deletion
	*/
	void cull();
};

#endif
