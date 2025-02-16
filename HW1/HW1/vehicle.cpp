import vehicle;
import <string>;


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
	case Wheel::SUMMER:
		return "Summer";
		break;
	case Wheel::PERFORMANCE:
		return "Performance";
		break;
	case Wheel::MUD:
		return "Mud";
		break;
	default:
		return "Unkown Wheel Type";
		break;
	}
}

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