import vehicle;

export module car;

export class Car : public Vehicle {
private:
	static int carCount;
	std::string bodyType; //sedan, coupe, suv, etc.
	int seatCapacity;
public:
	~Car() { carCount--; }
	Car(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand, std::string bodyType, int seatCapacity)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->bodyType = bodyType;
		this->seatCapacity = seatCapacity;
		carCount++;
	}

	int getCount() { return carCount; }

	virtual std::string toString() const override {
		return std::format("Total cars : {}", carCount);
	};
};