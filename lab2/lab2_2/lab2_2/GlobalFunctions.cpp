#include <cstring>
#include "Student.h"
#include "GlobalFunctions.h"

int CompareName(Student A, Student B)
{
	if (strcmp(A.GetName(), B.GetName()) > 0)
		return 1;
	if (strcmp(A.GetName(), B.GetName()) < 0)
		return -1;
	return 0;
}

int CompareMath(Student A, Student B)
{
	if (A.GetMath() > B.GetMath())
		return 1;
	if (A.GetMath() < B.GetMath())
		return -1;
	return 0;
}

int CompareHistory(Student A, Student B)
{
	if (A.GetHistory() > B.GetHistory())
		return 1;
	if (A.GetHistory() < B.GetHistory())
		return -1;
	return 0;
}

int CompareEnglish(Student A, Student B)
{
	if (A.GetEnglish() > B.GetEnglish())
		return 1;
	if (A.GetEnglish() < B.GetEnglish())
		return -1;
	return 0;
}

int CompareAverage(Student A, Student B)
{
	if (A.Average() > B.Average())
		return 1;
	if (A.Average() < B.Average())
		return -1;
	return 0;
}
