#include <stdio.h>

int decrypt(int offset)
{
  int result;
  unsigned int i;
  unsigned int v3;
  char v4[29];

  *(char *)&v4[17] = __readgsdword(20);
  strcpy(v4, "Q}|u`sfg~sf{}|a3");
  v3 = strlen(v4);
  for (i = 0; i < v3; ++i)
    v4[i] ^= offset;
  if (strcmp(v4, "Congratulations!") == 0)
    result = system("/bin/sh");
  else
    result = puts("\nInvalid Password");
  return (result);
}

int test(int a1, int a2)
{
  int result;
  int rval;

	switch (a2 - a1)
  	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
			result = decrypt(a2 - a1);
			break;
		default:
			rval = rand();
			result = decrypt(rval);
			break;
 	}
  return (result);
}

int main(void)
{
  unsigned int rval;
  int savedregs;

  rval = time(0);
  srand(rval);
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");
  scanf("%d", &savedregs);
  test(savedregs, 322424845);
  return (0);
}