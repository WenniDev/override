#include <stdio.h>

void clear_stdin(void)
{
  char c;
  
  do {
    c = getchar();
    if (c == '\n') {
      return;
    }
  } while (c != -1);
  return;
}

unsigned int get_unum(void)
{
  unsigned int unsigned_number;
  
  unsigned_number = 0;
  fflush(stdout);
  scanf("%u",unsigned_number);
  clear_stdin();
  return unsigned_number;
}

int store_number(int offset)
{
  unsigned int number;
  unsigned int index;
  int return_value;
  
  printf(" Number: ");
  number = get_unum();
  printf(" Index: ");
  index = get_unum();
  if ((index % 3 == 0) || (number >> 0x18 == 0xb7))
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return_value = 1;
  }
  else {
    *(unsigned int *)(index * 4 + offset) = number;
    return_value = 0;
  }
  return return_value;
}

int read_number(int number)
{
  unsigned int index;
  
  printf(" Index: ");
  unsigned int index = get_unum();
  printf(" Number at data[%u] is %u\n", index, *(unsigned int *)(index * 4 + number));
  return 0;
}

// CONTINUE HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main(int argc, char **argv, char **envp)
{
  char cVar1;
  int iVar2; // probably a temporary value used for different purposes
  uint uVar3;
  int    *perhaps_memory_storage_pointer;   //pointer to int or unsigned int
  char *pcVar5;
  byte *pbVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char **local_1c8;
  
  undefined4 local_1bc [100];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  bVar10 = 0;
  char **arguments = argv;
  local_1c8 = envp;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  perhaps_memory_storage_pointer = local_1bc;


  for (int i = 100; i != 0; --i)
  {
    *perhaps_memory_storage_pointer = 0;
    ++perhaps_memory_storage_pointer;
  }
  for (; *arguments != '\0'; ++arguments)
  {
    uVar3 = -1;
    pcVar5 = *arguments;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != '\0');
    memset(*arguments,0,~uVar3 - 1);
  }
  for (; *local_1c8 != (char *)0x0; local_1c8 = local_1c8 + 1) {
    uVar3 = 0xffffffff;
    pcVar5 = *local_1c8;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != '\0');
    memset(*local_1c8,0,~uVar3 - 1);
  }
  puts(
      "----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
      );
  do {
    printf("Input command: ");
    local_2c = 1;
    fgets((char *)&local_28,0x14,stdin);
    uVar3 = 0xffffffff;
    perhaps_memory_storage_pointer = &local_28;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *(char *)perhaps_memory_storage_pointer;
      perhaps_memory_storage_pointer = (undefined4 *)((int)perhaps_memory_storage_pointer + (uint)bVar10 * -2 + 1);
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    bVar7 = uVar3 == 1;
    bVar9 = uVar3 == 2;
    *(undefined *)((int)&local_2c + uVar3 + 2) = 0;
    iVar2 = 5;
    perhaps_memory_storage_pointer = &local_28;
    pbVar6 = (byte *)"store";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *(byte *)perhaps_memory_storage_pointer < *pbVar6;
      bVar9 = *(byte *)perhaps_memory_storage_pointer == *pbVar6;
      perhaps_memory_storage_pointer = (undefined4 *)((int)perhaps_memory_storage_pointer + (uint)bVar10 * -2 + 1);
      pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    bVar8 = false;
    bVar7 = (!bVar7 && !bVar9) == bVar7;
    if (bVar7) {
      local_2c = store_number(local_1bc);
    }
    else {
      iVar2 = 4;
      perhaps_memory_storage_pointer = &local_28;
      pbVar6 = &DAT_08048d61;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *(byte *)perhaps_memory_storage_pointer < *pbVar6;
        bVar7 = *(byte *)perhaps_memory_storage_pointer == *pbVar6;
        perhaps_memory_storage_pointer = (undefined4 *)((int)perhaps_memory_storage_pointer + (uint)bVar10 * -2 + 1);
        pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
      } while (bVar7);
      bVar9 = false;
      bVar7 = (!bVar8 && !bVar7) == bVar8;
      if (bVar7) {
        local_2c = read_number(local_1bc);
      }
      else {
        iVar2 = 4;
        perhaps_memory_storage_pointer = &local_28;
        pbVar6 = &DAT_08048d66;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *(byte *)perhaps_memory_storage_pointer < *pbVar6;
          bVar7 = *(byte *)perhaps_memory_storage_pointer == *pbVar6;
          perhaps_memory_storage_pointer = (undefined4 *)((int)perhaps_memory_storage_pointer + (uint)bVar10 * -2 + 1);
          pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
        } while (bVar7);
        if ((!bVar9 && !bVar7) == bVar9) {
          if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
            return 0;
          }
                    // WARNING: Subroutine does not return
          __stack_chk_fail();
        }
      }
    }
    if (local_2c == 0) {
      printf(" Completed %s command successfully\n",&local_28);
    }
    else {
      printf(" Failed to do %s command\n",&local_28);
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
  } while( true );
}


