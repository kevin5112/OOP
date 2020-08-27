#include <iostream>
#include <string.h>

class car
{
public:
	car(int seats, int engineSize)
	{
		this->seats = seats;
		this->engineSize = engineSize;
	}

	virtual void accelerate()
	{
		std::cout << "I'm a car moving\n";
	}

	virtual void brake()
	{
		std::cout << "I'm a car stopping\n";
	}

	virtual void unlockDoors()
	{
		std::cout << "Unlocking doors for car\n";
	}

	virtual void lockDoors() = 0;

	virtual void openTrunk()
	{
		std::cout << "Opening trunk\n";
	}

	virtual void turnOnHeadlights()
	{
		std::cout << "Turning on headlights\n";
	}

private:
	int seats;
	int engineSize;
};


class honda : public car
{
public:
	honda(int seats, int engineSize, std::string carName) : car(seats, engineSize) 
	{ 
		this->carName = carName; 
	}

	void accelerate() 
	{
		std::cout << carName << " accelerating\n";
	}

	void brake()
	{
		std::cout << carName << " stopping\n";
	}

	void unlockDoors()
	{
		std::cout << "Unlocking " << carName << " doors\n";
	}

	void lockDoors()
	{
		std::cout << "Locking " << carName << " doors\n";
	}



private:
	std::string carName;

};

class sedan : public honda
{
public:
	sedan(int seats, int engineSize, std::string carName) : honda(seats, engineSize, carName) 
	{ 
		this->carName = carName; 
	}

	void accelerate() 
	{
		std::cout << carName << " accelerating\n";
	}

	void brake()
	{
		std::cout << carName << " stopping\n";
	}

	void unlockDoors()
	{
		std::cout << "Unlocking " << carName << " doors\n";
	}

	void lockDoors()
	{
		std::cout << "Locking " << carName << " doors\n";
	}

	void turnOnHeadlights()
	{
		std::cout << "Turning on " << carName << " headlights\n";
	}

private:
	std::string carName;

};

class toyota : public car
{
public:
	toyota(int seats, int engineSize, std::string carName) : car(seats, engineSize) 
	{ 
		this->carName = carName; 
	}

	void accelerate() 
	{
		std::cout << carName << " accelerating\n";
	}

	void brake()
	{
		std::cout << carName << " stopping\n";
	}

	// unable to compile without having this function
	void lockDoors()
	{
		std::cout << "Locking " << carName << " doors\n";
	}

private:
	std::string carName;

};



int main()
{
	// created a car object that holds it's child honda to show polymorphism
	car* civic = new honda(5, 4, "Civic");
	civic->accelerate();
	civic->brake();
	civic->unlockDoors();
	civic->lockDoors();
	std::cout << std::endl;

	honda accord(5, 6, "Accord");
	// checking inheritance to open trunk
	accord.openTrunk();
	std::cout << std::endl;

	honda* insight = new sedan(5, 4, "Insight");
	// honda type insight inherits turnOnHeadlights from car therefore
	// meaning that although we hold a sedan object in insight we can 
	// use polymorphism to override turnOnHeadlights in the car object 
	insight->turnOnHeadlights();
	std::cout << std::endl;

	// created another car object to hold a different child toyota and shows 
	// polymorphism through unlockDoors functions
	car* corolla = new toyota(5, 4, "Corolla");
	corolla->accelerate();
	corolla->brake();
	corolla->unlockDoors();
	corolla->lockDoors();

	std::cout << "Program terminating\n";
	return 0;
}