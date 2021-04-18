/*
** Fahrenheit degree to Celsius degree
** °C = (°F - 32) * 5 / 9
** Celsius degree to Fahrenheit degree
** °F = °C * 9 / 5 + 32
*/

#include <stdio.h>

#define DEGREE_TABLE_MAX		16

double	fahr_to_celsius(double fahr)
{
	return (((fahr - 32) * 5.0 / 9.0));
}

double	celsius_to_fahr(double celsius)
{
	return (celsius * 9.0 / 5.0 + 32);
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
		printf("fahr: %3.0f, fahr_to_celsius(): %6.1f\n", degree[idx][0], fahr_to_celsius((double)degree[idx][0]));
	for (int idx = 0; idx < DEGREE_TABLE_MAX; idx++)
		printf("celsius: %3.0f, celsius_to_fahr(): %6.1f\n", degree[idx][1], celsius_to_fahr((double)degree[idx][1]));
	return (0);
}
