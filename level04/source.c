#include <unistd.h>
#include <sys/prctl.h>

// Function declarations

int clear_stdin();
int get_unum();
void prog_timeout(int a1);
unsigned int enable_timeout_cons();
void term_proc();

//----- (08048634) --------------------------------------------------------
int clear_stdin()
{
    char result;

    do
        result = getchar();
    while (result != '\n' && result != 255);
    return result;
}

//----- (08048657) --------------------------------------------------------
int get_unum()
{
    int v1[3]; // [esp+1Ch] [ebp-Ch] BYREF

    v1[0] = 0;
    fflush(stdout);
    scanf("%u", v1);
    clear_stdin();
    return v1[0];
}
// 8048560: using guessed type int __cdecl __isoc99_scanf(_DWORD, _DWORD);
// 8048657: using guessed type int var_C[3];

//----- (0804868F) --------------------------------------------------------
void prog_timeout(int a1)
{
    sys_exit(1);
}

//----- (080486A0) --------------------------------------------------------
unsigned int enable_timeout_cons()
{
    signal(14, (__sighandler_t)prog_timeout);
    return alarm(0x3Cu);
}

//----- (080486C8) --------------------------------------------------------
int main(int argc, const char **argv, const char **envp)
{
    int stat_loc; // [esp+1Ch] [ebp-9Ch] BYREF
    char s[128];  // [esp+20h] [ebp-98h] BYREF
    int v6;       // [esp+A0h] [ebp-18h]
    int v7;       // [esp+A4h] [ebp-14h]
    int v8;       // [esp+A8h] [ebp-10h]
    pid_t v9;     // [esp+ACh] [ebp-Ch]

    v9 = fork();
    memset(s, 0, sizeof(s));
    v8 = 0;
    stat_loc = 0;
    if (v9) // father
    {
        while (v8 != 11)
        {
            wait(&stat_loc);
            v6 = stat_loc;
            if ((stat_loc & 0x7F) == 0 || (v7 = stat_loc, (char)((stat_loc & 0x7F) + 1) >> 1 > 0))
            {
                puts("child is exiting...");
                return 0;
            }
            /*
            ** PTRACE_PEEKUSER
            ** Read a word at offset addr in the tracee's USER area,
            ** which holds the registers and other information about the
            ** process (see <sys/user.h>).  The word is returned as the
            ** result of the ptrace() call.  Typically, the offset must
            ** be word-aligned, though this might vary by architecture.
            ** See NOTES.  (data is ignored; but see NOTES.)
            */

            v8 = ptrace(PTRACE_PEEKUSER, v9, 44, 0);
        }

        puts("no exec() for you");
        kill(v9, 9);
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