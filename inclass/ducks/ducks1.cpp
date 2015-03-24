#include "duck1.h"

// There are no answers to the questions ?? (amy)

using std::string;

class Mallard : public DuckClass
{
public:
	Mallard(string n = "nameless")
	{
		typeOf = "mallard";
		name = n;
	}
	void fly() { std::cout << "I fly.\n"; }
	void quack() { std::cout << "I quack.\n"; }
};

class Loon : public DuckClass
{
public:
	// This duck quacks and flies   <<<<<<<<<<<< FILL THIS IN
	Loon(string n = "nameless")
	{
		typeOf = "loon";
		name = n;
	}

	void fly() { std::cout << "I fly.\n"; }
	void quack() { std::cout << "I quack.\n"; }
};

class Decoy : public DuckClass
{
	// This duck quacks but cannot fly   <<<<<<<<<<< FILL THIS IN
public:
	Decoy(string n = "nameless")
	{
		typeOf = "decoy";
		name = n;
	}
	// Might still want a fly() to maintain consistency across subclasses
	// void fly() { std::cout << "I don't fly.\n"; }
	void quack() { std::cout << "I quack.\n"; }
};

// <<<<<<<<<<<< WHAT ABOUT A RUBBER DUCK ??

class RubberDuck : public DuckClass
{
public:
	RubberDuck(string n = "nameless")
	{
		typeOf = "rubberduck";
		name = n;
	}

	void squeek() { std::cout << "I squeek.\n"; }
};

int main()
{
	Mallard molly("Molly");
	molly.display();
	molly.fly();
	molly.quack();

	Loon luna("Luna");
	luna.display();
	luna.fly();
	luna.quack();

	Decoy leroy("Leroy");
	leroy.display();
	leroy.quack();

	RubberDuck adl("Atomic Duck Lord");
	adl.display();
	adl.squeek();

	return 0;
}
