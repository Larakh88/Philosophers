# Philosophers

## Introduction:
The Dining Philosophers Problem is a classic synchronization challenge that illustrates the complexities of resource allocation and concurrency control. In this scenario, a group of philosophers sits around a circular table, where each philosopher alternates between thinking and eating. A large bowl of spaghetti is placed at the center of the table, with forks distributed evenly between each philosopher. To eat, a philosopher must hold both the fork on their left and right sides.

However, in this **`Philosophers`** project at School 42, an additional state of sleeping is introduced, adding complexity to the simulation. Philosophers alternate between eating, thinking, and sleeping, with strict rules governing their actions. Furthermore, an optional parameter allows specifying the number of times each philosopher must eat before the program ends. If this parameter is provided, all philosophers must meet this eating threshold to conclude the simulation; otherwise, they face the risk of starvation.

# Description
* **Philosophers**: A group of philosophers (numbered from 1 to N) sit at a round table.
* **Spaghetti Bowl**: There is a large bowl of spaghetti in the middle of the table.
* **Forks**: There are as many forks as there are philosophers. Each philosopher needs two forks to eat.
* **Actions**:
	* Philosophers alternate between three actions: eating, thinking, and sleeping.
	* While eating, a philosopher holds both their right and left forks.
	* While thinking or sleeping, they release the forks.
	* Philosophers do not speak to each other.
	* They do not know if another philosopher is about to die.
	* The simulation stops when a philosopher dies of starvation.
* **Constraints**:
	* Philosophers should never starve.
	* Avoid deadlocks (where all philosophers are waiting for a fork).
	* Implement the solution without using global variables.

# Compile
1. Clone this repository
2. Compile the project:
```make all```
3. Run the program using the below command:

```./philo [number_of_philos] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]```

![philo](https://github.com/Larakh88/Philosophers/assets/88907380/c3f3fecf-4018-4de0-9605-69ffeb367ec8)

# Conclusion
This project presents a challenging exercise in concurrent programming and synchronization. I gained valuable experience in managing threads and mutexes to ensure the correct behavior of the philosophers' simulation without encountering deadlock or starvation.
