#include <iostream>
#include <memory>

class Duck {
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck : public Duck {
public:
	void quack() { std::cout << "Quack" << std::endl; }
	void fly() { std::cout << "I'm flying" << std::endl; }
};

class Turkey {
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};

class WildTurkey : public Turkey {
public:
	void gobble() { std::cout << "Gobble gobble" << std::endl; }
	void fly() { std::cout << "I'm flying a short distance" << std::endl; }
};

class TurkeyAdapter : public Duck {
public:
	TurkeyAdapter(Turkey* turkey) : turkey(turkey) {}
	void quack() { turkey->gobble(); }
	void fly() {
		for (int i = 0; i < 5; i++) {
			turkey->fly();
		}		
	}
	
private:
	Turkey* turkey;
};

void testDuck(Duck* duck) {
	duck->quack();
	duck->fly();
}

int main() {
	std::auto_ptr<MallardDuck> duck (new MallardDuck());
	
	std::auto_ptr<WildTurkey> turkey (new WildTurkey());
	std::auto_ptr<Duck> turkeyAdapter (new TurkeyAdapter(turkey.get()));
	
	std::cout << "The Turkey says..." << std::endl;
	turkey->gobble();
	turkey->fly();
	
	std::cout << "The Duck says..." << std::endl;
	testDuck(duck.get());
	
	std::cout << "The Turkey Adapter says..." << std::endl;
	testDuck(turkeyAdapter.get());

	return 0;
}