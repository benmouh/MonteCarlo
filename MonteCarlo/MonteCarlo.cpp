// MonteCarlo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>


/* Resolving Pi using Monte Carlo Method*/
struct Point
{
	double x;
	double y;

};
double approximatPi(Point& inP, int inRange)
{
	double pi = 0;
	double d = 0;
	int howManyInside = 0; // asuming x^2 + y^2 <= R^2 --> P may be inside
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 1);

	for (int i = 0; i < inRange; ++i)
	{
		inP.x = distribution(generator);
		inP.y = distribution(generator);
		d = (inP.x * inP.x) + (inP.y * inP.y);
		if (d < 1)
			howManyInside++;
	}
	pi = (4.0 * howManyInside) / inRange;

	return pi;
}
int main()
{

	Point p;
	p.x = 0;
	p.y = 0;
	/* Let's calculate statistics according to this interval */
	double pi = approximatPi(p, 10000);
	std::cout << "value of pi == " << pi << std::endl;
	getchar();
	return 0;
}

