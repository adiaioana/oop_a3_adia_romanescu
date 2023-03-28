#pragma once
#include "Weather.h"

class Car {
	// (fuel capacity, fuel consumption, average speed on different conditions (Rain, Sunny, Snow)).
	
	public:
	int car_number;
	float fuel_consumption[4];
	int capacity[4];
	double average_speed[4];
	bool init[4];
	int time[4];
	//virtual void setProp(float A[4], int B[4], double C[4]);

	Car();
};
