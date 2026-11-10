/**
* File: signal_alarm.c 
* Modified by: Musa Abdul Hamid
*
* Brief summary of program:
* Schedules an alarm to be sent after 5 seconds. 
*/
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void alarm_handler(){
    printf("Signal received\n"); 
    exit(EXIT_SUCCESS); 
}
int main(int argc, char* argv[]){
    signal(SIGALRM, alarm_handler); 

    alarm(5); 

    while(1){
        printf("Sleeping\n"); 
        sleep(1);
    }
    return 0; 
}