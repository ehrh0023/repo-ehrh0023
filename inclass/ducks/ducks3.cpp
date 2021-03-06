#include "duck3.h"

using std::string;

class Mallard : public DuckClass
{
	// Flies and quacks   <<<<<<<<<<<<<<< IMPLEMENT THIS
public:
	Mallard(string n = "nameless")
	{
		typeOf = "mallard";
		name = n;
		canQuack = true;
		canFly = true;
	}
};

class Decoy : public DuckClass
{
	// This duck quacks but cannot fly <<<<<<<<<<< IMPLEMENT THIS
public:
	Decoy(string n = "nameless")
	{
		typeOf = "decoy";
		name = n;

		canQuack = true;
		canFly = false;
	}
};

class RubberDuck : public DuckClass
{
	// Squeaks (no quack) and cannot fly  <<<<<<<<< IMPLEMENT THIS
public:
	RubberDuck(string n = "nameless")
	{
		typeOf = "loon";
		name = n;

		canQuack = false;
		canFly = false;
	}

	void squeek() { std::cout << "I squeek.\n"; }
};

int main()
{
	Mallard molly("molly");
	molly.display();
	molly.fly();
	molly.quack();
}

