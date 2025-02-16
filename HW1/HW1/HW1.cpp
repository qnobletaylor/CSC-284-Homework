import <iostream>;
import <memory>;
import <unordered_map>;
import vehicle;
import motorcycle;
import car;
import truck;

// Iniitializing the static variable for each vehicle to keep track of # of objects
int Car::carCount = 0;
int Truck::truckCount = 0;
int Motorcycle::motorcycleCount = 0;
int Vehicle::vehicleCount = 0;

void fillInventory(std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory);
bool validateInput(char input);
void printInventory(const std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>inventory);

int main()
{
    char userInput{};
    std::unordered_map<std::size_t, std::unique_ptr<Vehicle>> inventory{};
    std::unordered_map<std::size_t, std::unique_ptr<Vehicle>> rentedInventory{};
    fillInventory(inventory); // put assortment of vehicles into the map

    do {
        std::cout << "Welcome to the vehicle management system,\nPlease choose from the list of options:" << std::endl;
        std::cout << "\tA) View available vehicles\n\tB) Add new vehicle\n\tC) Rent Vehicle\n\tD) Exit" << std::endl;
        std::cin >> userInput;
        std::cin.ignore(100, '\n');
    } while (!validateInput(userInput));

    std::cout << "Response : " << userInput << std::endl;


    return 0;
}

/**
 * This function simply serves to fill the inventory with different vehicle options upon starting the program.
 * */
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

/**
 * Validates input from user to ensure they enter an appropriate menu option.
 *  */
bool validateInput(char input) {
    switch (input)
    {
    case ('a'):
    case ('A'):
        return true;
        break;
    case ('b'):
    case ('B'):
        return true;
        break;
    case ('c'):
    case ('C'):
        return true;
        break;
    case ('d'):
    case ('D'):
        return true;
        break;
    default:
        return false;
        break;
    }
}

void printInventory(const std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>inventory) {
    // Iterate through the inventory
    for (auto iter = inventory.begin(); iter != inventory.end(); iter++) {
        std::cout << (*iter).second->toString() << "\n" << std::endl;
    }
}
