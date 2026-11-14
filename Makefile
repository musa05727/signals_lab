CC=gcc
CFLAGS=-Wall -MMD

SOURCES=recv_signal.c send_signal.c signal_alarm.c signal_handler.c signal_segfault.c signal_sigaction.c
EXECUTABLES=$(SOURCES:.c=)

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES) *.d *.o