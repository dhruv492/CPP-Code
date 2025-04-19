#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius
{
    private:
        float temperature;
    public:
        Celsius(float temp) : temperature(temp) {}

    operator Fahrenheit();

    float getTemperature() const
    {
        return temperature;
    }

    bool operator==(const Celsius& other) const
    {
        return temperature == other.temperature;
    }
};

class Fahrenheit
{
    private:
        float temperature;
    public:
        Fahrenheit(float temp) : temperature(temp) {}

    operator Celsius();

    float getTemperature() const
    {
        return temperature;
    }

    bool operator==(const Fahrenheit& other) const
    {
        return temperature == other.temperature;
    }
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit((temperature * 9 / 5) + 32);
}

Fahrenheit::operator Celsius()
{
    return Celsius((temperature - 32) * 5 / 9);
}

int main()
{
    Celsius celsiusObj(25.0);
    Fahrenheit fahrenheitObj = celsiusObj;

    cout << "Celsius: " << celsiusObj.getTemperature() << "°C\n";
    cout << "Fahrenheit: " << fahrenheitObj.getTemperature() << "°F\n";

    Celsius convertedBack = fahrenheitObj;

    cout << "Converted Back to Celsius: " << convertedBack.getTemperature() << "°C\n";

    Celsius anotherCelsius(25.0);
    if (celsiusObj == anotherCelsius)
    {
        cout << "Temperatures are equal.\n";
    }
    else
    {
        std::cout << "Temperatures are not equal.\n";
    }

    return 0;
}
