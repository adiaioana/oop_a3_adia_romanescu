#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit {

	public:
		int countOfCars;
		Weather typeOfWeather;
		int lenght;
		Car* cars[110];
		Circuit();
		~Circuit();
		void AddCar(Car*);
		//virtual void Race() = 0;
		void ShowFinalRanks();
		void ShowWhoDidNotFinish();
		void SetWeather(Weather K);
		void SetLength(int x);
		bool finished(Car*);
		bool faster(Car*, Car*);
};

