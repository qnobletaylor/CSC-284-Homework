export module vehicle;

import <string>;
import <iostream>;
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

	static int vehicleCount;

public:
	~Vehicle() { vehicleCount--; }
	Vehicle(std::string brand, std::string model, int year) : Vehicle(brand, model, year, Engine::GAS, Wheel::ALLSEASON, GPS::GARMIN) {};
	Vehicle(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand);

	// Setters
	void setBrand(std::string brand) { this->brand = brand; }
	void setModel(std::string model) { this->model = model; }
	void setYear(int year) { this->year = year; }
	void setEngine(Engine engine) { this->engine = engine; }
	void setWheelType(Wheel wheelType) { this->wheelType = wheelType; }
	void setGPSBrand(GPS gpsBrand) { this->gpsBrand = gpsBrand; }
	//Getters
	std::string getBrand() const { return brand; }
	std::string getModel() const { return model; }
	int getYear() const { return year; }
	Engine getEngine() const { return engine; }
	Wheel getWheelType() const { return wheelType; }
	GPS getGPSBrand() const { return gpsBrand; }
	std::string getEngine(Engine) const;
	std::string getWheel(Wheel) const;
	std::string getGPS(GPS) const;

	virtual int getCount() const { return vehicleCount; }

	// Overriden functions
	virtual std::size_t hashCode() const noexcept;
	virtual std::string toString() const = 0;
};