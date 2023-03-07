#include "Canvas.h"
#include <cmath>
#include <iostream>
using namespace std;
//ofstream fout("of.txt");

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = x - ray; i <= x + ray; ++i)
		for (int j = y - ray; j <= y + ray; ++j)
			if (i > 0 && j > 0 && i < 1000 && j < 1000 && (int)sqrt((x - i) * (x - i) + (y - j) * (y - j)) == ray)
				this->mat[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = x - ray; i <= x + ray; ++i)
		for (int j = y - ray; j <= y + ray; ++j)
			if (i > 0 && j > 0 && i < 1000 && j < 1000 && (x-i)*(x-i)+(y-j)*(y-j)<=ray*ray)
				this->mat[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; ++i)
	{
		this->mat[i][top] = ch;
		this->mat[i][bottom] = ch;
	}
	for (int j = top; j <= bottom; ++j)
	{
		this->mat[left][j] = ch;
		this->mat[right][j] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; ++i)
		for (int j = top; j <= bottom; ++j)
			this->mat[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->mat[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	double panta =(float) (y2 - y1) / (float)(x2 - x1);
	double npanta = y2 - panta * x2;
	double aproxy; int yint;
	for (int i = x1; i <= x2; ++i)
	{	
		aproxy = i * panta + npanta; yint = (int)aproxy;
		this->mat[i][yint] = ch;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->width; ++i, cout << '\n')
		for (int j = 0; j < this->height; ++j)
			cout << this->mat[i][j];
}

void Canvas::Clear()
{
	for (int i = 0; i < this->width; ++i)
		for (int j = 0; j < this->height; ++j)
			this->mat[i][j] = ' ';
}
