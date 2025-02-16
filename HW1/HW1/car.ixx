import vehicle;
import <format>;

export module car;

export class Car : public Vehicle {
private:
	static int carCount;
	std::string bodyType; //sedan, coupe, suv, etc.
	int seatCapacity;
public:
	~Car() { carCount--; }
	Car(std::string brand, std::string model, int year, std::string bodyType, int seatCapacity) : Vehicle(brand, model, year) {
		this->bodyType = bodyType;
		this->seatCapacity = seatCapacity;
		carCount++;
	}
	Car(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand, std::string bodyType, int seatCapacity)
		: Vehicle(brand, model, year, engine, wheelType, gpsBrand) {
		this->bodyType = bodyType;
		this->seatCapacity = seatCapacity;
		carCount++;
	}

	// Getters/Setters
	void setBodyType(std::string bodyType) { this->bodyType = bodyType;	}
	void setSeatCapacity(int seatCapacity) { this->seatCapacity = seatCapacity;	}
	std::string getBodyType() { return bodyType; }
	int getSeatCapacity() {	return seatCapacity; }

	int getCount() { return carCount; }

	virtual std::string toString() const override {
		return std::format("{}, {} - {} ({})\nUses {}, equipped with {} tires and {} gps\nseats {}", brand, model, year, bodyType, getEngine(engine), getWheel(wheelType), getGPS(gpsBrand), seatCapacity);
	};
};