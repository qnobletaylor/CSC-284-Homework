import <string>;
import vehicleComponents;

export module vehicle;

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

	void setBrand(std::string brand) { this->brand = brand; }
	void setModel(std::string model) { this->model = model; }
	void setYear(int year) { this->year = year; }
	void setEngine(Engine engine) { this->engine = engine; }
	void setWheelType(Wheel wheelType) { this->wheelType = wheelType; }
	void setGPSBrand(GPS gpsBrand) { this->gpsBrand = gpsBrand; }
	
	std::string getBrand() { return brand; }
	std::string getModel() { return model; }
	int getYear() { return year; }
	Engine getEngine() { return engine; }
	Wheel getWheelType() { return wheelType; }
	GPS getGPSBrand() { return gpsBrand; }

	virtual std::string toString() const = 0;
};