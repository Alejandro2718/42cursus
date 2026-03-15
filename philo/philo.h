#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


typedef struct s_philo t_philo;

typedef struct s_data {
    int n_of_philosophers; // and number of forks
    int time_to_die; //in miliseconds, si se le acaba este tiempo el philosofo muere
    int time_to_eat; // in miliseconds, el tiempo que le toma al philo comer, necesita ambos forks durante este tiempo
    int time_to_sleep; // in miliseconds, el tiempo que va a estar durmiendo
    int num_of_times_philo_must_eat; // argumento opcional, si cada philo no come al menos esta cantidad de veces, el programa para.
    //si no especificado el programa solo para cuando un philo haya muerto
    int dead_flag; // 0 if alive, 1 if someone died
    long start_time;
    pthread_mutex_t dead_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t *forks;
    t_philo *philos;
} t_data;

typedef struct s_philo {
    
    int philo_index; // cada philo tiene un numero desde el 1 a n (n_of_philosophers)
    int meals_eat;
    long last_meal_time;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data *data; //link to the data struct

}  t_philo;


int		ft_atoi(const char *str);
int		parser(t_data *data, int argc, char **argv);
void	ft_usleep(int ms, t_philo *philo);
void	print_status(t_philo *philo, char *message);
int		check_dead(t_philo *philo);
long	get_time_ms(void);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	*philo_routine(void *arg);
void	*monitor_thread(void *arg);


#endif