#include <iostream>
#include <string>

class Singleton {
public:
	~Singleton();
	
	static Singleton* getInstance();

	std::string message;
	
private:
	Singleton() : message("Just try to make two of me!") {}
	static Singleton* pThis;
	
};

Singleton* Singleton::pThis = 0;

Singleton::~Singleton() {
	if(pThis != 0) {
		delete pThis;
	}
}

Singleton* Singleton::getInstance() {
		if(pThis == 0) {
			pThis = new Singleton();
		}
		return pThis;
}

int main() {
	std::cout << Singleton::getInstance()->message << std::endl;
	
	return 0;
}