#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// typedef enum bool
// {
// 	int 
// }

typedef struct philo
{
	int t_to_die;
	int t_to_eat;
	int t_to_sleep;
	bool option;
	int times_to_eat;
}	t_philo;
