#include <stdio.h>
#include <stdlib.h>
#include "include.h"

int main (void)
{
	FILE *f; char name[30];
	printf ("Enter the name of file\n");
	scanf ("%s", name); 

	if ((f=fopen(name, "r")) == NULL)
	{
		printf("File can't be open\n");
	} 
	else 
	{
		polygons(f);
		fclose(f);
	}
	return 0;
}
