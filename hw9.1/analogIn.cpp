/** File name: analogIn.cpp
* Class for wrapping functionality of analog input pins.
*
* Written by Amer Qouneh, October 30, 2020.
*/
#include <iostream>
#include <sstream>
#include "analogIn.h"
#include <string>
#include <fstream>
#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
using std::cout;
using std::endl;
AnalogIn::AnalogIn(){ }
AnalogIn::AnalogIn(unsigned int n){
	number = n;
}
void AnalogIn::setNumber(unsigned int n){
	number = n;
}
int AnalogIn::readAdcSample(){
	int adc_value;
	std::stringstream ss;
	ss << ADC_PATH << number << "_raw";
	std::fstream fs;
	fs.open(ss.str().c_str(), std::fstream::in);
	fs >> adc_value;
	fs.close();
	return adc_value;
}
AnalogIn::~AnalogIn(){}
