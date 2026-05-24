import java.util.ArrayList;
import java.util.List;

// 1. INTERFACE: Java has a direct keyword for this.
interface Insurance {
    void claimInsurance(); 
}

// 2. ABSTRACT CLASS
abstract class Vehicle implements Insurance {
    private String fuelType; // Encapsulation

    // Constructor
    public Vehicle(String fuelType) {
        this.fuelType = fuelType;
        System.out.println("[+] Vehicle Constructor (Fuel: " + this.fuelType + ")");
    }

    // Getter
    public String getFuelType() {
        return fuelType;
    }

    // Abstract methods (Java's version of pure virtual functions)
    public abstract void start();
    public abstract void stop();
}

// 3. DERIVED CLASSES
class Car extends Vehicle {
    public Car() {
        super("Petrol"); // Calls the base class (Vehicle) constructor
        System.out.println("    -> Car Object Created");
    }

    @Override
    public void start() {
        System.out.println("Car is starting with push button.");
    }

    @Override
    public void stop() {
        System.out.println("Car is stopping with ABS brakes.");
    }

    @Override
    public void claimInsurance() {
        System.out.println("Car Insurance Claimed: Four-Wheeler Comprehensive.");
    }
}

class Bike extends Vehicle {
    public Bike() {
        super("Petrol");
        System.out.println("    -> Bike Object Created");
    }

    @Override
    public void start() {
        System.out.println("Bike is starting with kick start.");
    }

    @Override
    public void stop() {
        System.out.println("Bike is stopping with disc brakes.");
    }

    @Override
    public void claimInsurance() {
        System.out.println("Bike Insurance Claimed: Two-Wheeler Basic.");
    }
}

// 4. vehicle_managment 
public class vehicle_managment {
    public static void main(String[] args) {
        // List of Base Class References (Java's version of vector of pointers)
        List<Vehicle> garage = new ArrayList<>();

        // Creating objects (new keyword)
        garage.add(new Car());
        garage.add(new Bike());

        System.out.println("\n--- Testing Runtime Polymorphism ---");
        for (Vehicle v : garage) {
            v.start(); // Dynamic Binding
            v.claimInsurance();
            v.stop();
            System.out.println("----------------------");
        }
        
        // No manual memory cleanup needed in Java! 
        // Garbage Collector will handle it.
    }
}