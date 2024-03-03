

//----- (08048748) --------------------------------------------------------
_BOOL4 auth(char *login, int serial)
{
    int i;         // [esp+14h] [ebp-14h]
    int computed;  // [esp+18h] [ebp-10h]
    int login_len; // [esp+1Ch] [ebp-Ch]

    login[strcspn(login, "\n")] = 0;
    login_len = strnlen(login, 32);
    if (login_len <= 5)
        return 1;
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        puts("\x1B[32m.---------------------------.");
        puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
        puts("\x1B[32m'---------------------------'");
        return 1;
    }
    else
    {
        computed = (login[3] ^ 0x1337) + 6221293; // 0x1335 = 4919
        for (i = 0; i < login_len; ++i)
        {
            if (login[i] <= 31)
                return 1;
            computed += (computed ^ (unsigned int)login[i]) % 0x539; // 0x539 = 1337
        }
        return serial != computed;
    }
}

int main(int argc, const char **argv, const char **envp)
{
    int serial;      // [esp+2Ch] [ebp-24h] BYREF
    char login[28];  // [esp+30h] [ebp-20h] BYREF
    unsigned int v6; // [esp+4Ch] [ebp-4h]  ????????????????????????

    v6 = __readgsdword(0x14u);
    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(login, 32, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");
    scanf("%u", &serial);
    if (auth(login, serial))
        return 1;
    puts("Authenticated!");
    system("/bin/sh");
    return 0;
}
