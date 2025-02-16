import <iostream>;
import <memory>;
import <unordered_map>;
import vehicle;
import motorcycle;
import car;
import truck;

int Car::carCount = 0;
int Truck::truckCount = 0;
int Motorcycle::motorcycleCount = 0;
int Vehicle::vehicleCount = 0;

void fillInventory(std::unordered_map < std::size_t, std::unique_ptr<Vehicle>>& inventory);

int main()
{
    std::unordered_map<std::size_t, std::unique_ptr<Vehicle>> inventory{};

    fillInventory(inventory);

    for (auto iter = inventory.begin(); iter != inventory.end(); iter++) {
        std::cout << (*iter).second->toString() << "\n" << std::endl;
    }

    return 0;
}

void fillInventory(std::unordered_map < std::size_t, std::unique_ptr<Vehicle>>& inventory) {
    auto car1 = std::make_unique<Car>("Toyota", "Camry", 2022, "Sedan", 5);
    auto car2 = std::make_unique<Car>("Subaru", "Forester", 2012, "SUV", 5);
    inventory.emplace(car1->hashCode(), std::move(car1));
    inventory.emplace(car2->hashCode(), std::move(car2));

    auto truck1 = std::make_unique<Truck>("Ford", "Raptor", 2016, 1400);
    auto truck2 = std::make_unique<Truck>("Honda", "Ridgeline", 2018, 1350);
    inventory.emplace(truck1->hashCode(), std::move(truck1));
    inventory.emplace(truck2->hashCode(), std::move(truck2));

    auto cycle1 = std::make_unique<Motorcycle>("Yamaha", "Bolt", 2025, "Sport");
    auto cycle2 = std::make_unique<Motorcycle>("Suzuki", "DR-Z125L", 2020, Engine::GAS, Wheel::OFFROAD, GPS::TOMTOM, "Offroad");
    inventory.emplace(cycle1->hashCode(), std::move(cycle1));
    inventory.emplace(cycle2->hashCode(), std::move(cycle2));
}