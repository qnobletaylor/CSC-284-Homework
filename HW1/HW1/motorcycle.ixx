export module motorcycle;

import vehicle;
import vehicleComponents;

export class Motorcycle : public Vehicle {
private:
	static int motorcycleCount;
	std::string bodyType; // dirt, sport, touring, etc.
public:
	~Motorcycle() { motorcycleCount--; }
	Motorcycle(std::string brand, std::string model, int year, std::string bodyType) : Vehicle(brand, model, year) {
		this->bodyType = bodyType;
		motorcycleCount++;
	}
	Motorcycle(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand, std::string bodyType)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->bodyType = bodyType;
		motorcycleCount++;
	}

	// Getters/Setters
	void setBodyType(std::string bodyType) { this->bodyType = bodyType; }
	std::string getBodyType() { return bodyType; }

	int getCount() { return motorcycleCount; }

	virtual std::string toString() const override {
		return std::format("Brand : {} | Model : {} {} ({})\nUses {}, equipped with {} tires and {} gps", brand, model, year, bodyType, getEngine(engine), getWheel(wheelType), getGPS(gpsBrand));
	};
};