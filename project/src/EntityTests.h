#pragma once

#include <cxxtest/TestSuite.h>

#include "../src/Entity/Entity.h"
#include "../src/Entity/RobotClass.h"
#include "../src/Entity/Target.h"
#include "../src/Entity/Obstacle.h"
#include "../src/Entity/EntityManager.h"
#include <math.h>

using namespace std;

class EntityTests : public CxxTest::TestSuite
{
	public:
		// Author: Andrew Hartfiel
		void Test_Get_Set_Orientation()
		{
			const float floatError = .001;

			// Ensure initial orientation is correct for 3 arg constructor.
			Entity ent1(30, 40, 5);
			Vector2<float> orientBase(1, 0);
			TS_ASSERT_DELTA(ent1.getOrientation().x, orientBase.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, orientBase.y, floatError);
			
			// Create orientation vectors
			Entity ent2(20, 22, 1);
			Vector2<float> orient1(2.4, 3.1);
			Vector2<float> orient1c = orient1;
			orient1c.normalize();

			Vector2<float> orient2(-1.5, 3.1);
			Vector2<float> orient2c = orient2;
			orient2c.normalize();

			Vector2<float> orient3(61.2, -11.5);
			Vector2<float> orient3c = orient3;
			orient3c.normalize();

			Vector2<float> orient4(-12.5, -1.6);
			Vector2<float> orient4c = orient4;
			orient4c.normalize();

			Vector2<float> orient5(0, 0);
			Vector2<float> orient5c = orient5;
			orient5c.normalize();
			
			// Run tests
			ent2.setOrientation(orient1);
			TS_ASSERT_DELTA(ent2.getOrientation().x, orient1c.x, floatError);
			TS_ASSERT_DELTA(ent2.getOrientation().y, orient1c.y, floatError);

			ent2.setOrientation(orient2);
			TS_ASSERT_DELTA(ent2.getOrientation().x, orient2c.x, floatError);
			TS_ASSERT_DELTA(ent2.getOrientation().y, orient2c.y, floatError);


			ent2.setOrientation(orient3);
			TS_ASSERT_DELTA(ent2.getOrientation().x, orient3c.x, floatError);
			TS_ASSERT_DELTA(ent2.getOrientation().y, orient3c.y, floatError);


			ent2.setOrientation(orient4);
			TS_ASSERT_DELTA(ent2.getOrientation().x, orient4c.x, floatError);
			TS_ASSERT_DELTA(ent2.getOrientation().y, orient4c.y, floatError);

			ent2.setOrientation(orient5);
			TS_ASSERT_DELTA(ent2.getOrientation().x, orient5c.x, floatError);
			TS_ASSERT_DELTA(ent2.getOrientation().y, orient5c.y, floatError);


			ent2.setOrientation(orient2);
			TS_ASSERT_DELTA(ent2.getOrientation().x, orient2c.x, floatError);
			TS_ASSERT_DELTA(ent2.getOrientation().y, orient2c.y, floatError);

		}

		// Author: Andrew Hartfiel
		void Test_Rotate_Rad()
		{
			// Allow error less than .001, due to using float values
			const float floatError = .001;
			
			// Establish the definition of PI
			const float PI = 3.14159265359;

			// Create entity and vectors
			Entity ent1(55, 61, 14);
			// PI/2 radians
			Vector2<float> rot(1, 0);
			// PI radians
			Vector2<float> rot1(0, 1);
			// (3*PI)/2 radians
			Vector2<float> rot2(-1, 0);
			// 0 radians
			Vector2<float> rot3(0, -1);
			// (3*PI)/4 radians
			Vector2<float> rot4(sqrt(2)/2, sqrt(2)/2);
			// PI/3 radians
			Vector2<float> rot5(sqrt(3)/2, -0.5);
			
			
			// Run tests
			
			// Starts at PI/2 radians
			// Rotate PI/2 radians, now PI radians
			ent1.rotateRad(PI/2);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot1.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot1.y, floatError);

			// Rotate PI/2 radians, now (3*PI)/2 radians
			ent1.rotateRad(PI/2);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot2.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot2.y, floatError);

			// Rotate PI/2 radians, now 0 radians; ensures that a cycle is made
			ent1.rotateRad(PI/2);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot3.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot3.y, floatError);

			// Rotate PI/2 radians, now PI/2 radians
			ent1.rotateRad(PI/2);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate -PI/2 radians, now 0 radians; ensures that negative rotations function
			ent1.rotateRad(-PI/2);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot3.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot3.y, floatError);

			// Rotate -PI radians, now PI radians
			ent1.rotateRad(-PI);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot1.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot1.y, floatError);

			// Rotate -PI/4 radians, now (3*PI)/4 radians; ensures non-multiples of PI/2 radians turns can be made
			ent1.rotateRad(-PI/4);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot4.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot4.y, floatError);

			// Rotate -PI/4 radians, now PI/2 radians
			ent1.rotateRad(-PI/4);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate 2*PI radians, now PI/2 radians; ensures a full cycle is 2*PI radians
			ent1.rotateRad(2*PI);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate -2*PI radians, now PI/2 radians; ensures a full cycle is also -2*PI radians
			ent1.rotateRad(-2*PI);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate -PI/6 radians, now PI/3 radians; further tests non-multiples of PI/2 radians
			ent1.rotateRad(-PI/6);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot5.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot5.y, floatError);
		}

		// Author: Andrew Hartfiel
		void Test_Rotate()
		{
			// Allow error less than .001, due to using float values
			const float floatError = .001;

			// Create entity and vectors
			Entity ent1(55, 61, 14);
			// 90 degrees
			Vector2<float> rot(1, 0);
			// 180 degrees
			Vector2<float> rot1(0, 1);
			// 270 degrees
			Vector2<float> rot2(-1, 0);
			// 0 degrees
			Vector2<float> rot3(0, -1);
			// 135 degrees
			Vector2<float> rot4(sqrt(2)/2, sqrt(2)/2);
			// 60 degrees
			Vector2<float> rot5(sqrt(3)/2, -0.5);
			
			
			// Run tests
			
			// Starts at 90 degrees
			// Rotate 90 degrees, now 180 degrees
			ent1.rotate(90);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot1.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot1.y, floatError);

			// Rotate 90 degrees, now 270 degrees
			ent1.rotate(90);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot2.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot2.y, floatError);

			// Rotate 90 degrees, now 0 degrees; ensures that a cycle is made
			ent1.rotate(90);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot3.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot3.y, floatError);

			// Rotate 90 degrees, now 90 degrees
			ent1.rotate(90);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate -90 degrees, now 0 degrees; ensures that negative rotations function
			ent1.rotate(-90);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot3.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot3.y, floatError);

			// Rotate -180 degrees, now 180 degrees
			ent1.rotate(-180);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot1.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot1.y, floatError);

			// Rotate -45 degrees, now 135 degrees; ensures non-multiples of 90 degree turns can be made
			ent1.rotate(-45);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot4.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot4.y, floatError);

			// Rotate -45 degrees, now 90 degrees
			ent1.rotate(-45);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate 360 degrees, now 90 degrees; ensures a full cycle is 360 degrees
			ent1.rotate(360);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate -360 degrees, now 90 degrees; ensures that a full cycle is also -360 degrees
			ent1.rotate(-360);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot.y, floatError);

			// Rotate -30 degrees, now 60 degrees; further tests non-multiples of 90 degrees
			ent1.rotate(-30);
			TS_ASSERT_DELTA(ent1.getOrientation().x, rot5.x, floatError);
			TS_ASSERT_DELTA(ent1.getOrientation().y, rot5.y, floatError);
		}

		// Author: Andrew Hartfiel
		void Test_Translate_Int_Vec()
		{
			// Create entity and vectors
			Entity ent1(112, 104, 11);
			Vector2<int> t1(0, 0);
			Vector2<int> t2(0, -1);
			Vector2<int> t3(0, 1);
			Vector2<int> t4(-1, 0);
			Vector2<int> t5(1, 0);
			Vector2<int> t6(-3, 12);
			
			// Run tests
			
			// Test moving by 0 vector, ensure no movement is made
			ent1.translate(t1);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving downward
			ent1.translate(t2);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 103);

			// Test moving upward
			ent1.translate(t3);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving leftward
			ent1.translate(t4);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 111);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving rightward
			ent1.translate(t5);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving an arbitrary amount
			ent1.translate(t6);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 109);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 116);
		}
		
		// Author: Andrew Hartfiel
		// These currently fail due to position being stored as integers
		void Test_Translate_Float_Vec()
		{
			// Create entity and vectors
			Entity ent1(112, 104, 11);
			Vector2<float> t1(0, 0);
			Vector2<float> t2(0, -1.5);
			Vector2<float> t3(0, 1.5);
			Vector2<float> t4(-1.5, 0);
			Vector2<float> t5(1.5, 0);
			Vector2<float> t6(-3.5, 12.5);
			
			// Run tests
			
			// Test moving by 0 vector, ensure no movement is made
			ent1.translate(t1);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving downward
			ent1.translate(t2);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 102.5);

			// Test moving upward
			ent1.translate(t3);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving leftward
			ent1.translate(t4);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 110.5);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving rightward
			ent1.translate(t5);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving an arbitrary amount
			ent1.translate(t6);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 108.5);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 116.5);
		}

		// Author: Andrew Hartfiel
		void Test_Translate_Comp()
		{
			// Create entity
			Entity ent1(112, 104, 11);
			
			// Run tests
			
			// Test moving by 0 in both directions, ensure no movement is made
			ent1.translate(0, 0);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving downward
			ent1.translate(0, -1);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 103);

			// Test moving upward
			ent1.translate(0, 1);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving leftward
			ent1.translate(-1, 0);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 111);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving rightward
			ent1.translate(1, 0);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 112);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 104);

			// Test moving an arbitrary amount
			ent1.translate(-3, 12);
			TS_ASSERT_EQUALS(ent1.getPosition().x, 109);
			TS_ASSERT_EQUALS(ent1.getPosition().y, 116);
		}
		
		// Author: David Tran
		void Test_Get_Set_Radius()
		{
			// Create entity
			Entity ent1(200, 200, 10);
			
			// Run tests
			TS_ASSERT_EQUALS(ent1.getRadius(), 10);
			
			ent1.setRadius(15);
			TS_ASSERT_EQUALS(ent1.getRadius(), 15);
			
			ent1.setRadius(0);
			TS_ASSERT_EQUALS(ent1.getRadius(), 0);
			
			ent1.setRadius(100);
			TS_ASSERT_EQUALS(ent1.getRadius(), 100);
		}
		
		// Author: David Tran
		void Test_Get_Set_Speed()
		{
			// Create entity
			Entity ent1(200, 200, 10);
			
			// Run tests
			ent1.setSpeed(0);
			TS_ASSERT_EQUALS(ent1.getSpeed(),0);
			
			ent1.setSpeed(-5);
			TS_ASSERT_EQUALS(ent1.getSpeed(),0);
			
			ent1.setSpeed(5);
			TS_ASSERT_EQUALS(ent1.getSpeed(),5);
			
			ent1.setSpeed(121);
			TS_ASSERT_EQUALS(ent1.getSpeed(),121);
		}
		
		// Author: David Tran
		void Test_Get_Set_Velocity()
		{
			// Create entity
			Entity ent1(200, 200, 10);
			
			// Create vectors
			Vector2<float> v1(0, 0);
			Vector2<float> v2(-5, 0);
			Vector2<float> v3(0, -5);
			Vector2<float> v4(10, 0);
			Vector2<float> v5(0, 10);
			Vector2<float> v6(-15, 15);
			Vector2<float> v7(15, -15);
			Vector2<float> v8(-20, -20);
			Vector2<float> v9(20, 20);
			
			// Run tests
			ent1.setVelocity(v1);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v1.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v1.y);
			
			ent1.setVelocity(v2);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v2.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v2.y);
			
			ent1.setVelocity(v3);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v3.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v3.y);
			
			ent1.setVelocity(v4);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v4.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v4.y);
			
			ent1.setVelocity(v5);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v5.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v5.y);
			
			ent1.setVelocity(v6);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v6.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v6.y);
			
			ent1.setVelocity(v7);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v7.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v7.y);
			
			ent1.setVelocity(v8);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v8.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v8.y);
			
			ent1.setVelocity(v9);
			TS_ASSERT_EQUALS(ent1.getVelocity().x, v9.x);
			TS_ASSERT_EQUALS(ent1.getVelocity().y, v9.y);
		}
		
		// Author: Evan Stuempfig
		// This test assumes a hard-coded window size for now; this may change in future iterations
		void Test_BoundsCheck()
		{
			// Create entity instances
			Entity ent1(10, 10, 20);
			Entity ent2(20, 10, 15);
			Entity ent3(10, 10, 10);
			Entity ent4(790, 890, 20);
			Entity ent5(780, 790, 15);
			Entity ent6(790, 790, 10);
			Entity ent7(50, 50, 20);
				
			
			// Run Tests
			// Both origin axes overlap
			TS_ASSERT_EQUALS(ent1.boundsCheck(), false);
			// One origin axis overlaps
			TS_ASSERT_EQUALS(ent2.boundsCheck(), false);
			// Both origin axes contact
			TS_ASSERT_EQUALS(ent3.boundsCheck(), true);
			// Both upper-bounds axes overlap
			TS_ASSERT_EQUALS(ent4.boundsCheck(), false);
			// One upper-bounds axis overlaps
			TS_ASSERT_EQUALS(ent5.boundsCheck(), false);
			// Both upper-bounds axes contact
			TS_ASSERT_EQUALS(ent6.boundsCheck(), true);
			// No border overlaps
			TS_ASSERT_EQUALS(ent7.boundsCheck(), true);
					
		}
		
		
		// Author: Evan Stuempfig
		void Test_Wall_Collide()
		{
			// Create entity instances and add them to EntityManager
			EntityManager::getInstance().clear();
			Entity* ent1 = new Entity(200, 200, 10);
			Entity* ent2 = new Entity(5, 200, 10);
			Entity* ent3 = new Entity(200, 5, 10);
			Entity* ent4 = new Entity(795, 200, 10);
			Entity* ent5 = new Entity(200, 795, 10);
			EntityManager::getInstance().add(ent1);
			EntityManager::getInstance().add(ent2);
			EntityManager::getInstance().add(ent3);
			EntityManager::getInstance().add(ent4);
			EntityManager::getInstance().add(ent5);

			
			// Run tests
			// ent1 does not collide with walls
			ent1->wallCollide();
			TS_ASSERT_EQUALS(ent1->getPosition().x, 200);
			TS_ASSERT_EQUALS(ent1->getPosition().y, 200);
			// ent2 collides with the left wall
			ent2->wallCollide();
			TS_ASSERT_EQUALS(ent2->getPosition().x, 10);
			TS_ASSERT_EQUALS(ent2->getPosition().y, 200);
			// ent3 collides with the top wall
			ent3->wallCollide();
			TS_ASSERT_EQUALS(ent3->getPosition().x, 200);
			TS_ASSERT_EQUALS(ent3->getPosition().y, 10);
			// ent4 collides with the right wall
			ent4->wallCollide();
			TS_ASSERT_EQUALS(ent4->getPosition().x, 790);
			TS_ASSERT_EQUALS(ent4->getPosition().y, 200);
			// ent5 collides with the bottom wall
			ent5->wallCollide();
			TS_ASSERT_EQUALS(ent5->getPosition().x, 200);
			TS_ASSERT_EQUALS(ent5->getPosition().y, 790);

			EntityManager::getInstance().clear();	
		}
		
		// Author: Evan Stuempfig
		void Test_Collide()
		{
			// Create entity instances
			Entity ent1(200, 200, 10);
			Entity ent2(200, 200, 10);
			Entity ent3(200, 200, 5);
			Entity ent4(195, 200, 5);
			Entity ent5(185, 200, 5);
			Entity ent6(184, 200, 5);
			Entity ent7(250, 250, 10);

			// Run tests
			// ent1 and ent2 are identical circles
			TS_ASSERT_EQUALS(ent1.collide(&ent2), true);
			TS_ASSERT_EQUALS(ent2.collide(&ent1), true);
			// ent3 is entirely contained in ent1
			TS_ASSERT_EQUALS(ent1.collide(&ent3), true);
			TS_ASSERT_EQUALS(ent3.collide(&ent1), true);
			// ent4 is contained in ent1 with one shared border point
			TS_ASSERT_EQUALS(ent1.collide(&ent4), true);
			TS_ASSERT_EQUALS(ent4.collide(&ent1), true);
			// ent5 is outside of ent1 and collides at one border point
			TS_ASSERT_EQUALS(ent1.collide(&ent5), true);
			TS_ASSERT_EQUALS(ent5.collide(&ent1), true);
			// ent6 is entirely outside of ent1
			TS_ASSERT_EQUALS(ent1.collide(&ent6), false);
			TS_ASSERT_EQUALS(ent6.collide(&ent1), false);
			// ent7 is entirely outside of ent1 at a greater distance
			TS_ASSERT_EQUALS(ent1.collide(&ent7), false);
			TS_ASSERT_EQUALS(ent7.collide(&ent1), false);

		}

		// Author: Evan Stuempfig
		/* Note: This test may later check more cases for setting positions outside the bounds of the window, non-negative, etc. At the moment, the plan is that this method will only be used internally in the program, and that such validity checks will be made before such calls rather than in the setPosition method. */
		void Test_Get_Set_Position()
		{
			// Create entity instance
			Entity ent1(200, 200, 10);

			// Set and get positions of entity
			Vector2<float> setVal1(250, 250);
			ent1.setPosition(setVal1);
			Vector2<float> getVal1 = ent1.getPosition();

			// Test set and get coordinates' equality
			TS_ASSERT_EQUALS(setVal1.x, getVal1.x);
			TS_ASSERT_EQUALS(setVal1.y, getVal1.y); 
		} 

		

		

		


};
