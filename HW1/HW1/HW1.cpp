import <iostream>;
import <string>;
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

// Function explanations above definitions
void fillInventory(std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory);
bool validateInput(char input);
void printInventory(const std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory);
void promptVehicleAttributes(char vehicleType, std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory);
Engine parseEngineChoice(char input);
Wheel parseWheelChoice(char input);
GPS parseGPSChoice(char input);
void moveVehicle(char input, std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory, std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& rented);

int main()
{
    bool doesContinue = true; // To end the main program loop
    char userInput{};
    std::unordered_map<std::size_t, std::unique_ptr<Vehicle>> inventory{};
    std::unordered_map<std::size_t, std::unique_ptr<Vehicle>> rentedInventory{};
    fillInventory(inventory); // put assortment of vehicles into the map

    std::cout << "Welcome to the vehicle management system," << std::endl;

    do {
        do { // Continues to prompt if invalid input is given
            std::cout << "Please choose from the list of options:" << std::endl;
            std::cout << "\tA) View vehicles\n\tB) Add new vehicle\n\tC) Rent/Return Vehicle\n\tD) Exit" << std::endl;
            std::cin >> userInput;
            std::cin.ignore(100, '\n');
        } while (!validateInput(userInput));

        switch (userInput)
        {
        case ('a'):
        case ('A'):
            do {
                std::cout << "Which inventory would you like to view?" << std::endl;
                std::cout <<"\tA) Available Vehicles\n\tB) Rented Vehicles" << std::endl;
                std::cin >> userInput;
                std::cin.ignore(100, '\n');
            } while (!validateInput(userInput));
            if (userInput == 'a' || userInput == 'A') printInventory(inventory);
            else if (userInput == 'b' || userInput == 'B') printInventory(rentedInventory);
            break;
        case ('b'):
        case ('B'):
            do { // Get type of vehicle to create
                std::cout << "What type of vehicle would you like to add to the system: " << std::endl;
                std::cout << "\tA) Car\n\tB) Truck\n\tC) Motorcycle" << std::endl;
                std::cin >> userInput;
                std::cin.ignore(100, '\n');
            } while (!validateInput(userInput));
            promptVehicleAttributes(userInput, inventory);
            break;
        case ('c'):
        case ('C'):
            do {
                std::cout << "Rent or return a vehicle?\n\tA) Rent\n\tB) Return" << std::endl;
                std::cin >> userInput;
                std::cin.ignore(100, '\n');
            } while (!validateInput(userInput));
            moveVehicle(userInput, inventory, rentedInventory);
            break;
        case ('d'):
        case ('D'):
        default:
            doesContinue = false; // End of program
            break;
        }
    } while (doesContinue);

    std::cout << "Exiting" << std::endl;

    return 0;
}

/**
 * This function simply serves to fill the inventory with different vehicle options upon starting the program.
 * */
void fillInventory(std::unordered_map<std::size_t, std::unique_ptr<Vehicle>> &inventory) {
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

/**
 * Prints the items in the a map of Vehicles.
 *  */
void printInventory(const std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>&inventory) {
    if (inventory.size() == 0) return;

    int i = 0;
    for (const auto& pair : inventory) {
        i++;
        std::cout << std::format("[ {} ]   {}\n", i, pair.second->toString()) << std::endl;
    }

    std::cout << std::format("{} Vehicles | {} Cars, {} Trucks, {} Motorcycles\n", Vehicle::vehicleCount, Car::carCount, Truck::truckCount, Motorcycle::motorcycleCount) << std::endl;
}

/**
 * Handles the creation of a new vehicle and places it into the inventory map. Handles error checking for invalid inputs.
 *  */
void promptVehicleAttributes(char vehicleType, std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory) {
    std::string brand, model, bodyType;
    int year, seatsOrLbs;
    Engine engine;
    Wheel wheel;
    GPS gps;
    char input;

    std::cout << "Please enter brand:" << std::endl;
    std::getline(std::cin, brand);
    std::cout << "Please enter model:" << std::endl;
    std::getline(std::cin, model);
    
    std::cout << "Year of manufactur:" << std::endl;
    std::cin >> year;
    while (!std::cin.good()) { // Checking for a valid integer, will reprompt if invalid
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Enter a valid integer for year:" << std::endl;
        std::cin >> year;
    }
    
    do {
        std::cout << "Would you like to enter specific parts (engine, wheels, gps) or use defaults (gas, allseason, garmin)?" << std::endl;
        std::cout << "\tY) yes, let me choose\n\tN) no, use defaults" << std::endl;
        std::cin >> input;
    } while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

    if (input == 'y' || input == 'Y') {
        do {
            std::cout << "Choose type of engine:\n\tA) Gas\n\tB) Diesel\n\tC) Electric\n\tD) Hybrid" << std::endl;
            std::cin >> input;
        } while (!validateInput(input));
        engine = parseEngineChoice(input);
        do {
            std::cout << "Choose type of wheels:\n\tA) Allseason\n\tB) Offroad\n\tC) Winter\n\tD) Perfomance" << std::endl;
            std::cin >> input;
        } while (!validateInput(input));
        wheel = parseWheelChoice(input);
        do {
            std::cout << "Choose type of GPS:\n\tA) Garmin\n\tB) TomTom\n\tC) Navi" << std::endl;
            std::cin >> input;
        } while (!validateInput(input));
        gps = parseGPSChoice(input);
    }
    else {
        engine = Engine::GAS;
        wheel = Wheel::ALLSEASON;
        gps = GPS::GARMIN;
    }
    if (vehicleType == 'a' || vehicleType == 'A') { // Car
        std::cin.ignore(100, '\n');
        std::cout << "Enter the body type of the car:" << std::endl;
        std::getline(std::cin, bodyType);

        std::cout << "Number of seats in the car:" << std::endl;
        std::cin >> seatsOrLbs;
        while (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Enter a valid integer for # of seats:" << std::endl;
            std::cin >> seatsOrLbs;
        }

        auto car = std::make_unique<Car>(brand, model, year, engine, wheel, gps, bodyType, seatsOrLbs);
        inventory.emplace(car->hashCode(), std::move(car));
    }
    else if (vehicleType == 'b' || vehicleType == 'B') { // Truck
        std::cout << "Enter carrying capacity of truck (lbs):" << std::endl;
        std::cin >> seatsOrLbs;
        while (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Enter a valid integer for carrying capacity:" << std::endl;
            std::cin >> seatsOrLbs;
        }

        auto truck = std::make_unique<Truck>(brand, model, year, engine, wheel, gps, seatsOrLbs);
        inventory.emplace(truck->hashCode(), std::move(truck));
    }
    else if (vehicleType == 'c' || vehicleType == 'C') { // Motorcycle
        std::cin.ignore(100, '\n');
        std::cout << "Enter the body type of the motorcycle:" << std::endl;
        std::getline(std::cin, bodyType);

        auto motorcycle = std::make_unique<Motorcycle>(brand, model, year, engine, wheel, gps, bodyType);
        inventory.emplace(motorcycle->hashCode(), std::move(motorcycle));
    }
}

/**
 * Takes a user input as a char and returns the corresponding enum.
 *  */
Engine parseEngineChoice(char input) {
    switch (input)
    {
    case ('a'):
    case ('A'):
        return Engine::GAS;
        break;
    case ('b'):
    case ('B'):
        return Engine::DIESEL;
        break;
    case ('c'):
    case ('C'):
        return Engine::ELECTRIC;
        break;
    case ('d'):
    case ('D'):
        return Engine::HYBRID;
        break;
    default:
        return Engine::GAS;
        break;
    }
}

/**
 * Takes user input as a char and returns corresponding enum.
 *  */
Wheel parseWheelChoice(char input) {
    switch (input)
    {
    case ('a'):
    case ('A'):
        return Wheel::ALLSEASON;
        break;
    case ('b'):
    case ('B'):
        return Wheel::OFFROAD;
        break;
    case ('c'):
    case ('C'):
        return Wheel::WINTER;
        break;
    case ('d'):
    case ('D'):
        return Wheel::PERFORMANCE;
        break;
    default:
        return Wheel::ALLSEASON;
        break;
    }
}

/**
 * Takes user input as a char and returns corresponding enum.
 *  */
GPS parseGPSChoice(char input) {
    switch (input)
    {
    case ('a'):
    case ('A'):
        return GPS::GARMIN;
        break;
    case ('b'):
    case ('B'):
        return GPS::TOMTOM;
        break;
    case ('c'):
    case ('C'):
        return GPS::NAVI;
        break;
    default:
        return GPS::GARMIN;
        break;
    }
}

/**
 * Asks a user for index of a vehicle to move from the available inventory to the rented inventory map.
 *  */
void moveVehicle(char input, std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& inventory, std::unordered_map<std::size_t, std::unique_ptr<Vehicle>>& rented) {
    int indexInput;
    int i = 0;

    if (input == 'a' || input == 'A') {
        std::cout << "Please enter the index of the vehicle being rented:" << std::endl;
        std::cin >> indexInput;
        while (!std::cin.good() || indexInput > inventory.size() || indexInput < 1) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Enter a valid integer index within range:" << std::endl;
            std::cin >> indexInput;
        }
        for (auto& pair : inventory) {
            i++;
            if (indexInput == i) {
                rented.emplace(pair.first, std::move(pair.second));
                inventory.erase(pair.first);
                return;
            }
        }
    }
    else if (input == 'b' || input == 'B') {
        std::cout << "Please enter the index of the vehicle being returned:" << std::endl;
        std::cin >> indexInput;
        while (!std::cin.good() || indexInput > rented.size() || indexInput < 1) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Enter a valid integer index within range:" << std::endl;
            std::cin >> indexInput;
        }

        for (auto& pair : rented) {
            i++;
            if (indexInput == i) {
                inventory.emplace(pair.first, std::move(pair.second));
                rented.erase(pair.first);
                return;
            }
        }
    }
}
