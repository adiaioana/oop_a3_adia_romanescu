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

bool Circuit::finished(Car* C, int tp)
{
	if (C->average_speed == 0)
		return 0;
	if (C->fuel_consumption[tp] * this->lenght > C->capacity[tp])
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

void Circuit::masina(Car* A)
{
	char bmw[] = "BMW";
	char volvo[] = "Volvo";
	char seat[] = "Seat";
	char fiat[] = "Fiat";
	char rangerover [] = "RangeRover";

	if (A->car_number == 1)
		cout << bmw;
	else if (A->car_number == 2)
		cout << volvo;
	else if (A->car_number == 3)
		cout << seat;
	else if (A->car_number == 4)
		cout << fiat;
	else if (A->car_number == 5)
		cout << rangerover;
	else
		cout << "EROARE";
}


void Circuit::ShowFinalRanks()
{
	bool ok = 1;
	do {
		ok = 0;
		
		for (int i = 1; i < this->countOfCars; ++i)
			if (!faster(this->cars[i], this->cars[i + 1]))
			{
				ok = 1;
				for (int j = 0; j < 3; ++j)
				{
					swap(this->cars[i]->average_speed[j], this->cars[i + 1]->average_speed[j]);
					swap(this->cars[i]->fuel_consumption[j], this->cars[i + 1]->fuel_consumption[j]);
					swap(this->cars[i]->capacity[j], this->cars[i + 1]->capacity[j]);
					swap(this->cars[i]->init[j], this->cars[i + 1]->init[j]);
				}
				swap(this->cars[i], this->cars[i + 1]);
			}


	} while (ok);

	cout << "Rankings>" << '\n';
	for(int ind=1; ind<=this->countOfCars; ++ind)
		if (this->finished(this->cars[ind]))
		{
			cout << ind << ' ';
			masina(this->cars[ind]);
			cout<< endl;
		}
}

void Circuit::Race()
{
	for (int ind = 1; ind <= this->countOfCars; ind++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (!finished(this->cars[ind],j))
				this->cars[ind]->time[j] = this->lenght / this->cars[ind]->average_speed[j];
			else this->cars[ind]->time[j] = -1;
		}
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	int nr = 0;
	for (int ind = 1; ind <= this->countOfCars; ++ind)
		if(!finished(this->cars[ind]))
		{
			if (nr == 0)
				cout << "The cars that didn't finish the race " << endl;
			nr++;
			cout << ind << ' ';
			masina(this->cars[ind]);
			cout<< endl;
		}

	if (!nr)
		cout << "All cars finished the race" << endl;
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
	this->cars[ind]->car_number = C->car_number;
}
