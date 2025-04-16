#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include.h"

double distance (Point A, Point B)
{
	double r;
	r = sqrt(pow(B.x-A.x, 2)+pow(B.y-A.y, 2));	
	return r;
}
  
int cosinus (Point A, Point B, Point C)
{
	double cos1, cos2;
	cos1 = (B.x-A.x)*(C.x-A.x)+(B.y-A.y)*(C.y-A.y); 
	cos2 = (A.x-B.x)*(C.x-B.x)+(A.y-B.y)*(C.y-B.y);	
	if (cos1>=0&&cos2>=0)
	{
		return 0; 
	}
	else
	{
		return 1;
	} 
}
  
double ro(Point P, double A, double B, double C)
{
	double R;
	R = fabs(A*P.x+B*P.y+C)/pow(A*A+B*B, 0.5);	
	return R;
}

double halfplane (Point A, Point B, Point C) 
{
	double F, A1, B1, C1;
	Point vec;
	vec.x = B.x-A.x;	
	vec.y = B.y-A.y;
	A1 = vec.y+0;
	B1 = -vec.x+0;
	C1 = vec.x*A.y-vec.y*A.x;
	F = A1*C.x+B1*C.y+C1;
	return F; 
}	
