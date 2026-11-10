/**
* @file signal_segfault.c
* @brief Program that dereferences a null pointer causing a segmentation fault
*/
/**
* Modified by:
* Musa Abdul Hamid
* Brief summary of modifications:
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void seg_handler(){
    printf("Seg fault received\n"); 
    //if i don't have an exit, the program will keep printing the above statement.
    //This is because when the signal is handled, the program goes back to derefrencing a null pointer; 
    exit(0);
}
int main (int argc, char* argv[]) {
    signal(SIGSEGV, seg_handler); 
    // Declare a null pointer
    int* i = NULL;
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);
    // Return to exit the program
    return 0;
}