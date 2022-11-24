#include "../include/philo.h"

int main (int ac, char **av)
{
	if (av != NULL)
	printf("ac is%i\n", ac);
	if (ac < 5)
	{
		printf ("not enough arguments\n");
		return (1);
	}
	if (ac == 5)
		printf ("1. case\n");
	if (ac == 6)
		printf ("2. case\n");
	if (ac > 6)
	{
		printf ("too many arguments\n");
		return (1);
	}
	return (0);
}