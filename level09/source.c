#include <stdio.h>


int secret_backdoor()
{
  char s[128]; // [rsp+0h] [rbp-80h] BYREF

  fgets(s, 0x80, stdin);
  return system(s);
}

int handle_msg()
{
  char v1[140]; // [rsp+0h] [rbp-C0h] BYREF
  int v2; // [rsp+8Ch] [rbp-34h]
  int v3; // [rsp+94h] [rbp-2Ch]
  int v4; // [rsp+9Ch] [rbp-24h]
  int v5; // [rsp+A4h] [rbp-1Ch]
  int v6; // [rsp+ACh] [rbp-14h]
  int v7; // [rsp+B4h] [rbp-Ch]

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 140;
  set_username((int)v1);
  set_msg((int)v1);
  return puts(">: Msg sent!");
}

char *set_msg(int a1)
{
  char s[1024]; // [rsp+10h] [rbp-400h] BYREF

  memset(s, 0, sizeof(s));
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(s, 1024, stdin);
  return strncpy((char *)a1, s, *(int *)(a1 + 180));
}

int set_username(int a1)
{
  char s[140]; // [rsp+10h] [rbp-90h] BYREF
  int i; // [rsp+9Ch] [rbp-4h]

  memset(s, 0, 128);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(s, 128, stdin);
  for ( i = 0; i <= 40 && s[i]; ++i )
    *(_BYTE *)(a1 + i + 140) = s[i];
  return printf(">: Welcome, %s", (const char *)(a1 + 140));
}

int main(int argc, const char **argv, const char **envp)
{
  puts(
    "--------------------------------------------\n"
    "|   ~Welcome to l33t-m$n ~    v1337        |\n"
    "--------------------------------------------");
  handle_msg();
  return (0);
}
