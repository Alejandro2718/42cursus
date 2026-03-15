#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	temp;

	i = 0;
	negative = 0;
	temp = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - '0');
		i++;
	}
	if (negative)
		return (temp * -1);
	return (temp);
}

long get_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


int check_dead(t_philo *philo)
{
    int dead;

    pthread_mutex_lock(&philo->data->dead_lock);
    dead = philo->data->dead_flag;
    pthread_mutex_unlock(&philo->data->dead_lock);

    return (dead);

}


// para evitar duplicado de forks, se debe protejer los forks con mutex cada uno
// Cada philo deber ser un thread


//    ./philo 'arguments'
// Empiezo con el parser
// Lee los argumentos y guárdalos en una estructura t_data
int parser(t_data *data, int argc, char **argv)
{
    
    int i;
    int num;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (num <= 0)
            return (1);

        i++;
    }


    data->n_of_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->num_of_times_philo_must_eat = -1;
    if (argc == 6)
        data->num_of_times_philo_must_eat = ft_atoi(argv[5]);
    data->dead_flag = 0;

    pthread_mutex_init(&data->dead_lock, NULL);
    pthread_mutex_init(&data->write_lock, NULL);
    return (0);

}

void ft_usleep(int ms, t_philo *philo)
{
    long start;

    start = get_time_ms();
    while ((get_time_ms() - start) < ms)
    {
        if (check_dead(philo))
            break;
        usleep(100);
    }
}

void print_status(t_philo *philo, char *message)
{
    long time_stamp;

    pthread_mutex_lock(&philo->data->write_lock);
    time_stamp = get_time_ms() - philo->data->start_time;
    if (!philo->data->dead_flag)
        printf("%ld %d %s", time_stamp, philo->philo_index, message);
    pthread_mutex_unlock(&philo->data->write_lock);
}



void think(t_philo *philo)
{
    long think_time;

    print_status(philo, "is thinking\n");
    if (philo->data->n_of_philosophers % 2 != 0)
    {
        think_time = (philo->data->time_to_eat * 2)
            - philo->data->time_to_sleep;
        if (think_time < 0)
            think_time = 0;
        ft_usleep(think_time, philo);
    }
}

void eat(t_philo *philo)
{

    if (philo->philo_index % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork\n");
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork\n");
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork\n");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork\n");
    }

    pthread_mutex_lock(&philo->data->dead_lock);
    philo->last_meal_time = get_time_ms();
    pthread_mutex_unlock(&philo->data->dead_lock);
    print_status(philo, "is eating\n");
    ft_usleep(philo->data->time_to_eat, philo);
    pthread_mutex_lock(&philo->data->dead_lock);
    philo->meals_eat++;
    pthread_mutex_unlock(&philo->data->dead_lock);

    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);

}

void philo_sleep(t_philo *philo)
{
    print_status(philo, "is sleeping\n");
    ft_usleep(philo->data->time_to_sleep, philo);
}


void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->data->n_of_philosophers == 1)
    {
        print_status(philo, "has taken a fork\n");
        ft_usleep(philo->data->time_to_die, philo);
        return (NULL);
    }


    if (philo->philo_index % 2 == 0)
        ft_usleep(philo->data->time_to_eat / 2, philo);

    while (!check_dead(philo))
    {
        think(philo);
        if (check_dead(philo))
            break;
        eat(philo);
        if (check_dead(philo))
            break;
        philo_sleep(philo);
    }
    return (NULL);

}

void *monitor_thread(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;
    int all_ate;

    while (1)
    {
        i = 0;
        all_ate = 1;
        while (i < data->n_of_philosophers)
        {
            pthread_mutex_lock(&data->dead_lock);
            if ((get_time_ms() - data->philos[i].last_meal_time)
                >= data->time_to_die)
            {
                data->dead_flag = 1;
                pthread_mutex_unlock(&data->dead_lock);
                pthread_mutex_lock(&data->write_lock);
                printf("%ld %d died\n", get_time_ms() - data->start_time,
                    data->philos[i].philo_index);
                pthread_mutex_unlock(&data->write_lock);
                return (NULL);
            }
            if (data->num_of_times_philo_must_eat > 0
                && data->philos[i].meals_eat
                < data->num_of_times_philo_must_eat)
                all_ate = 0;
            pthread_mutex_unlock(&data->dead_lock);
            i++;
        }
        if (data->num_of_times_philo_must_eat > 0 && all_ate)
        {
            pthread_mutex_lock(&data->dead_lock);
            data->dead_flag = 1;
            pthread_mutex_unlock(&data->dead_lock);
            return (NULL);
        }
        usleep(500);
    }
}


int main(int argc, char**argv)
{
    t_data data;
    t_philo *philos;
    pthread_t monitor;
    int i;
    
    //check if not arguments are enough
    if (argc < 5 || argc > 6)
    {
        printf("Correct use: ./philo n_philo t_die t_eat t_sleep n_t_each_philo_must_eat\n");
        return (1);
    }

    

    if (parser(&data, argc, argv))
        return (1);

    //Crea un array de mutexes (tenedores) y un array de estructuras para cada filósofo.

    // espacio para N philos
    philos = malloc(sizeof(t_philo) * data.n_of_philosophers);
    if (!philos)
        return (1);
    //asignar espacio para N forks (mutexes)
    data.forks = malloc(sizeof(pthread_mutex_t) * data.n_of_philosophers);
    if (!data.forks)
    {
        free(philos);
        return (1);
    }

    
    data.philos = philos;
    data.start_time = get_time_ms();
    // loop for creating the threads
    i = 0;
    while (i < data.n_of_philosophers)
    {
        pthread_mutex_init(&data.forks[i], NULL);
        
        philos[i].data = &data;
        philos[i].philo_index = i + 1;
        philos[i].meals_eat = 0;
        philos[i].last_meal_time = get_time_ms();
        philos[i].left_fork = &data.forks[i];
        philos[i].right_fork = &data.forks[(i + 1) % data.n_of_philosophers]; //module works for assigning each fork even when the table is a circle
        
        //Despues de asginar, ahora si se crea el thread
        pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
        i++;
    }

    pthread_create(&monitor, NULL, monitor_thread, &data);

    //Join del monitor_thread
    pthread_join(monitor, NULL);

    //Wait to execute everyone, not closing abrutly
    i = 0;
    while (i < data.n_of_philosophers)
    {
        pthread_join(philos[i].thread, NULL); // esperar a que philos[i].thread termine
        i++;
    }

    //limpiamos los mutexes y los destruimos
    i = 0;
    while (i < data.n_of_philosophers)
    {
        pthread_mutex_destroy(&data.forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data.dead_lock);
    pthread_mutex_destroy(&data.write_lock);
    free(data.forks);
    free(philos);
    
    return (0);
}


