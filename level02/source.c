#include <stdio.h>

int main(void)
{
  char password[96];
  char file_pass[48];
  char username[96];
  int pwd_len;
  FILE *stream;

  memset(username, 0, sizeof(username));
  memset(file_pass, 0, 41);
  memset(password, 0, sizeof(password));
  stream = 0;
  pwd_len = 0;
  stream = fopen("/home/users/level03/.pass", "r");

  if (!stream)
  {
    fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
    exit(1);
  }

  pwd_len = fread(file_pass, 1, 41, stream);
  file_pass[strcspn(file_pass, "\n")] = 0;

  if (pwd_len != 41)
  {
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    exit(1);
  }
  fclose(stream);

  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");

  fgets(username, 100, stdin);
  username[strcspn(username, "\n")] = 0;
  printf("--[ Password: ");
  fgets(password, 100, stdin);
  password[strcspn(password, "\n")] = 0;

  puts("*****************************************");

  if (strncmp(file_pass, password, 41))
  {
    printf(username);
    puts(" does not have access!");
    exit(1);
  }

  printf("Greetings, %s!\n", username);
  system("/bin/sh");
  return 0;
}