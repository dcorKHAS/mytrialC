#include <iostream>
#include <cstdlib>  // for random temperature generation
#include<windows.h>  
//#include<unistd.h>
class TemperatureSensor {
private:
    double currentTemperature;

public:
    TemperatureSensor() : currentTemperature(0.0) {}

    // Simulate reading temperature data (replace with actual sensor communication)
    void readTemperature() {
        // In a real implementation, this would interact with sensor hardware.
        currentTemperature = 20.0 + (rand() % 11 - 5);  // Simulated temperature data between 15°C and 25°C
    }

    double getCurrentTemperature() {
        return currentTemperature;
    }
};

class Thermostat {
public:
    void controlTemperature(TemperatureSensor& sensor) {
        sensor.readTemperature();
        double currentTemp = sensor.getCurrentTemperature();
        if (currentTemp < 20.0) {
            // It's too cold, turn on the heater
            std::cout << "Heating: Temperature is " << currentTemp << "°C. Turning on the heater.\n";
            // Add code to control heating system
        }
        else if (currentTemp > 25.0) {
            // It's too hot, turn on the AC
            std::cout << "Cooling: Temperature is " << currentTemp << "°C. Turning on the air conditioner.\n";
            // Add code to control cooling system
        }
        else {
            // Temperature is within the comfort range
            std::cout << "Comfortable: Temperature is " << currentTemp << "°C. No action required.\n";
        }
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    TemperatureSensor roomSensor;
    Thermostat thermostat;

    // Simulate temperature control
    for (int i = 0; i < 5; ++i) {
        thermostat.controlTemperature(roomSensor);
        // Wait for some time before the next temperature reading
        // Simulating the passage of time
        
        Sleep(2);

    }

    return 0;
}
