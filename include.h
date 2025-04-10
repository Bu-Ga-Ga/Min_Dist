#include <stdio.h>
#include <stdlib.h>
#include <cmath>
typedef struct 
	{
		double x;
		double y;
	} 
	Point;
	int polygons(FILE *f);
	double distance (Point A, Point B);
	int cosinus (Point A, Point B, Point C);
	double ro(Point P,double A,double B,double C);
	double halfplane (Point A, Point B, Point C);
