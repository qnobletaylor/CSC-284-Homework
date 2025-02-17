export module motorcycle;

import vehicle;
import vehicleComponents;

export class Motorcycle : public Vehicle {
private:
	std::string bodyType; // dirt, sport, touring, etc.
public:
	~Motorcycle() { motorcycleCount--; }
	Motorcycle(std::string brand, std::string model, int year, std::string bodyType) : Vehicle(brand, model, year) {
		this->bodyType = bodyType;
		motorcycleCount++;
	}
	Motorcycle(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsBrand, std::string bodyType)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->bodyType = bodyType;
		motorcycleCount++;
	}

	static int motorcycleCount;

	// Getters/Setters
	void setBodyType(std::string bodyType) { this->bodyType = bodyType; }
	std::string getBodyType() const { return bodyType; }

	virtual int getCount() const { return motorcycleCount; }

	/**
	 * Creates a hash code with Motorcycle specific attributes.
	 *  */
	virtual std::size_t hashCode() const noexcept {
		std::size_t h1 = std::hash<std::string>{}(bodyType);

		return Vehicle::hashCode() ^ (h1 << 1);
	}

	/**
	 * Formats and returns a string with attributes of a Motorcycle.
	 *  */
	virtual std::string toString() const override {
		return std::format("{}, {} - {} ({})\n\tUses {}, equipped with {} tires and {} gps", 
			brand, model, year, bodyType, getEngine(engine), getWheel(wheelType), getGPS(gpsBrand));
	};
};