export module vehicle;

import <string>;
import <format>;
import vehicleComponents;

export class Vehicle {

protected:
	std::string brand;
	std::string model;
	int year;
	Engine engine;
	Wheel wheelType;
	GPS gpsBrand;

public:
	Vehicle() {};
	Vehicle(std::string brand, std::string model, int year) : Vehicle(brand, model, year, Engine::GAS, Wheel::ALLSEASON, GPS::GARMIN) {};
	Vehicle(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand) {
		this->brand = brand;
		this->model = model;
		this->year = year;
		this->engine = engine;
		this->wheelType = wheelType;
		this->gpsBrand = gpsbrand;
	}

	// Setters
	void setBrand(std::string brand) { this->brand = brand; }
	void setModel(std::string model) { this->model = model; }
	void setYear(int year) { this->year = year; }
	void setEngine(Engine engine) { this->engine = engine; }
	void setWheelType(Wheel wheelType) { this->wheelType = wheelType; }
	void setGPSBrand(GPS gpsBrand) { this->gpsBrand = gpsBrand; }
	//Getters
	std::string getBrand() { return brand; }
	std::string getModel() { return model; }
	int getYear() { return year; }
	Engine getEngine() { return engine; }
	Wheel getWheelType() { return wheelType; }
	GPS getGPSBrand() { return gpsBrand; }

	std::string getEngine(Engine) const;
	std::string getWheel(Wheel) const;
	std::string getGPS(GPS) const;

	virtual std::string toString() const = 0;
};