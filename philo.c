#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>



void*   print_info()
{
    // time_t t;
    // struct tm *info;
    // char buffer[64];
    
    // struct timeval current_time;
    // gettimeofday(&current_time, NULL);
    // t = current_time.tv_sec;
    // info = localtime(&t);
    // strftime (buffer, sizeof buffer, "The time is %I:%M:%S %p.\n", info);
    // printf("%s",buffer);
    // while (1)
        write (1 ,"here", 5);
    return NULL;
}

int main ()
{
    pthread_t p1, p2, p3, p4;

    pthread_create(&p1, NULL, print_info, NULL);
    // pthread_create(&p2, NULL, &print_info, NULL);
    // pthread_create(&p3, NULL, &print_info, NULL);
    // pthread_create(&p4, NULL, &print_info, NULL);
    // pthread_join(p4, NULL);
    // pthread_join(p3, NULL);
    // pthread_join(p2, NULL);
    // pthread_join(p1, NULL);



}