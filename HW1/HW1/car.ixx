export module car;

import vehicle;
import <format>;
import <iostream>;

export class Car : public Vehicle {
private:
	static int carCount;
	std::string bodyType; //sedan, coupe, suv, etc.
	int seatCapacity;
public:
	~Car() { 
		std::cout << "Destroyed" << std::endl;
		carCount--; }

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
	std::string getBodyType() const { return bodyType; }
	int getSeatCapacity() const {	return seatCapacity; }

	virtual int getCount() const { return carCount; }

	/**
	 * Creates a hash code with the additional Car specific attributes.
	 *  */
	virtual std::size_t hashCode() const noexcept {
		std::size_t h1 = std::hash<std::string>{}(bodyType);
		std::size_t h2 = std::hash<int>{}(seatCapacity);

		return Vehicle::hashCode() ^ (h1 << 1) ^ (h2 << 2);
	}

	/**
	 * Return a formatted string with the attributes of a Car.
	 *  */
	virtual std::string toString() const override {
		return std::format("{}, {} - {} ({}), seats{}\n\tUses {}, equipped with {} tires and {} gps", 
			brand, model, year, bodyType, seatCapacity, getEngine(engine), getWheel(wheelType), getGPS(gpsBrand));
	};
};