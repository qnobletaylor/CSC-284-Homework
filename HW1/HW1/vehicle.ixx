import <iostream>;

export module vehicle;

export class Vehicle {

protected:
	std::string brand;
	std::string model;
	int year;
public:
	virtual ~Vehicle() {};
	Vehicle() {};
	Vehicle(std::string brand, std::string model, int year) {
		this->brand;
		this->model;
		this->year;
	}

	virtual std::string toString() const = 0;
};