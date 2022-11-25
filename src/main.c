#include "../include/philo.h"
void philo_printf(t_philo *philo);

int parce_input(int ac, char **av, t_philo *philo)
{
		// printf("ac is:%i\n", ac);
		if (ac < 5)
		{
			printf ("not enough arguments\n");
			return (1);
		}
		else if (ac > 6)
		{
			printf ("too many arguments\n");
			return (1);
		}
		philo->t_to_die = atoi(av[2]);
		philo->t_to_eat = atoi(av[3]);
		philo->t_to_sleep = atoi(av[4]);
		if (ac == 6)
		{
			philo->option = true;
			philo->times_to_eat = atoi(av[5]);
		}
	return (0);
}
int main (int ac, char **av)
{
	t_philo philo;
	if (parce_input(ac, av, &philo))
		return (1);
	philo_printf(&philo);
	return (0);
}

void philo_printf(t_philo *philo)
{
	printf("%d\n", philo->t_to_die);
	printf("%d\n", philo->t_to_eat);
	printf("%d\n", philo->t_to_sleep);
	printf("%d\n", philo->t_to_eat);
	if (philo->option)
		printf("%d", philo->times_to_eat);
}