#include <iostream>
#include <list>

//! Observes the subject
class Observer { 
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

//! Is the subject of observation
class Subject { 
public:
	virtual void registerObserver(Observer* obs) = 0;
	virtual void removeObserver(Observer* obs) = 0;
	virtual void notifyObservers() = 0;
};

class DisplayElement {
public:
	virtual void display() = 0;
};

class CurrentConditionsDisplay : public DisplayElement, public Observer {
public:
	CurrentConditionsDisplay(Subject* weatherData) {
		this->weatherData = weatherData;
		this->weatherData->registerObserver(this);
	}

	virtual void update(float temp, float humidity, float pressure) {
		this->temperature = temp;
		this->humidity = humidity;
		display();
	}
	
	virtual void display() {
		std::cout << "Temperature: " << temperature << " Humidity: " << humidity << std::endl;
	}
	
private:
	float temperature;
	float humidity;
	Subject* weatherData; 
	
};

class WeatherData : public Subject {
public:
	virtual void registerObserver(Observer* obs) {
		obsList.push_back(obs);
		obsList.unique();
	}
	
	virtual void removeObserver(Observer* obs) {
		obsList.remove(obs);
	}
	
	virtual void notifyObservers() {
		std::list<Observer*>::iterator it;
		for (it = obsList.begin(); it != obsList.end(); it++) {
			(*it)->update(temperature, humidity, pressure);
		}
	}
	
	virtual void measurementsChanged() {
		notifyObservers();
	}
	
	virtual void setMeasurements(float temperature, float humidity, float pressure) {
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		measurementsChanged();
	}
	
private:
	std::list<Observer*> obsList;
	float temperature;
	float humidity;
    float pressure;
};


int main() {
	WeatherData weatherData;
	CurrentConditionsDisplay curConditionsDisplay(dynamic_cast<Subject*>(&weatherData));			// XXX Interesting Difference from Java here, have to cast to Subject*
	
	weatherData.setMeasurements(80, 65, 30.4f);
	weatherData.setMeasurements(82, 70, 29.2f);
	weatherData.setMeasurements(78, 90, 29.2f);

	return 0;
}