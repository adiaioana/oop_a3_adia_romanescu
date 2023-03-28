#include "Car.h"


Car::Car(){

	this->car_number = 0;
	for(int i=0; i<3; ++i)
	{
		this->average_speed[i] = 0;
		this->capacity[i] = 0;
		this->fuel_consumption[i] = 0;
		this->init[i] = 0;
	}

}