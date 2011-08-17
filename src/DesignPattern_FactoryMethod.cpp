#include <iostream>
#include <string>

//! Abstract Product
class Pizza {
public:
	virtual ~Pizza() {}
	
	std::string name;
};

class NYPizza : public Pizza {
public:
	NYPizza() {name = "New York Pizza";}
};

class ChicagoPizza : public Pizza {
public:
	ChicagoPizza() {name = "Chicago Pizza";}
};

//! Abstract Creator
class PizzaStore {
public:
	PizzaStore() {}
	
	void orderPizza() { 
		Pizza* za = createPizza();
		std::cout << za->name << " On it's way!"  << std::endl;
		delete za;
	}
	
protected:
	virtual Pizza* createPizza() = 0;
};

class NYPizzaStore : public PizzaStore {
public:	
	NYPizzaStore() {}

protected:
	virtual Pizza* createPizza() {return new NYPizza();}
};

class ChicagoPizzaStore : public PizzaStore {
public:
	ChicagoPizzaStore() {}

protected:
	virtual Pizza* createPizza() {return new ChicagoPizza();}
};

int main() {
	PizzaStore* zaStore = new NYPizzaStore();
	zaStore->orderPizza();
	delete zaStore;

	zaStore = new ChicagoPizzaStore();
	zaStore->orderPizza();
	delete zaStore;
	
	return 0;
}