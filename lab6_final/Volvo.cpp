#pragma once
#include "Volvo.h"


Volvo::Volvo()
{
	this->car_number = 2;

	float FC[4] = { 0.3, 0.2, 0.4 };
	int C[4] = {2000, 2000, 2000};
	double AS[4] = { 56, 61, 81 };
	this->setProp(FC, C, AS);
}

void Volvo::setProp(float fc[4], int c[4], double as[4])
{
	this->car_number = 2;
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