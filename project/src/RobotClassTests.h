#pragma once

#include <cxxtest/TestSuite.h>

#include "../src/Entity/Entity.h"
#include "../src/Entity/RobotClass.h"
#include "../src/Entity/Target.h"
#include "../src/Entity/Obstacle.h"
#include "../src/Entity/EntityManager.h"
#include <math.h>

using namespace std;

class RobotClassTests : public CxxTest::TestSuite
{
	public:
		// Author: Andrew Hartfiel
		// The following test utilizes the RobotClass and Target subclasses of Entity; pointAtTarget() is in RobotClass

		void Test_Point_At_Target()
		{
			// Create robot and target
			RobotClass* rob = new RobotClass(100, 100, 1);
			Target* tar = new Target(120, 100, 1);
			Vector2<float> dir1(1, 0);
			Vector2<float> dir2(-1, 0);
			Vector2<float> dir3(0, 1);
			Vector2<float> dir4(0, -1);
			EntityManager::getInstance().add(rob);
			EntityManager::getInstance().add(tar);
			rob->setTargetID(EntityManager::getInstance().getEntityID(tar));
			
			// Test stationary robot
			
			// Test robot initially points at target (rightward)
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir1.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir1.y);
			
			// Test moving target left of robot
			tar->translate(-40, 0);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir2.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir2.y);
			
			// Test moving target directly up from robot
			tar->translate(20, 20);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir3.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir3.y);
			
			// Test moving target directly down from robot
			tar->translate(0, -40);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir4.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir4.y);
			
			
			// Test stationary target
			
			// Move robot and target, so robot is left of target, and target is where robot was previously
			rob->translate(-20, 0);
			tar->translate(0, 20);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir1.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir1.y);
			
			// Test moving robot right of target 
			rob->translate(40, 0);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir2.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir2.y);
			
			// Test moving robot directly down from target
			rob->translate(-20, -20);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir3.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir3.y);
			
			// Test moving robot directly up from target
			rob->translate(0, 40);
			rob->pointAtTarget();
			TS_ASSERT_EQUALS(rob->getOrientation().x, dir4.x);
			TS_ASSERT_EQUALS(rob->getOrientation().y, dir4.y);
		}

		// Author: Andrew Hartfiel
		// The following test utilizes the RobotClass and Target subclasses of Entity; pointAtTarget() is in RobotClass
		void Test_Home_On_Target()
		{
			// Create robot and target
			RobotClass* rob = new RobotClass(100, 100, 1);
			Target* tar = new Target(120, 100, 1);
			Vector2<float> dir1(20, 0);
			Vector2<float> dir2(-20, 0);
			Vector2<float> dir3(0, 20);
			Vector2<float> dir4(0, -20);
			EntityManager::getInstance().add(rob);
			EntityManager::getInstance().add(tar);
			rob->setTargetID(EntityManager::getInstance().getEntityID(tar));
			
			// Test stationary robot
			
			// Test robot initially points at target (rightward)
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir1.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir1.y);
			
			// Test moving target left of robot
			tar->translate(-40, 0);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir2.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir2.y);
			
			// Test moving target directly up from robot
			tar->translate(20, 20);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir3.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir3.y);
			
			// Test moving target directly down from robot
			tar->translate(0, -40);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir4.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir4.y);
			
			
			// Test stationary target
			
			// Move robot and target, so robot is left of target, and target is where robot was previously
			rob->translate(-20, 0);
			tar->translate(0, 20);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir1.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir1.y);
			
			// Test moving robot right of target 
			rob->translate(40, 0);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir2.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir2.y);
			
			// Test moving robot directly down from target
			rob->translate(-20, -20);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir3.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir3.y);
			
			// Test moving robot directly up from target
			rob->translate(0, 40);
			TS_ASSERT_EQUALS(rob->getHomingInfo().x, dir4.x);
			TS_ASSERT_EQUALS(rob->getHomingInfo().y, dir4.y);
		}

		// Author: Andrew Hartfiel
		void Test_Robot_Target_Collide()
		{
			// Create entity instances
			RobotClass* rob1 = new RobotClass(200, 200, 10);
			EntityManager::getInstance().add(rob1);
			Target* tar1 = new Target(200, 200, 10);
			EntityManager::getInstance().add(tar1);
			RobotClass* rob2 = new RobotClass(150, 150, 10);
			EntityManager::getInstance().add(rob2);
			Target* tar2 = new Target(150, 150, 5);
			EntityManager::getInstance().add(tar2);
			RobotClass* rob3 = new RobotClass(100, 100, 10);
			EntityManager::getInstance().add(rob3);
			Target* tar3 = new Target(95, 100, 5);
			EntityManager::getInstance().add(tar3);
			RobotClass* rob4 = new RobotClass(300, 300, 10);
			EntityManager::getInstance().add(rob4);
			Target* tar4 = new Target(285, 300, 5);
			EntityManager::getInstance().add(tar4);
			RobotClass* rob5 = new RobotClass(400, 400, 10);
			EntityManager::getInstance().add(rob5);
			Target* tar5 = new Target(384, 400, 5);
			EntityManager::getInstance().add(tar5);
			RobotClass* rob6 = new RobotClass(500, 500, 10);
			EntityManager::getInstance().add(rob6);
			Target* tar6 = new Target(550, 550, 10);
			EntityManager::getInstance().add(tar6);

			unsigned int rob1ID = EntityManager::getInstance().getEntityID(rob1);
			unsigned int tar1ID = EntityManager::getInstance().getEntityID(tar1);
			unsigned int rob2ID = EntityManager::getInstance().getEntityID(rob2);
			unsigned int tar2ID = EntityManager::getInstance().getEntityID(tar2);
			unsigned int rob3ID = EntityManager::getInstance().getEntityID(rob3);
			unsigned int tar3ID = EntityManager::getInstance().getEntityID(tar3);
			unsigned int rob4ID = EntityManager::getInstance().getEntityID(rob4);
			unsigned int tar4ID = EntityManager::getInstance().getEntityID(tar4);
			unsigned int rob5ID = EntityManager::getInstance().getEntityID(rob5);
			unsigned int tar5ID = EntityManager::getInstance().getEntityID(tar5);
			unsigned int rob6ID = EntityManager::getInstance().getEntityID(rob6);
			unsigned int tar6ID = EntityManager::getInstance().getEntityID(tar6);
			
			rob1->setTargetID(tar1ID);
			rob2->setTargetID(tar2ID);
			rob3->setTargetID(tar3ID);
			rob4->setTargetID(tar4ID);
			rob5->setTargetID(tar5ID);
			rob6->setTargetID(tar6ID);

			// Run tests: Same cases as collide test in EntityTest
			EntityManager::getInstance().collide();
			EntityManager::getInstance().update();
			
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(rob1ID), false);
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(tar1ID), false);

			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(rob2ID), false);
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(tar2ID), false);

			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(rob3ID), false);
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(tar3ID), false);

			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(rob4ID), false);
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(tar4ID), false);

			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(rob5ID), true);
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(tar5ID), true);

			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(rob6ID), true);
			TS_ASSERT_EQUALS(EntityManager::getInstance().entityAvailable(tar6ID), true);

		}
	
};
