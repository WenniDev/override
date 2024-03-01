#include <stdio.h>

char a_user_name[100];

int verify_user_name(void) {
  puts("verifying username....\n");
  return (memcmp(a_user_name, "dat_wil", 7) != 0);
}

int verify_user_pass(const void *a1) {
  return (memcmp(a1, "admin", 5) != 0);
}

int main(void) {
  char s[64];
  int test;

  memset(s, 0, sizeof(s));
  test = 0;

  puts("********* ADMIN LOGIN PROMPT *********");
  
  printf("Enter Username: ");
  fgets(a_user_name, 256, stdin);
  test = verify_user_name();
  
  if (test != 0) {
    puts("nope, incorrect username...\n");
  } else {
    puts("Enter Password: ");
    fgets(s, 100, stdin);
    test = verify_user_pass(s);
    puts("nope, incorrect password...\n");
  }
  return (1);
}