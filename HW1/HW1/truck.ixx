import vehicle;

export module truck;

export class Truck : public Vehicle {
private:
	static int truckCount;
	int loadCapacity; // max weight truck can carry (lbs)
public:
	~Truck() { truckCount--; }
	Truck(std::string brand, std::string model, int year, int loadCapacity) : Vehicle(brand, model, year) {
		this->loadCapacity = loadCapacity;
		truckCount++;
	}
	Truck(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand, int loadCapacity)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->loadCapacity = loadCapacity;
		truckCount++;
	}

	// Getters/Setters
	void setLoadCapacity(int loadCapacity) {
		this->loadCapacity = loadCapacity;
	}
	int getLoadCapacity() {
		return loadCapacity;
	}

	int getCount() { return truckCount; }

	virtual std::string toString() const override {
		return std::format("{}, {} - {}\nUses {}, equipped with {} tires and {} gps\nTow Capacity - {} lbs", brand, model, year, getEngine(engine), getWheel(wheelType), getGPS(gpsBrand), loadCapacity);
	};
};