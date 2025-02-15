import vehicle;

export module truck;

export class Truck : public Vehicle {
private:
	static int truckCount;
	int loadCapacity; // max weight truck can carry
public:
	~Truck() { truckCount--; }
	Truck(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand, int loadCapacity)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->loadCapacity = loadCapacity;
		truckCount++;
	}

	int getCount() { return truckCount; }

	virtual std::string toString() const override {
		return std::format("Total cars : {}", truckCount);
	};
};