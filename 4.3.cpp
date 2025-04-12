#include <iostream>
using namespace std;


class Fuel
{
protected:
    string fuelType;

public:
    Fuel(string fuelType) : fuelType(fuelType) {}
    virtual void displayDetails() const
    {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand
{
protected:
    string brandName;

public:
    Brand(string brandName) : brandName(brandName) {}
    virtual void displayDetails() const
    {
        cout << "Brand Name: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand
{
public:
    Car(string fuelType, string brandName) : Fuel(fuelType), Brand(brandName) {}
    void displayDetails() const override
    {
        Fuel::displayDetails();
        Brand::displayDetails();
    }
};

int main()
{
    const int queueSize = 3;
    Car serviceQueue[queueSize] =
    {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Ford"),
        Car("Electric", "Tesla")
    };

    cout << "Service Queue: Cars\n";
    for (int i = 0; i < queueSize; ++i)
    {
        cout << "Car " << (i + 1) << " Details:\n";
        serviceQueue[i].displayDetails();
        cout << "-----------------------------\n";
    }

}
