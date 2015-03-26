#include <iostream>
#include <stdlib.h>

#define MPH_DEFAULT 5
#define DB_DEFAULT 10

using namespace std;

//-----------------------------------------------
//   QUACKING

class QuackBehavior
{
protected:
	double volume;
public:
	QuackBehavior() : volume(DB_DEFAULT) {}
	virtual void quack() { cout << "Generic Quack at " << volume << " decibels" << endl; }
};

class Quack : public QuackBehavior
{
public:
	Quack() {}
	void quack() { cout << "Quack at " << volume << " decibels" << endl; }
};

class Mute : public QuackBehavior
{
public:
	Mute() { volume = 0; }
	void quack() { cout << "Can not talk." << endl; }
};

class Squeak : public QuackBehavior
{
public:
	Squeak() {}
	Squeak(int d) { volume = d; }
	void quack() { cout << "Squeak at " << volume << " decibels." << endl; }
};

class Honk : public QuackBehavior
{
	Honk() {}
	Honk(int d) { volume = d; }
	void quack() { cout << "Honk at " << volume << " decibels." << endl; }
};


//-----------------------------------------------
//   FLYING

class FlyBehavior
{
protected:
	double milesPerHour;
public:
	FlyBehavior() : milesPerHour(MPH_DEFAULT) {}
	virtual void fly() { cout << "Generic Flying at " << milesPerHour << " mph." << endl; }
};

class FlyWithWings : public FlyBehavior
{
public:
	FlyWithWings() {}
	void fly() { cout << "Fly at speed of " << milesPerHour << " mph." << endl; }
};

class NoFly : public FlyBehavior
{
public:
	NoFly() {}
	void fly() { cout << "Can not fly" << endl; }
};

class FlyWithRocket : public FlyBehavior
{
	FlyWithRocket() { milesPerHour = MPH_DEFAULT * 3; }
	void fly() { cout << "Fly at speed of " << milesPerHour << " mph." << endl; }
};

//----------------------------------------------
//  THE DUCKS

class Duck
{
protected:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
public:
	Duck()
	{
		flyBehavior = new FlyWithWings();
		quackBehavior = new Quack();
	}
	virtual void display() { cout << "I am a duck." << endl; }
	virtual void fly() { flyBehavior->fly(); }
	virtual void quack() { quackBehavior->quack(); }


	virtual ~Duck()
	{
		delete flyBehavior;
		delete quackBehavior;
	}
};

class Mallard : public Duck
{
public:
	Mallard()
	{
		delete flyBehavior;
		delete quackBehavior;

		flyBehavior = new FlyWithWings();
		quackBehavior = new Quack();
	}
	void display() { cout << "I am a Mallard." << endl; }
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
	{
		delete flyBehavior;
		delete quackBehavior;

		flyBehavior = new NoFly();
		quackBehavior = new Squeak(2);
	}
	void display() { cout << "I am a Rubber Duck." << endl; }
};

int main()
{

	Mallard mary;
	RubberDuck ralph;
	Duck donald;

	cout << endl << "Donald does this ... " << endl;
	donald.display();
	donald.fly();
	donald.quack();

	cout << endl << "Mary does this ... " << endl;
	mary.display();
	mary.fly();
	mary.quack();

	cout << endl << "Ralph does this ... " << endl;
	ralph.display();
	ralph.fly();
	ralph.quack();

	cout << endl;
}


