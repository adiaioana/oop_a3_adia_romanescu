#pragma once
#include "Circuit.h"
#include <tuple>
#include <iostream>
using namespace std;

Circuit::Circuit()
{
	this->countOfCars = 0;
	this->lenght = 0;
	this->typeOfWeather = Weather::Sunny;
}
Circuit::~Circuit()
{
	this->countOfCars = 0;
	this->lenght = 0;
	this->typeOfWeather = Weather::Sunny;
	for(int i=1; i<=this->countOfCars; ++i)
		delete this->cars[i];
}

int meteo(Weather X)
{
	if (X == Weather::Rain)
		return 0;
	if (X == Weather::Sunny)
		return 1;
	return 2;
}

bool Circuit::finished(Car* C)
{
	if (C->fuel_consumption[meteo(this->typeOfWeather)] * this->lenght > C->capacity[meteo(this->typeOfWeather)])
		return 0;
	if (C->average_speed == 0)
		return 0;
	return 1;
}


bool Circuit::faster(Car* A, Car* B)
{
	if (!finished(A) && finished(B))
		return 0;
	if (finished(A) && !finished(B))
		return 1;
	return (A->average_speed >= B->average_speed);
}

void Circuit::ShowFinalRanks()
{
	bool ok = 1;
	do {
		ok = 0;
		
		for (int i = 1; i < this->countOfCars; ++i)
			if(faster(this->cars[i], this->cars[i+1])==0)
			{
				ok = 1;
				for (int j = 0; j < 3; ++j)
				{	
					swap(this->cars[i]->average_speed[j], this->cars[i+1]->average_speed[j]);
					swap(this->cars[i]->fuel_consumption[j], this->cars[i+1]->fuel_consumption[j]);
					swap(this->cars[i]->capacity[j], this->cars[i+1]->capacity[j]);
					swap(this->cars[i]->init[j], this->cars[i + 1]->init[j]);
				}
			}


	} while (ok);

	for(int ind=1; ind<=this->countOfCars; ++ind)
		if (this->finished(this->cars[ind]))
		{
			std::cout << ind << ' ';
		}
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int ind = 1; ind <= this->countOfCars; ++ind)
		if(!finished(this->cars[ind]))
		{
			std:: cout << ind << ' ';
		}
}
void Circuit::SetWeather(Weather K)
{
	this->typeOfWeather = K;
}
void Circuit::SetLength(int x)
{
	this->lenght = x;
}

void Circuit::AddCar(Car* C)
{
	int ind = this->countOfCars + 1;
	this->countOfCars++;
	this->cars[ind] = new Car;
	for (int i = 0; i < 3; ++i)
	{
		this->cars[ind]->average_speed[i] = C->average_speed[i];
		this->cars[ind]->fuel_consumption[i] = C->fuel_consumption[i];
		this->cars[ind]->capacity[i] = C->capacity[i];
		this->cars[ind]->init[i] = 1;
	}
}
