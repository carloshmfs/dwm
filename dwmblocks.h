#ifndef DWMBLOCKS
#define DWMBLOCKS

#ifdef __OpenBSD__

#define SIGPLUS			SIGUSR1+1
#define SIGMINUS		SIGUSR1-1

#else

#define SIGPLUS			SIGRTMIN
#define SIGMINUS		SIGRTMIN

#endif

#include <X11/Xlib.h>

typedef enum {
    shell_cmd,
    callback
} command_type;

typedef struct {
	char* icon;
    command_type type;
    union {
        char* cmdstr;
        char* (*cmdfun)(void);
    } command;
	unsigned int interval;
	unsigned int signal;
} Block;

#ifndef __OpenBSD__
void dummysighandler(int num);
#endif

void sighandler(int num);
void getcmds(int time);
void getsigcmds(unsigned int signal);
void setupsignals();
void sighandler(int signum);
int getstatus(char *str, char *last);
void statusloop();
void termhandler();
void pstdout();
void* initblocks(void* args);


#endif /* DWMBLOCKS */
