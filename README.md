# CPE 2600 - Lab 10: Signals

## Description
This lab explores POSIX signals in Linux, including registering signal handlers, sending signals between processes, handling operating system signals, and transferring data using signals.

## Files

- **`signal_handler.c`** - Demonstrates how to register a signal handler for `SIGINT` and observe how a process responds when the signal is received.

- **`signal_alarm.c`** - Uses `alarm()` to schedule a `SIGALRM` signal after 5 seconds and handles the signal by displaying a message.

- **`signal_segfault.c`** - Demonstrates how a `SIGSEGV` signal occurs when dereferencing a NULL pointer and what happens when its handler returns without terminating the program.

- **`signal_sigaction.c`** - Uses `sigaction()` to register a handler for `SIGUSR1` and displays the PID of the process that sent the signal.

- **`recv_signal.c`** - Receives a `SIGUSR1` signal using `sigaction()` and displays the integer value sent with the signal.

- **`send_signal.c`** - Generates a random integer and sends it to another process using `sigqueue()` and `SIGUSR1`.

- **`Makefile`** - Automates the compilation of the C programs.

- **`.gitignore`** - Prevents generated executables and other unnecessary files from being tracked by Git.