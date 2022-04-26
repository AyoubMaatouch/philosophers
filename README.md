# philosophers
Dining philosophers problem solution in C<br>
in this project a got to  learn the basics of threading a process and how to create threads and got to  discover mutexes.

### Usage
```sh
$ make
$ ./philo [number of philosophers] [time to die] [time to eat] [time to sleep]
```
### Functions used

```
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
```
### Resources
[multithreading in C](https://www.geeksforgeeks.org/multithreading-c-2/)<br>
[mutex lock](https://www.youtube.com/watch?v=oq29KUy29iQ&ab_channel=CodeVault)
