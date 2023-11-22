/*
*file name: read_resistance.cpp
*This function initializes an AnalogIn object with AIN0, then uses this object to read an ADC sample.
*It calculates the voltage across the bottom resistor and then calculates the resistance of this resistor using the voltage divider formula.
*The calculated resistance is then printed to the console.
*
*Command Line Arguments: None
*Example Invocation: ./read_resistance
*/
#include <iostream>
#include <iomanip>
#include "analogIn.h"

#define TOP_RESISTOR 10000.0 // 10k Ohm
#define MAX_ADC_VALUE 4096.0 // Maximum ADC value for 12 bit resolution
#define SUPPLY_VOLTAGE 1.8 // Supply voltage in Volts

int main(){
    AnalogIn adc(0); // Using AIN0 to read analog value.
    std::cout << "Using AIN0 to read analog value." << std::endl;
    std::cout << "Measuring resistance ..." << std::endl;

    // Read ADC value
    int adc_value = adc.readAdcSample();
    std::cout << "ADC value is: " << adc_value << std::endl;

    // Calculate the voltage across the bottom resistor
    double voltage = (adc_value / MAX_ADC_VALUE) * SUPPLY_VOLTAGE;

    // Calculate the resistance using the voltage divider formula
    double resistance = TOP_RESISTOR * ((SUPPLY_VOLTAGE / voltage) - 1);

    // Print the resistance
    if(resistance >= 1000){
        std::cout << "Resistance: " << std::fixed << std::setprecision(2) << resistance/1000 << "K Ohms" << std::endl;
    } else {
        std::cout << "Resistance: " << std::fixed << std::setprecision(0) << resistance << " Ohms" << std::endl;
    }

    return 0;
}
