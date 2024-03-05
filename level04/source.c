#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <sys/types.h>

int clear_stdin()
{
    char result = 0;

    while (result != '\n' && result != 255)
        ;
    result = getchar();
    return result;
}

int get_unum()
{
    unsigned int nb = 0;

    fflush(stdout);
    scanf("%u", nb);
    clear_stdin();
    return nb;
}

int main(int argc, const char **argv, const char **envp)
{
    int status = 0;
    char s[128];
    int data = 0;
    pid_t son = fork();
    memset(s, 0, sizeof(s));

    if (son) // I'm your father
    {
        while (data != 11)
        {
            wait(&status);
            /*
            **reads the 7 low value bits (ascii code)
            ** 0        Successful completion.
            ** 1-126    An error occurred.
            ** 127      A specified pid or job-id has terminated or is unknown by the invoking shell
            */
            if ((status & 0x7F) == 0 || (status & 0x7F) == 127)
            {
                puts("child is exiting...");
                return 0;
            }

            data = ptrace(PTRACE_PEEKUSER, son, 44, 0);
        }

        puts("no exec() for you");
        kill(son, SIGKILL);
    }
    else // I'm your son
    {
        /*
        ** Set the parent-death signal of the calling process to
        ** SIGHUP. This is the signal that the calling process will
        ** get when its parent dies.
        */
        prctl(PR_SET_PDEATHSIG, SIGHUP);
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(s);
    }
    return 0;
}