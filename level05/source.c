#include <stdio.h>
int main(int argc, const char **argv, const char **envp)
{
  char s[100]; // [esp+28h] [ebp-70h] BYREF
  unsigned int i; // [esp+8Ch] [ebp-Ch]

  i = 0;
  fgets(s, 100, stdin);
  for ( i = 0; i < strlen(s); ++i )
  {
    if ( s[i] > 64 && s[i] <= 90 ) // upercase
      s[i] ^= 0x20u; // + 32 => lowercase
      /*
        64: 1000000     90: 1011010
        32: 0100000    
      */
  }
  printf(s);
  exit(0);
}