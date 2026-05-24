#include <bits/stdc++.h>
using namespace std;

// 1. INTERFACE: C++ me interface abstract class se banta hai jiske saare methods pure virtual ho.
class Insurance {
    public:
        virtual void claimInsurance() = 0; // pure virtual function
        virtual ~Insurance() {}; // Virtual destructor for safe cleanup
};

// 2. ABSTRACT CLASS: Encapsulation aur inheritance yahan hoti hai.
class Vehicle : public Insurance {
    private: 
        string fuelType;
    
    public:
        // constructor
        Vehicle(string fuel) : fuelType(fuel) {
            cout << " Vehicle Constructor Called ( Fuel : " << fuelType << ")\n";
        }

        // Virtual Destructor: Zaroori hai taaki child class ka destructor theek se call ho.
        virtual ~Vehicle(){
            cout << "Vehicle destructor called \n";
        }

        // getter method (Encapsulation)
        string getFuelType(){
            return fuelType;
        }

        // Pure Virtual Functions (Enforces that child classes MUST define these)
        virtual void start() = 0;
        virtual void stop() = 0;
};

// 3. DERIVED CLASSES (Function Overriding)

class Car : public Vehicle {
    public:
        Car() : Vehicle("Petrol"){
            cout << " -> Car Object Created\n";
        }
        ~Car() {
            cout << "    <- Car Object Destroyed\n";
        }
        void start() override {
            cout << "Car start with push button. \n";
        }

        void stop() override {
            cout << "Car stop with ABS Brakes. \n";
        }

        void claimInsurance() override {
            cout << "Car Insurance Claimed: Four-Wheeler Comprehensive.\n";
        }
};

class Bike : public Vehicle {
    public:
        Bike() : Vehicle("Petrol") {
            cout << " -> Bike Object Created\n";
        }
        ~Bike() {
            cout << " -> Bike Object Destroyed\n";
        }

        void start() override{
            cout << "Bike is starting with kick start.\n";
        }
        void stop() override{
            cout << "Bike is stops with disc brakes.\n";
        }
        void claimInsurance() override {
        cout << "Bike Insurance Claimed: Two-Wheeler Basic.\n";
    }
};


int main(){
    // Vector of Base Class Pointers (Polymorphism container)
    vector<Vehicle*> garage;

    // Creating objects using 'new' (Dynamic Memory Allocation)
    garage.push_back(new Car());
    garage.push_back(new Bike());

    cout << "\n--- Testing Runtime Polymorphism ---\n";
    for(Vehicle* v : garage){
        v -> start();           // Dynamic Binding: Decides at runtime which start() to call
        v -> claimInsurance();
        v -> stop();
        cout << "-------------------\n";
    }

    // C++ me explicitly delete karna padta hai (Destructors call honge)
    cout << "--- Cleaning up Memory ---\n";

    for(Vehicle *v : garage){
        delete v;
    }

    return 0;
}
