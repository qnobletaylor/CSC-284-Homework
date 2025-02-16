import <iostream>;
import <memory>;
import <vector>;
import vehicle;
import motorcycle;
import car;
import truck;

int Car::carCount = 0;
int Truck::truckCount = 0;
int Motorcycle::motorcycleCount = 0;

int main()
{
    //std::vector<std::unique_ptr<Vehicle*>> inventory;

    //inventory.push_back(std::make_unique<Car>());

    auto car1 = std::make_unique<Car>("Toyota", "Camry", 2022, "Sedan", 5);
    auto car2 = std::make_unique<Car>("Subaru", "Forester", 2012, "SUV", 5);

    auto truck1 = std::make_unique<Truck>("Ford", "Raptor", 2016, 1400);
    auto truck2 = std::make_unique<Truck>("Honda", "Ridgeline", 2018, 1350);

    auto cycle1 = std::make_unique<Motorcycle>("Yamaha", "Bolt", 2025, "Sport");
    auto cycle2 = std::make_unique<Motorcycle>("Suzuki", "DR-Z125L", 2020, Engine::GAS, Wheel::OFFROAD, GPS::TOMTOM, "Offroad");

    std::cout << car1->toString() << std::endl;

    return 0;
}