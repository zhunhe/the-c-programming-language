/*
** Fahrenheit degree to Celsius degree
** °C = (°F - 32) * 5 / 9
*/

#include <stdio.h>

#define DEGREE_TABLE_MAX		16

double	fahr_to_celsius(double fahr)
{
	return (((fahr - 32) * 5.0 / 9.0));
}

int		main(void)
{
	double	degree[DEGREE_TABLE_MAX][2] = {
		{0, -17},
		{20, -6},
		{40, 4},
		{60, 15},
		{80, 26}, 
		{100, 37},
		{120, 48},
		{140, 60},
		{160, 71},
		{180, 82},
		{200, 93},
		{220, 104},
		{240, 115},
		{260, 126},
		{280, 137},
		{300, 148}};
	
	for (int idx = 0; idx < DEGREE_TABLE_MAX; idx++)
		printf("fahr: %3.0f, fahr_to_celsius(): %6.1f\n"
				, degree[idx][0], fahr_to_celsius((double)degree[idx][0]));
	return (0);
}
