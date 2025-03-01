
### Vehicle Rental Management System

#### Homework 1

This console program simulates a simple management system that might exist at a car  
rental company. The program allows a user to add different types of vehicles (car, truck, or motorcycle)  
as well as customizing the attributes of them. The three types are derived from a generic Vehicle  
class allowing for polymorphic behaviour and allows easier storing within the same datastructure.  
Lastly, the program allows the user to move created vehicles between two datastructures which  
signify a list of already rented vehicles and ones which are available for rental.

---

To run the console program, simply clone the repository and open visual studio 2022  
with the Visual Studio solution file `~/../HW1/HW1.sln`. This will open the project with c++20  
already chosen as the standard.

Use `ctrl + F5` and the program will run.

---

#### Exercise Questions

1) Which classes should inherit from a base class?

I decided to make the Vehicle class a generic base class which contains all the shared attributes between  
the other subclasses (car, truck, motorcycle). The three subclasses thus inherit all of the attributes and  
functions which I designed for the Vehicle class.

2) Which classes should be contained within other classes as components?

I used three enum classes to represent certain vehicle components such as Wheel, Engine, and GPS types.  
These are stored within the Vehicle class as attributes and are thus inherited by it's subclasses.  
Going forward, it would be cool to add a time/date class or use a prexisting one to include an attribute which  
stores a timestamp for when a vehicle is check in/out of the system.

3) How would you modify the design to support new vehicle types without major code changes?

Currently because the abstract class Vehicle includes most attributes that all vehicles would normally share,  
the ability to add new vehicle types is already fairly straight forward. One would just create a new class which  
extends from Vehicle and add any type specific attributes.

Another option for increasing scaleability is to create a container class which stores rental information  
such as time/date of rental, price, etc. While containing a Vehicle as an attribute as well. This contianer class  
could be made as a template which accepts any derived classes of Vehicle.