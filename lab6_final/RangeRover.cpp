#pragma once
#include "RangeRover.h"

RangeRover::RangeRover()
{
	this->car_number = 5;

	float FC[4] = { 0.3, 0.2, 0.4 };
	int C[4] = { 0, 0, 0 };
	double AS[4] = { 35, 50, 75 };
	this->setProp(FC, C, AS);
}

void RangeRover::setProp(float fc[4], int c[4], double as[4])
{
	this->car_number = 5;

	for (int i = 0; i < 3; i++)
	{
		this->fuel_consumption[i] = fc[i];
		this->capacity[i] = c[i];
		this->average_speed[i] = as[i];
	}
}
/*
float fuel_consumption[4];
int capacity[4];
double average_speed[4];
*/