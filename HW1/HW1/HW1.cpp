import <iostream>;
import vehicle;
import car;

int Car::carCount = 0;

int main()
{
    Car* car1;

    car1 = new Car("Subaru", "Forester", 2022, HYBRID, ALLSEASON, GARMIN, "suv", 4);

    std::cout << car1->toString() << std::endl;

    delete car1;
    

    return 0;
}
