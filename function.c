#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include.h"

int polygons (FILE *f)
{
	Point *a, *b;
	int n, p, k = 0;
	Point A, B, C, vec,  I1, I2, J1, J2;
	double A1, B1, C1, R, r2, rmin1, t1, t2;
	
	fscanf(f, "%d", &n);	
	a=(Point *)malloc(n * sizeof(Point));
	for (int i=0; i<n; i++)
	{
		fscanf (f, "%lf", &vec.x);
		fscanf (f, "%lf", &vec.y);
		a[i]=vec;
	}

	fscanf(f, "%d", &p);
	b=(Point *)malloc(p * sizeof(Point));
	for (int i=0; i<p; i++)
	{
		fscanf (f, "%lf", &vec.x);
		fscanf (f, "%lf", &vec.y);
		b[i] = vec;
	}
	A = a[0];
	B = b[0];
	
	for(int j=0; j<p; j++)
	{
		I1 = b[j];
		if(j==p-1)
		{
			I2 = b[0];
		}
		else
		{
			I2 = b[j+1];
		}
		for(int i=0; i<n; i++)
		{
			J1 = a[i];
			if(i==n-1)
			{
				J2 = a[0];
			}
			else
			{
				J2 = a[i+1];
		        }
				t1 = halfplane(I1, I2, J1);
				t2 = halfplane(I1, I2, J2);
			if (t1*t2<0)
			{
				t1 = halfplane(J1, J2, I1);
				t2 = halfplane(J1, J2, I2);
				if (t1*t2<0)
				{
					printf("These polygons have an intersection \nrmin1 = 0");
					return 0;
				}
			}		
		}		
	}
	rmin1 = distance(A, B);
	for (int i=0; i<n; i++)
	{
		A=a[i];
		for (int j=0; j<p; j++)
		{
			B = b[j];
			r2 = distance (A, B);	
			if (r2<rmin1)
			{
				rmin1 = r2;
			}
		}	
	}
	for(int i=0; i<n; i++)
	{
		A = a[i];
		if(i==n-1)
		{
			B = a[0];
		}
		else
		{
			B = a[i+1];
		}
		vec.x = B.x-A.x;
		vec.y = B.y-A.y;
		A1 = vec.y+0;
		B1 = -vec.x+0;
		C1 = vec.x*A.y-vec.y*A.x;
		for(int j=0; j<p; j++)
		{
			C = b[j];
			k = cosinus (A, B, C);
			if(k==0)
			{
				R = ro(C, A1, B1, C1);
				if(R<rmin1)
				{
					rmin1 = R;
				}
			}
		}		
	}
	for(int i=0;i<p;i++)
	{
		A = b[i];
		if(i==p-1)
		{
			B = b[0];
		}
		else
		{
			B = b[i+1];
		}
		vec.x = B.x-A.x;		
		vec.y = B.y-A.y;
		A1 = vec.y+0;
		B1 = -vec.x+0;
		C1 = vec.x*A.y-vec.y*A.x;
		for(int j=0; j<n; j++)
		{
			C = a[j];
			k = cosinus(A, B, C);
			if(k==0)
			{
				R = ro(C, A1, B1, C1);
				if(rmin1-R>0)
				{
					rmin1 = R;
				}
			}
		}		
	}
	if(rmin1<1e-200)
	{
		printf ("rmin1 = %lf\nThese polygons have a one point of intersection\n", rmin1);
	}
	else
	{
		printf ("rmin1 = %lf\n", rmin1);
	}
	free(a);
	free(b);
	return 0;
}	 
