import vehicle;
import <string>;

/**
 * Primary constructor for all vehicles
 * */
Vehicle::Vehicle(std::string brand, std::string model, int year, Engine engine, Wheel wheelType, GPS gpsbrand) {
	this->brand = brand;
	this->model = model;
	this->year = year;
	this->engine = engine;
	this->wheelType = wheelType;
	this->gpsBrand = gpsbrand;
	vehicleCount++;
}

/** 
* Converts enum value to a string
* */
std::string Vehicle::getEngine(Engine engine) const {
	switch (engine)
	{
	case Engine::GAS:
		return "Gas";
		break;
	case Engine::DIESEL:
		return "Diesel";
		break;
	case Engine::ELECTRIC:
		return "Electric";
		break;
	case Engine::HYBRID:
		return "Hybrid";
		break;
	default:
		return "Unknown Engine Type";
		break;
	}
}

/**
 * Converts an enum value to a string.
 * */
std::string Vehicle::getWheel(Wheel wheel) const {
	switch (wheel)
	{
	case Wheel::ALLSEASON:
		return "Allseason";
		break;
	case Wheel::OFFROAD:
		return "Offroad";
		break;
	case Wheel::WINTER:
		return "Winter";
		break;
	case Wheel::PERFORMANCE:
		return "Performance";
		break;
	default:
		return "Unkown Wheel Type";
		break;
	}
}

/**
 * Converts enum to a string. 
 */
std::string Vehicle::getGPS(GPS gps) const {
	switch (gps)
	{
	case GPS::GARMIN:
		return "Garmin";
		break;
	case GPS::TOMTOM:
		return "TomTom";
		break;
	case GPS::NAVI:
		return "Navi";
		break;
	default:
		return "Unknown Type";
		break;
	}
}

/**
 * Creates a hash code using the attributes from a Vehicle object
 *  */
std::size_t Vehicle::hashCode() const noexcept {
	std::size_t h1 = std::hash<std::string>{}(brand);
	std::size_t h2 = std::hash<std::string>{}(model);
	std::size_t h3 = std::hash<int>{}(year);
	std::size_t h4 = std::hash<int>{}(static_cast<int>(engine));
	std::size_t h5 = std::hash<int>{}(static_cast<int>(wheelType));
	std::size_t h6 = std::hash<int>{}(static_cast<int>(gpsBrand));

	return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3) ^ (h5 << 4) ^ (h6 << 5);
}