#include <cstdio>
#pragma once
class Student {

	int UID;
	char* name;
	float grade_math, grade_history, grade_english;

public:
	int GetInd()
	{
		return this->UID;
	}

	void Init(int k)
	{
		this->UID = k;
		strcpy_s(this->name, sizeof this->name,"noname");
		this->grade_math = this->grade_history = this->grade_math = 0;
	}
	char* GetName()
	{
		char* p;
		p = NULL;
		if (strcmp(this->name, "noname") == 0)
		{
			printf("%d doesn't have a name || ", this->UID);
			return p;
		}
		p = this->name;
		printf("The name of %d is %s  || ", this->UID, this->name);
		return p;
	}
	void SetName(char* p)
	{
		strcpy_s(this->name, sizeof this->name, p);
	}
	float GetMath()
	{
		if (this->grade_math == 0)
		{
			printf("%d doesn't have a math grade || ", this->UID);
			return 0;
		}
		printf("The math grade of %d is %f  || ", this->UID, this->grade_math);
		return this->grade_math;
	}
	float GetHistory()
	{
		if (this->grade_history == 0)
		{
			printf("%d doesn't have a history grade || ", this->UID);
			return 0;
		}
		printf("The history grade of %d is %f  || ", this->UID, this->grade_history);
		return this->grade_history;
	}
	float GetEnglish()
	{
		if (this->grade_english == 0)
		{
			printf("%d doesn't have a english grade || ", this->UID);
			return 0;
		}
		printf("The english grade of %d is %f  || ", this->UID, this->grade_english);
		return this->grade_english;
	}
	void SetMath(float nr)
	{
		this->grade_math = nr;
	}
	void SetHistory(float nr)
	{
		this->grade_history = nr;
	}
	void SetEnglish(float nr)
	{
		this->grade_english = nr;
	}
	float Average()
	{
		float sum = 0;
		int nr = 0;
		if (this->grade_english == 0)
			nr++, sum += this->grade_english;
		if (this->grade_math == 0)
			nr++, sum += this->grade_math;
		if (this->grade_history == 0)
			nr++, sum += this->grade_history;
		return (float)(sum / nr);
	}
}; 