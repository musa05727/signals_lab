/**
* @file signal_handler.c
* @brief Sets a signal handler for SIGINT, the handler prints a message and then
quits
*/
/**
* Modified by:
* Musa Abdul hamid
* Brief summary of modifications:
* Killed the process by using SIGKILL instead of exit(); 
*/
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
/**
* @brief Signal handler for SIGINT - prints a message and exits
*/
void handle_signal() {
    printf("\nReceived a signal\n");
    if(kill(getpid(), SIGKILL) == -1){
        printf("Failed to kill the process.\n"); 
    }
}
int main() {
    printf("%d\n", getpid()); 
    // Register for the signal
    //SIGINT was sent using the CTRL+C 
    //and kill command: kill <PID>
    signal(SIGINT, handle_signal);
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }
    return 0; 
}