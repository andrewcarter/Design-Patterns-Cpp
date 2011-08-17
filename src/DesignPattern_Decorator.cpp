#include <iostream>
#include <string>

//! Component 
class Beverage { 
public:
	Beverage() : description("Unknown Beverage") {}

	virtual std::string getDescription() const{
		return description;
	}

	virtual float cost() const = 0;

protected:
	std::string description;
};

//! Decorator
class CondimentDecorator : public Beverage {
public:
	virtual std::string getDescription() const = 0;
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) : beverage(beverage) {}

	std::string getDescription() const {
		return beverage->getDescription() + ", Mocha";
	}

	float cost() const {
		return beverage->cost() + 0.20f;
	}

private:
	Beverage* beverage;
};

class Soy : public CondimentDecorator {
public:
	Soy(Beverage* beverage) : beverage(beverage) {}

	std::string getDescription() const {
		return beverage->getDescription() + ", Soy";
	}

	float cost() const {
		return beverage->cost() + 0.15f;
	}

private:
	Beverage* beverage;
};

class Whip : public CondimentDecorator {
public:
	Whip(Beverage* beverage) : beverage(beverage) {}

	std::string getDescription() const {
		return beverage->getDescription() + ", Whip";
	}

	float cost() const {
		return beverage->cost() + 0.10f;
	}

private:
	Beverage* beverage;
};

class HouseBlend : public Beverage {
public:	
	HouseBlend() {	
		this->description = "House Blend Coffee";
	}

	float cost() const {
		return 0.89f;
	}	
};

class DarkRoast : public Beverage {
public:	
	DarkRoast() {
		this->description = "Dark Roast Coffee";
	}

	float cost() const {
		return 0.99f;
	}	
};

class Espresso : public Beverage {
public:
	Espresso() {
		this->description = "Espresso";
	}

	float cost() const {
		return 1.99f;
	}
};

int main() {
	Beverage* espresso = new Espresso();
	std::cout << espresso->getDescription() << " $" << espresso->cost() << std::endl;
	delete espresso;

	Beverage* beverage = new DarkRoast();
	beverage = new Mocha(beverage);
	beverage = new Mocha(beverage);
	beverage = new Whip(beverage);
	std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;
	delete beverage;
	
	Beverage* beverage2 = new HouseBlend();
	beverage2 = new Soy(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;
	delete beverage2;

	return 0;
}