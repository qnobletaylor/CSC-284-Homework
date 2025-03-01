export module truck;

import vehicle;

export class Truck : public Vehicle {
private:
	int loadCapacity; // max weight truck can carry (lbs)
public:
	~Truck() { truckCount--; }
	Truck(std::string brand, std::string model, int year, int loadCapacity) : Vehicle(brand, model, year) {
		this->loadCapacity = loadCapacity;
		truckCount++;
	}
	Truck(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsBrand, int loadCapacity)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->loadCapacity = loadCapacity;
		truckCount++;
	}

	static int truckCount;

	// Getters/Setters
	void setLoadCapacity(int loadCapacity) { this->loadCapacity = loadCapacity; }
	int getLoadCapacity() const { return loadCapacity; }

	virtual int getCount() const { return truckCount; }

	/**
	 * Creates a hash code using Truck specific attributes.
	 *  */
	virtual std::size_t hashCode() const noexcept {
		std::size_t h1 = std::hash<int>{}(loadCapacity);

		return Vehicle::hashCode() ^ (h1 << 1);
	}

	/**
	 * Formats and returns a string with the attributes of a Truck.
	 *  */
	virtual std::string toString() const override {
		return std::format("{}, {} - {}\n\tUses {}, equipped with {} tires and {} gps\n\tTow Capacity - {} lbs",
			brand, model, year, getEngine(engine), getWheel(wheelType), getGPS(gpsBrand), loadCapacity);
	};
};