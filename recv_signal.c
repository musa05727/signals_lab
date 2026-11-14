/**
* File: recv_signal.c 
* Modified by: Musa Abdul Hamid 
*
* Brief summary of program:
* prints the number sent by send_signal.c by using sigaction to register SIGSUR1 and 
* the sigaction struct to get the number.  
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *context ){
    if(info->si_code == SI_QUEUE){
        printf("%d\n", info->si_value.sival_int); 
    }
    
}
int main(int argc, char* argv[]){ 
    struct sigaction sa = {0}; 
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO; 
    sigemptyset(&sa.sa_mask); 
    sigaction(SIGUSR1, &sa, NULL); 
    printf("%d\n", getpid());
    while(1){
        printf("...\n"); 
        sleep(1); 
    }
    

    return 0; 
}