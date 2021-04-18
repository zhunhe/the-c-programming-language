/*
** Fahrenheit degree to Celsius degree
** °C = (°F - 32) * 5 / 9
*/

#include <stdio.h>

#define DEGREE_TABLE_MAX		16

int	fahr_to_celsius(int fahr)
{
	return ((int)(((double)fahr - 32) * 5.0 / 9.0));
}

int	main(void)
{
	int	degree[DEGREE_TABLE_MAX][2] = {
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
		printf("fahr: %3d, fahr_to_celsius(): %3d, celsius: %3d\n"
				, degree[idx][0], fahr_to_celsius(degree[idx][0]), degree[idx][1]);
	return (0);
}
