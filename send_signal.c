#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){
    srand(time(NULL)); 

    int random_val = rand(); 
    union sigval value; 

    value.sival_int = random_val; 

    sigqueue(atoi(argv[1]), SIGUSR1, value);
    printf("sent %d to process %d\n", random_val, atoi(argv[1])); 
    return 0; 
}