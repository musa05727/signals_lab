
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>

void handler(int sig, siginfo_t *info, void *context ){
    if(info->si_code == SI_QUEUE){
        printf("%d\n", info->si_value.sival_int); 
    }
    
}
int main(int argc, char* argv[]){
    wait(NULL); 
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