/**
* File: signal_sigaction.c 
* Modified by:
* Musa Abdul Hamid
* Brief summary of program:
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
void handler(){
    printf("%d\n", getpid());
}
int main(int argc, char* argv[]){
    
    struct sigaction sa = {0};
    sigaction(SIGUSR1, &sa, NULL); 
    sa.sa_handler = handler;  
    
    printf("%d\n", getpid());
    while(1){
        printf("....\n"); 
        sleep(1); 
    }
    return 0; 
}