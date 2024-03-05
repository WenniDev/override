#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <sys/types.h>
//#include <sched.h>  //vs code bug



int clear_stdin();
int get_unum();
void prog_timeout(int a1);
unsigned int enable_timeout_cons();
void term_proc();

int clear_stdin()
{
    char result = 0;

    while (result != '\n' && result != 255);
        result = getchar();
    return result;
}

int get_unum()
{
    unsigned int    nb = 0;

    fflush(stdout);
    scanf("%u", nb);
    clear_stdin();
    return nb;
}

void prog_timeout(int a1)
{
    sys_exit(1);
}

unsigned int enable_timeout_cons()
{
    signal(14, prog_timeout);
    return alarm(60);
}

int main(int argc, const char **argv, const char **envp)
{
    int status; // [esp+1Ch] [ebp-9Ch] BYREF
    char s[128];  // [esp+20h] [ebp-98h] BYREF
   
    int data;       // [esp+A8h] [ebp-10h]
    pid_t son;     // [esp+ACh] [ebp-Ch]

    son = fork();
    memset(s, 0, sizeof(s));
    data = 0;
    status = 0;
    if (son) // I'm your father
    {
        while (data != 11)
        {
            wait(&status);

            //reads the 7 low value bits (ascii code)
            if ((status & 0x7F) == 0 || (char)((status & 0x7F) + 1) >> 1 > 0)
            {
                puts("child is exiting...");
                return 0;
            }

            data = ptrace(PTRACE_PEEKUSER, son, 44, 0);
        }

        puts("no exec() for you");
        kill(son, SIGKILL);
    }
    else // son
    {
        /*
        ** Set the parent-death signal of the calling process to arg2
        ** (either a signal value in the range [1, NSIG - 1], or 0 to
        ** clear).  This is the signal that the calling process will
        ** get when its parent dies.
        */
        prctl(PR_SET_PDEATHSIG, SIGHUP);
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(s);
    }
    return 0;
}