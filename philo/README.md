# Philosophers | Dining Philosophers Problem

*This project has been created as part of the 42 curriculum by alejjime.*

## Description

**Philosophers** solves the classic Dining Philosophers concurrency problem using **threads and mutexes**. N philosophers alternate between thinking, eating, and sleeping around a table. Each must acquire two forks to eat, requiring careful synchronization to prevent deadlocks and starvation.

## Compilation & Execution

```bash
cd philo && make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Example:**
```bash
./philo 5 800 200 200 7  # 5 philosophers, each eats 7 times before exit
```

**Output Format:**
```
0 1 has taken a fork
10 1 is eating
210 1 is sleeping
410 1 is thinking
```

## Architecture

| File | Purpose |
|------|---------|
| `philosopers.c` | Argument parsing, thread creation, simulation init/cleanup |
| `philo_actions.c` | Philosopher states: think, eat, sleep, routine |
| `utils.c` | Time, synchronization, output utilities |
| `philo.h` | Data structures and declarations |

## Implementation Highlights

- **Deadlock Prevention**: Asymmetric fork acquisition order (odd/even philosophers alternate direction)
- **Starvation Detection**: Monitor thread checks meal timestamps every 500µs
- **Synchronization**: 
  - `dead_lock`: Protects death flag and timestamps
  - `write_lock`: Prevents log interleaving
  - `forks[]`: Protects fork access
- **Memory Safe**: All allocations freed, no leaks

## Compliance

✅ Norminette compliant | ✅ No global variables | ✅ No memory leaks | ✅ All required Makefile rules

## Resources

- [POSIX Threads](https://www.gnu.org/software/libc/manual/html_node/POSIX-Threads.html)
- Dijkstra's Dining Philosophers (1965)

## AI Usage

AI was used for **testing edge cases** and **refactoring code to comply with Norminette** standards, particularly:
- Breaking long lines and complex conditions across multiple lines
- Identifying and extracting oversized functions (`monitor_thread`, `main`) into smaller, compliant helpers
- Verifying proper indentation and spacing according to 42 norms
- Validating the program logic through execution tests with various argument combinations
